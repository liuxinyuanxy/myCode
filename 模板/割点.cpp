//¸îµã 
#include <iostream>
#include <cstdio>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y) scanf ("%lld%lld", &x, &y)
#define sfl3(x, y, z) scanf ("%lld%lld%lld", &x, &y, &z)
#define pfl(x) printf ("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define pfl3(x, y, z) printf("%lld%lld%lld", x, y, z)
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define _ 300005
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
int head[_], to[_], nxt[_];
int dfn[_], low[_];
int del[_];
int cnt, ans= 0;
int tot;
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
void tarjan(rt x, rt fa)
{
	rt y, child = 0;
	dfn[x] = low[x] = ++cnt;
	for (rt i = head[x]; i; i = nxt[i])
	{
		y = to[i];
		if (!dfn[y])
		{
			tarjan(y, 1);
			++child;
			low[x] = min(low[x], low[y]);
			if ((fa == -1 && child > 1) || (fa != -1 && low[y] == dfn[x]))
			{
				ans += (int)(!del[x]);
				del[x] = 1;
			}
		}
		else
			low[x] = min(low[x], dfn[y]);
	}
}
int main()
{
	int n = rd(), m = rd(), u, v;
	rep (i, 1, m)
	{
		u = rd(), v = rd(),
		add(u, v),
		add(v, u);
	}
	rep (i, 1, n)
		if (!dfn[i])
			tarjan(i, -1);
	printf("%d\n", ans);
	rep (i, 1, n)
		if (del[i])
			printf("%d ", i);
	return 0;
}

