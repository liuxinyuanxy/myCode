#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 120005;
int cnt = 1;
int S, T, N;
int head[MAXN], nxt[MAXN], to[MAXN], ret[MAXN];
int cur[MAXN], dis[MAXN];
int qu[MAXN + 10], l, r;
void ins(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	ret[cnt] = w;
}
void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, 0);
}
bool bfs()
{
	l = r = 0;
	for (int i = 1; i <= N; ++i)
		dis[i] = 0, cur[i] = head[i];
	qu[r++] = S;
	dis[S] = 1;
	while (l != r)
	{
		int u = qu[l++];
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (ret[i] && !dis[v])
			{
				dis[v] = dis[u] + 1,
				qu[r++] = v;
				if (v == T)
					return 1;
			}
	}
	return 0;
}
int dfs(int u, int maxflow)
{
	if (u == T)
		return maxflow;
	int ans = 0;
	for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (ret[i] && dis[v] == dis[u] + 1)
		{
			int temp = dfs(v, min(maxflow - ans, ret[i]));
			ret[i] -= temp;
			ret[i ^ 1] += temp;
			ans += temp;
			if (ans == maxflow)
				break;
		}
	if (!ans)
		dis[u] = -2;
	return ans;
}
int tot;
int vis[MAXN], dfn[MAXN], low[MAXN], clo[MAXN];
int sta[MAXN], top;
int y;
void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	sta[++top] = u;
	vis[u] = 1;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (ret[i])
		{
			if (!dfn[v])
				tarjan(v), low[u] = min(low[u], low[v]);
			else if (vis[v])
				low[u] = min(low[u], dfn[v]);
		}
	if (low[u] == dfn[u])
		do
			y = sta[top--], clo[y] = u, vis[y] = 0;
		while (y != u);
}
int u[MAXN], v[MAXN];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m;
	cin >> N >> m >> S >> T;
	for (int i = 1; i <= m; ++i)
	{
		int w;
		cin >> u[i] >> v[i] >> w;
		insert(u[i], v[i], w);
	}
	while (bfs())
		dfs(S, 0x3fffffff);
	for (int i = 1; i <= N; ++i)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= m; ++i)
	{
		if (ret[i << 1])
		{
			cout << "0 0\n";
			continue;
		}
		cout << (int)(clo[u[i]] != clo[v[i]]) << " ";
		cout << (int)(clo[u[i]] == clo[S] && clo[v[i]] == clo[T]) << endl;
	}
	return 0;
}