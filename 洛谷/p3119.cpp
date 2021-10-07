#include <cstdio>
#include <iostream>
using namespace std;
const int MAXM = 1000000;
const int MAXN = 200005;
int cnt = 0;
int head[MAXN], from[MAXN], nxt[MAXM], to[MAXM], val[MAXN];
int head2[MAXN], head3[MAXN];
int tot;
int clo[MAXN], vis[MAXN], dfn[MAXN], low[MAXN];
int sta[MAXN], top;
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	from[cnt] = u;
	to[cnt] = v;
}
void ins2(int u, int v)
{
	nxt[++cnt] = head2[u];
	head2[u] = cnt;
	from[cnt] = u;
	to[cnt] = v;
}
void ins3(int u, int v)
{
	nxt[++cnt] = head3[u];
	head3[u] = cnt;
	from[cnt] = u;
	to[cnt] = v;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	vis[u] = 1;
	sta[++top] = u;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	if (low[u] == dfn[u])
	{
		val[u] = 1;
		int y;
		while ((y = sta[top--]) != u)
			vis[y] = 0, clo[y] = u, ++val[u];
		clo[u] = u, vis[u] = 0;
	}
}
int qu[MAXM + 2], l, r;
int dis2[MAXN], dis3[MAXN];
void SPFA()
{
	dis2[clo[1]] = val[clo[1]];
	qu[r++] = clo[1];
	vis[clo[1]] = 1;
	while (l != r)
	{
		int u = qu[l++];
		if (l > MAXM)
			l = 0;
		for (int i = head2[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis2[v] < dis2[u] + val[v])
			{
				dis2[v] = dis2[u] + val[v];
				if (!vis[v])
				{
					vis[v] = 1;
					qu[r++] = v;
					if (r > MAXM)
						r = 0;
				}
			}
		vis[u] = 0;
	}
}
void SPFA2()
{
	dis3[clo[1]] = val[clo[1]];
	qu[r++] = clo[1];
	vis[clo[1]] = 1;
	while (l != r)
	{
		int u = qu[l++];
		if (l > MAXM)
			l = 0;
		for (int i = head3[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis3[v] < dis3[u] + val[v])
			{
				dis3[v] = dis3[u] + val[v];
				if (!vis[v])
				{
					vis[v] = 1;
					qu[r++] = v;
					if (r > MAXM)
						r = 0;
				}
			}
		vis[u] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		ins(u, v);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= m; ++i)
		if (clo[from[i]] != clo[to[i]])
		{
			ins2(clo[from[i]], clo[to[i]]);
			ins3(clo[to[i]], clo[from[i]]);
		}
	SPFA(), SPFA2();
	int ans = val[clo[1]];
	for (int i = 1; i <= m; ++i)
		if (clo[from[i]] != clo[to[i]])
		{
			int u = clo[from[i]], v = clo[to[i]];
			if (dis3[u] && dis2[v])
				ans = max(dis2[v] + dis3[u] - val[clo[1]], ans);
		}
	cout << ans << endl;
}