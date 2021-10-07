#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 200000
using namespace std;
int head[_], nxt[_], to[_], dfn[_];
int tot;
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
void dfs(rt u, rt fa)
{
	dfn[u] = fa;
	for (rt i = head[u]; i; i = nxt[i])
	{
		rt v = to[i];
		if (!dfn[v])
			dfs(v, fa);
	}
}
int main()
{
	int n, m, u, v;
	scanf ("%d%d", &n, &m);
	for (rt i = 1; i <= m; ++i)
	{
		scanf ("%d%d", &u, &v);
		add(v, u);
	}
	for (rt i = n; i >= 1; --i)
		if (!dfn[i])
			dfs(i, i);
	for (rt i = 1; i <= n; ++i)
		printf("%d ", dfn[i]);
	return 0;
}


