#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y)	scanf ("%lld%lld", &x, &y)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define MAXN 300005
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int head[MAXN], nxt[MAXN], to[MAXN], tot;
int cnt[MAXN], ans[MAXN];
int a[MAXN];
int fa[MAXN][20], deep[MAXN];
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
il void init(rt u, rt f)
{
	rt v;
	fa[u][0] = f;
	deep[u] = deep[f] + 1;
	for (rt i = 1; (1 << i) <= deep[u]; ++i)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == f)
			continue;
		init(v, u);
	}
}
il int lca(rt a, rt b)
{
	if (deep[a] < deep[b])
		swap(a, b);
	rt k = deep[a] - deep[b];
	for (rt i = 0; k; k >>= 1, ++i)
		if (k & 1)
			a = fa[a][i];
	if (a == b)
		return a;
	for (rt i = 19; i >= 0; --i)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i],
			b = fa[b][i];
	return fa[a][0];
}
il void dfs(rt u, rt f)
{
	rt v;
	ans[u] = cnt[u];
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == f)
			continue;
		dfs(v, u);
		ans[u] += ans[v];
	}
}
int main()
{
//	deep[0] = -1;
	rt n, LCA, x, y;
	sf(n);
	rep (i, 1, n)
		sf(a[i]);
	rep (i, 1, n - 1)
		sf2(x, y),
		add(x, y),
		add(y, x);
	init(1, 0);
	rep (i, 2, n)
	{
		++cnt[a[i - 1]];
		++cnt[a[i]];
		--cnt[LCA = lca(a[i], a[i - 1])];
		--cnt[fa[LCA][0]];
	}
	dfs(1, 0);
	rep (i, 2, n)
		--ans[a[i]];
	rep (i, 1, n)
		pf(ans[i]),
		putchar('\n');
	return 0;
}

