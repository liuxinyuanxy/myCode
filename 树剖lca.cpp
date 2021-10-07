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
#define _ 100005 
using namespace std;
int tot;
int head[_], nxt[_], to[_];
int fa[_], sze[_], top[_], son[_], dep[_];
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
void dfs(rt u)
{
	sze[u] = 1; 
	dep[u] = dep[fa[u]] + 1;
	for (rt i = head[u]; i; i = nxt[i])
	{
		rt v = to[i];
		if (v == fa[u])
			continue;
		fa[v] = u;
		dfs(v);
		sze[u] += sze[v];
		if (sze[v] > sze[son[u]])
			son[u] = v;
	}
}
void dfs2(rt u, rt t)
{
	top[u] = t;
	if (son[u])
		dfs2(son[u], t);
	for (rt i = head[u]; i; i = nxt[i])
	{
		rt v = to[i];
		if (v == fa[u] || v == son[u])
			continue;
		dfs2(v, v);
	}
}
void query(rt x, rt y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]])
			y = fa[top[y]];
		else
			x = fa[top[x]];
	}
	printf("%d\n", dep[x] < dep[y] ? x : y);
}
int main()
{
	int n, m, s, x, y;
	scanf ("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; ++i)
	{
		scanf ("%d%d", &x, &y);
		add(x, y);
		add(y, x);	
	} 
	dfs(s);
	dfs2(s, s);
	for (int i = 1; i <= m; ++i)
	{
		scanf ("%d%d", &x, &y);
		query(x, y);
	}
	return 0;
}


