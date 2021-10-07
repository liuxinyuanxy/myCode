#include <cstdio>
#include <iostream>
#define MAX 1000005

using namespace std;

int nxt[MAX], node[MAX], fst[MAX], tot;
int fa[MAX][21];
int d[MAX];

inline void path(int u, int v)
{
	node[++tot] = v;
	nxt[tot] = fst[u];
	fst[u] = tot;
}

void dfs(int u)
{
	register int v;
	for (register int i = 1; i <= 19; ++i)
	{
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for (register int i = fst[u]; i; i = nxt[i])
	{
		v = node[i];
		if (d[v]) continue;
		fa[v][0] = u;
		d[v] = d[u] + 1;
		dfs(v);
	}
}

inline void ans(int a, int b)
{
	if (a == b)
	{
		printf("%d\n", a);
		return;
	}
	if (d[a] < d[b])
		swap(a, b);
	register int k = d[a] - d[b];
	register int t = 0;
	for (; k; k >>= 1, ++t)
		if (k & 1)
			a = fa[a][t];
	if (a == b)
	{
		printf("%d\n", a);
		return;
	}
	for (register int i = 19; i >= 0; --i)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i],
			b = fa[b][i];
	printf("%d\n", fa[a][0]);
}

inline int r()
{
	register char ch;
	register int a;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
	{
		a = a * 10 + ch - '0';
		ch = getchar();
	}
	return a;
}

int main()
{
	int n, m, s, a, b;
	scanf("%d%d%d", &n, &m, &s);
	for (register int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		path(a, b);
		path(b, a);
	}
	d[s] = 1;
	dfs(s);
	for (register int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		ans(a, b);
	}
	return 0;
}
