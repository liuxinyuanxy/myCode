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
#define _ 300005
using namespace std;
il int rd()
{
	rt s = 0, p = 0; rc ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return p ? -s : s;
}
bool vis[_];
int qu[_], l, r;
int head2[_], in[_], dis[_];
int head[_], nxt[_], to[_];
int dfn[_], low[_], col[_], val[_], from[_];
int sta[_], top;
int tot, cnt, n;
void topo()
{
	rt ans = 0, now;
	for (rt i = 1; i <= n; ++i)
		if (col[i] == i && !in[i])
			qu[r++] = i,
			dis[i] = val[i],
			ans = max(ans, dis[i]);
	if (r > _ - 1)
		r = 0;
	while (l != r)
	{
		now = qu[l++];
		if (l > _ - 1)
			l = 0;
		for (rt i = head2[now]; i; i = nxt[i])
		{
			rt v = to[i];
			if (col[v] == v)
			{
				dis[v] = max(dis[v], dis[now] + val[v]);
				ans = max(ans, dis[v]);
				--in[v];
				if (!in[v])
				{
					qu[r++] = v;
					if (r > _ - 1)
						r = 0;
				}
			}
		}
	}
	printf("%d", ans);
}
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	from[tot] = u;
}
il void add2(rt u, rt v)
{
	nxt[++tot] = head2[u];
	head2[u] = tot;
	to[tot] = v;
	++in[v];
}
void tarjan(rt u)
{
	sta[top++] = u;
	vis[u] = 1;
	dfn[u] = low[u] = ++cnt;
	for (rt i = head[u]; i; i = nxt[i])
	{
		rt v = to[i];
		if (!dfn[v])
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else
			if (vis[v])
				low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		rt y;
		while (y = sta[--top], y != u)
			col[y] = u,
			val[u] += val[y],
			vis[y] = 0;
		col[u] = u;
		vis[u] = 0;	
	}
}
int main()
{
	int m, u, v;
	n = rd(), m = rd();
	for (rt i = 1; i <= n; ++i)
		val[i] = rd();
	for (rt i = 1; i <= m; ++i)
	{
		u = rd(), v = rd();
		add(u, v);
	}
	for (rt i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	tot = 0;
	for (rt i = 1; i <= m; ++i)
		if (col[from[i]] != col[to[i]])
			add2(col[from[i]], col[to[i]]);
	topo();
	return 0;
}
