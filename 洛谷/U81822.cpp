#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
// #define int long long
using namespace std;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[1 << 21], *p1 = buf, *p2 = buf;

struct io
{
	char obuf[200 << 20], *t;
	int a[40];
	io() : t(obuf)
	{
	}
	~io()
	{
		fwrite(obuf, 1, t - obuf, stdout);
	}
	template <class T>
	inline void read(T &s)
	{
		s = 0;
		bool p = 0;
		char ch;
		while (ch = gc(), p |= ch == '-', !isdigit(ch))
			;
		while (s = s * 10 + ch - '0', isdigit(ch = gc()))
			;
		s *= (p ? -1 : 1);
	}
	template <class T>
	inline void print(T u)
	{
		static int *q = a;
		if (u < 0)
			*t++ = '-', u = -u;
		if (!u)
			*t++ = 48;
		else
		{
			while (u)
				*q++ = u % 10 + 48, u /= 10;
			while (q != a)
				*t++ = *--q;
		}
		*t++ = '\n';
	}
} ip;
#define print ip.print
#define read ip.read
const int MAXN = 3000005;
struct node
{
	int son[2];
	int sze, cnt;
	int val, fa;
} st[MAXN];
int fre[MAXN], top;
int cnt;
struct Splay
{
	int rt;
	il int new_node()
	{
		return top ? fre[top--] : ++cnt;
	}
	il void push_up(int x)
	{
		st[x].sze = st[st[x].son[0]].sze + st[st[x].son[1]].sze + st[x].cnt;
	}
	void rotate(int x, int &k)
	{
		int y, z;
		y = st[x].fa;
		z = st[y].fa;
		int l, r;
		l = st[y].son[1] == x;
		r = l ^ 1;
		if (k == y)
			k = x;
		else
			st[z].son[int(st[z].son[1] == y)] = x;
		st[x].fa = z;
		st[y].fa = x;
		st[st[x].son[r]].fa = y;
		st[y].son[l] = st[x].son[r];
		st[x].son[r] = y;
		push_up(y);
		push_up(x);
	}
	void splay(int x, int &k)
	{
		int y, z;
		while (x != k)
		{
			y = st[x].fa;
			z = st[y].fa;
			if (y != k)
			{
				if ((st[z].son[0] == y) ^ (st[y].son[0] == x))
					rotate(x, k);
				else
					rotate(y, k);
			}
			rotate(x, k);
		}
	}
	void insert(int &o, int k, int f)
	{
		if (!o)
			o = new_node(),
			st[o].cnt = 1,
			st[o].sze = 1,
			st[o].val = k,
			st[o].fa = f,
			st[o].son[0] = st[o].son[1] = 0,
			splay(o, rt);
		else if (k == st[o].val)
			++st[o].cnt,
				splay(o, rt);
		else if (k < st[o].val)
			insert(st[o].son[0], k, o);
		else
			insert(st[o].son[1], k, o);
	}
	void find(int x)
	{
		int o = rt;
		while (st[o].val != x)
			o = st[o].son[st[o].val < x];
		splay(o, rt);
	}
	int find_lower(int x)
	{
		int o = rt, ans;
		while (o)
			if (st[o].val < x)
				ans = o, o = st[o].son[1];
			else
				o = st[o].son[0];
		return ans;
	}
	int find_upper(int x)
	{
		int o = rt, ans;
		while (o)
			if (st[o].val > x)
				ans = o, o = st[o].son[0];
			else
				o = st[o].son[1];
		return ans;
	}
	int query(int l, int r)
	{
		splay(find_lower(l), rt);
		splay(find_upper(r), st[rt].son[1]);
		return st[st[st[rt].son[1]].son[0]].sze;
	}
	void merge(int l, int r)
	{
		if (!l || !r)
		{
			rt = l ^ r;
			return;
		}
		int o = l;
		while (st[o].son[1])
			o = st[o].son[1];
		splay(o, l);
		rt = l;
		st[rt].son[1] = r;
		st[r].fa = l;
		push_up(rt);
	}
	void del(int x)
	{
		find(x);
		if (st[rt].cnt > 1)
		{
			--st[rt].cnt;
			--st[rt].sze;
			return;
		}
		fre[++top] = rt;
		st[st[rt].son[0]].fa = st[st[rt].son[1]].fa = 0;
		merge(st[rt].son[0], st[rt].son[1]);
	}
} node[MAXN];
int a[MAXN];
signed main()
{
	int n, q;
	read(n), read(q);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
		if (!node[a[i]].rt)
		{
			node[a[i]].insert(node[a[i]].rt, -1, 0);
			node[a[i]].insert(node[a[i]].rt, MAXN + 1, 0);
		}
		node[a[i]].insert(node[a[i]].rt, i, 0);
	}
	node[0].insert(node[0].rt, -1, 0);
	node[0].insert(node[0].rt, MAXN + 1, 0);
	node[0].insert(node[0].rt, 0, 0);
	for (int i = 1; i <= q; ++i)
	{
		int opt, l, r, b;
		read(opt);
		read(l), read(r);
		if (opt == 0)
		{
			node[a[l]].del(l);
			node[a[r]].del(r);
			swap(a[l], a[r]);
			node[a[l]].insert(node[a[l]].rt, l, 0);
			node[a[r]].insert(node[a[r]].rt, r, 0);
		}
		else
		{
			read(b);
			if (l > r)
				swap(l, r);
			print(node[b].query(l, r));
		}
	}
}