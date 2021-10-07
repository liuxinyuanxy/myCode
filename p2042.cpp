#include <iostream>
#include <cstdio>
#include <cctype>
#define il inline
#define re register
#define gc getchar
#define mid(x, y) (((x) + (y)) >> 1)
using namespace std;
const int MAXN = 550000;
struct node
{
	int son[2];
	int val, tag1, tag2;    // tag1 : 区间染色
	int sze;
	int fa;
	int maxl, maxr, maxsum, sum;
}st[MAXN];
int rt;
int cnt = 0;
int a[MAXN];
int fre[MAXN], top;
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
		;
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
il int new_node()
{
	return top ? fre[top--] : ++cnt;
}
il void updata(int o)
{
	st[o].sze = st[st[o].son[0]].sze + st[st[o].son[1]].sze + 1;
	st[o].sum = st[st[o].son[0]].sum + st[st[o].son[1]].sum + st[o].val;
	int l = st[o].son[0], r = st[o].son[1];
	st[o].maxsum = max(max(st[l].maxsum, st[r].maxsum), st[l].maxr + st[r].maxl + st[o].val);
	st[o].maxl = max(st[l].maxl, st[l].sum + st[o].val + st[r].maxl);
	st[o].maxr = max(st[r].maxr, st[l].maxr + st[o].val + st[r].sum);
}
il void push_down(int o)
{
	int &l = st[o].son[0], &r = st[o].son[1];
	if (st[o].tag1 != -1001)
	{
		st[o].tag2 = st[l].tag2 = st[r].tag2 = 0;
		int x = st[o].tag1;
		if (l)
			st[l].tag1 = st[l].val = x;
		if (r)
			st[r].tag1 = st[r].val = x;
		st[l].sum = x * st[l].sze;
		st[r].sum = x * st[r].sze;
		if (x > 0)
			st[l].maxl = st[l].maxr = st[l].maxsum = st[l].sum,
			st[r].maxl = st[r].maxr = st[r].maxsum = st[r].sum;
		else
			st[l].maxl = st[l].maxr = st[r].maxl = st[r].maxr = 0,
			st[l].maxsum = st[l].val,
			st[r].maxsum = st[r].val;
		st[o].tag1 = -1001;
	}
	if (st[o].tag2)
	{
		if (l)
			st[l].tag2 ^= 1;
		if (r)
			st[r].tag2 ^= 1;
		st[o].tag2 ^= 1;
		swap(st[l].maxl, st[l].maxr);
		swap(st[r].maxr, st[r].maxl);
		swap(st[l].son[0], st[l].son[1]);
		swap(st[r].son[0], st[r].son[1]);
	}
}
void build(int& o, int l, int r, int f)
{
	int m = mid(l, r);
	o = new_node();
	st[o].fa = f;
	st[o].sze = 1;
	st[o].son[0] = st[o].son[1] = st[o].tag2 = 0;
	st[o].tag1 = -1001;
	st[o].val = st[o].sum = a[m];
	st[o].maxl = st[o].maxr = max(a[m], 0);
	st[o].maxsum = a[m];
	if (l == r)
		return;
	if(l <= m - 1)
		build(st[o].son[0], l, m - 1, o);
	build(st[o].son[1], m + 1, r, o);
	updata(o);
}
int find(int x)
{
	int ans = 0, o = rt;
	while (true)
	{
		push_down(o);
		if (st[st[o].son[0]].sze + 1 + ans == x)
			return o;
		if (st[st[o].son[0]].sze + 1 + ans < x)
			ans += st[st[o].son[0]].sze + 1,
			o = st[o].son[1];
		else
			o = st[o].son[0];
	}
}
void rotate(int x, int& k)
{
	int y = st[x].fa, z = st[y].fa;
	int l = st[y].son[1] == x, r = l ^ 1;
	if (y == k)
		k = x;
	else
	{
		st[z].son[st[z].son[1] == y] = x;
	}
	st[x].fa = z;
	st[y].fa = x;
	st[st[x].son[r]].fa = y;
	st[y].son[l] = st[x].son[r];
	st[x].son[r] = y;
	updata(y);
	updata(x);
}
void splay(int x, int& k)
{
	int y, z;
	while (x != k)
	{
		y = st[x].fa;
		z = st[y].fa;
		if (y != k)
		{
			if (st[z].son[1] == y ^ st[y].son[1] == x)
				rotate(x, k);
			else
				rotate(y, k);
		}
		rotate(x, k);
	}
}
void insert(int pos, int tot)
{
	int l = find(pos + 1), r = find(pos + 2);
	splay(l, rt);
	splay(r, st[l].son[1]);
	for (int i = 1; i <= tot; ++i)
		rd(a[i]);
	build(st[st[l].son[1]].son[0], 1, tot, st[l].son[1]);
	updata(st[l].son[1]);
	updata(rt);
}
void clear(int& o)
{
	if (st[o].son[0])
		clear(st[o].son[0]);
	if (st[o].son[1])
		clear(st[o].son[1]);
	fre[++top] = o;
	o = 0;
}
void del(int pos, int tot)
{
	int l = find(pos), r = find(pos + tot + 1);
	splay(l, rt);
	splay(r, st[l].son[1]);
	clear(st[st[l].son[1]].son[0]);
	updata(st[l].son[1]);
	updata(rt);
}
void modify(int pos, int tot, int c)
{
	int l = find(pos), r = find(pos + tot + 1);
	splay(l, rt);
	splay(r, st[l].son[1]);
	int o = st[st[l].son[1]].son[0];
	st[o].tag1 = st[o].val = c;
	st[o].sum = c *  1ll *  st[o].sze;
	st[o].maxsum = (c > 0) ? c *  st[o].sze : c;
	st[o].maxl = st[o].maxr = (c > 0) ? c * st[o].sze : 0;
	updata(st[l].son[1]);
	updata(rt);
}
void reverse(int pos, int tot)
{
	int l = find(pos), r = find(pos + tot + 1);
	splay(l, rt);
	splay(r, st[l].son[1]);
	int o = st[st[l].son[1]].son[0];
	st[o].tag2 ^= 1;
	swap(st[o].maxl, st[o].maxr);
	swap(st[o].son[0], st[o].son[1]);
	updata(st[l].son[1]);
	updata(rt);
}
void get_sum(int pos, int tot)
{
	int l = find(pos), r = find(pos + tot + 1);
	splay(l, rt);
	splay(r, st[l].son[1]);
	printf("%d\n", st[st[st[l].son[1]].son[0]].sum);
}
void get_maxsum()
{
	printf("%d\n", st[rt].maxsum);
}
void finish()
{
	char ch;
	while (ch = gc(), !isspace(ch))
		;
}
int get_opt()
{
	char ch;
	while (ch = gc(), !isalpha(ch))
		;
	if (ch == 'I')
	{
		finish();
		return 1;
	}
	if (ch == 'D')
	{
		finish();
		return 2;
	}
	if (ch == 'M')
	{
		ch = gc();
		ch = gc();
		if (ch == 'K')
		{
			finish();
			return 3;
		}
		else
		{
			finish();
			return 6;
		}
	}
	if (ch == 'R')
	{
		finish();
		return 4;
	}
	finish();
	return 5;
}
const int INF = 0x3f3f3f3f;
int main()
{
	int n, m;
	rd(n, m);
	st[0].maxsum = st[0].val = -INF;
	a[1] = a[n + 2] = -INF;
	for (int i = 2; i <= n + 1; ++i)
	{
		rd(a[i]);
	}
	build(rt, 1, n + 2, 0);
	int pos, tot;
	for (int i = 1; i <= m; ++i)
	{
		int opt = get_opt();
		if (opt == 6)
		{
			get_maxsum();
		}
		else
		{
			rd(pos, tot);
			if (opt == 1)
			{
				insert(pos, tot);
			}
			if (opt == 2)
			{
				del(pos, tot);
			}
			if (opt == 3)
			{
				int c;
				rd(c);
				modify(pos, tot, c);
			}
			if (opt == 4)
			{
				reverse(pos, tot);
			}
			if (opt == 5)
			{
				get_sum(pos, tot);
			}
		}
	}
	return 0;
}