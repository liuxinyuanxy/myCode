#include <iostream>
#include <cstdio>
#define MAX 400000
using namespace std;
int fa[MAX], son[MAX][2], sum[MAX], val[MAX];
int a[MAX], u[MAX];
int tot, rt;
int fwh(int x)
{
	return son[fa[x]][1] == x; 
}
inline void pushup(int x)
{
	sum[x] = sum[son[x][0]] + sum[son[x][1]] + 1;
}
inline void rotate(int x)
{
	int f = fa[x], gf = fa[f], wh = fwh(x);
	fa[x] = gf;
	son[gf][fwh(f)] = x;
	fa[son[x][wh ^ 1]] = f;
	son[f][wh] = son[x][wh ^ 1];
	fa[f] = x;
	son[x][wh ^ 1] = f;
	pushup(f);
	pushup(x);
}
inline void splay(int x)
{
	if (x == rt)
		return;
	while (fa[x] != 0)
	{
		if (fa[fa[x]] != 0)
		{
			if (fwh(x) == fwh(fa[x]))
				rotate(fa[x]);
			else
				rotate(x);
		}
		rotate(x);
	}
	rt = x;
}
int findkth(int x)
{
	int p = rt;
	while (true)
	{
		if (sum[son[p][0]] + 1 == x)
		{
			return val[p];
		}
		if (sum[son[p][0]] + 1 < x)
		{
			x -= sum[son[p][0]] + 1;
			p = son[p][1];
		}
		else
			p = son[p][0];
	}
}
inline void insert(int x)
{
	if (!rt)
	{
		rt = ++tot;
		sum[rt] = 1;
		val[rt] = x;
		return;
	}
	int p = rt, last;
	while (p)
	{
		++sum[p];
		last = p;
		p = son[p][x > val[p]];
	}
	son[last][x > val[last]] = ++tot;
	sum[tot] = 1;
	val[tot] = x;
	fa[tot] = last;
	pushup(last);
	splay(tot);
}
int main()
{
	int ppp = 1500000000;
	cout << ppp;
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &a[i]);	
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &u[i]);
	}
	int j = 1;
	int x = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (j > n)
			break;
		insert(a[i]);
		while (u[j] == i)
			++j,
			printf("%d\n", findkth(++x));
	}
	return 0;
}
