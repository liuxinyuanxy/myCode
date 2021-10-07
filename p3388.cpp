#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define sf(x) scanf ("%d", &x)
#define pfl(x) printf("%lld", x)
#define sfl(x) scanf ("%lld", &x)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define mid(x, y) ((x) + (y) >> 1)
#define MAX 500000
using namespace std;
int head[MAX], nxt[MAX], to[MAX], dfn[MAX], low[MAX];
int tot;
int cnt;
int ans, del[MAX];
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
void tarjan(rt x, rt fa)
{
	rt child = 0;
	dfn[x] = low[x] = ++cnt;
	for (rt i = head[x]; i; i = nxt[i])
	{
		if (!dfn[to[i]])
		{
			tarjan(to[i], 1);
			low[x] = min(low[x], low[to[i]]);
			++child;
			if ((fa == -1 && child > 1) || (fa != -1 && low[to[i]] == dfn[x]))
			{
				ans += (int)(!del[x]);
				del[x] = 1;
			}
		}
		else
			low[x] = min(low[x], dfn[to[i]]);
	}
}
int main()
{
	rt n, m, u, v;
	sf(n), sf(m);
	for (rt i = 1; i <= m; ++i)
	{
		sf(u), sf(v);
		add(u, v);
		add(v, u);
	}
	for (rt i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i, -1);
	pf(ans);
	putchar('\n');
	for (rt i = 1; i <= n; ++i)
		if (del[i])
			pf(i),
			putchar(' ');
	return 0;
}

