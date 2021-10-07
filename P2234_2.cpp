#include <cstdio>
#include <iostream>
#define gc getchar
#define re register
using namespace std;
const int MAX = 100000;
int cnt, rt;
int ansp, ansn;
struct node
{
	int son[2];
	int val, fa;
}st[MAX];
void rotate(int x, int& k)
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
}
void splay(int x, int& k)
{
	int y, z;
	while (x != k)
	{
		y = st[x].fa;
		z = st[x].fa;
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
void insert(int& o, int k, int f)
{
	if (!o)
		o = ++cnt,
		st[o].val = k,
		st[o].fa = f,
		splay(o, rt);
	else
		if (k < st[o].val)
			insert(st[o].son[0], k, o);
		else
			insert(st[o].son[1], k, o);
}
void ask_pre(int k, int o)
{
	if (!o)
		return;
	if (st[o].val <= k)
		ansp = st[o].val,
		ask_pre(k, st[o].son[1]);
	else
		ask_pre(k, st[o].son[0]);
}
void ask_nxt(int k, int o)
{
	if (!o)
		return;
	if (st[o].val >= k)
		ansn = st[o].val,
		ask_nxt(k, st[o].son[0]);
	else
		ask_nxt(k, st[o].son[1]);
}
void rd(int& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
int a[1000000];
int main()
{
	int n, ans = 0;
	rd(n);
	for (int i = 1; i <= n; ++i)
	{
		rd(a[i]);
		ansn = 0x3fffffff;
		ansp = -0x3fffffff;
		ask_pre(a[i], rt);
		ask_nxt(a[i], rt);
		if (i == 1)
			ans = a[i];
		else
			ans += min(ansn - a[i], a[i] - ansp);
		insert(rt, a[i], 0);
	}
	cout << ans << endl;
	return 0;
}