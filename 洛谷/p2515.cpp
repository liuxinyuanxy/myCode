#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000;
vector<int> edge[MAXN];
vector<int> edge2[MAXN];
int w[MAXN], v[MAXN], d[MAXN];
int dp[MAXN][MAXN];
int m;
int tot;
int clo[MAXN];
int out[MAXN];
int dfn[MAXN], low[MAXN], vis[MAXN], sta[MAXN], top;
void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	vis[u] = 1;
	sta[++top] = u;
	for (auto v : edge[u])
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	if (low[u] == dfn[u])
	{
		vis[u] = 0;
		clo[u] = u;
		int y;
		while ((y = sta[top--]) != u)
			clo[y] = u, vis[y] = 0, w[u] += w[y], v[u] += v[y];
	}
}
int ned[MAXN], sze[MAXN], cnt, pos[MAXN];
void dfs(int u)
{
	pos[++cnt] = u;
	sze[u] = 1;
	for (auto t : edge2[u])
		ned[t] = ned[u] + w[u], dfs(t), sze[u] += sze[t];
}
#define upd(x, y) \
	if (y > x)    \
		x = y;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int v = 1; v <= n; ++v)
	{
		cin >> d[v];
		edge[d[v]].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	for (int u = 1; u <= n; ++u)
		for (auto v : edge[u])
			if (clo[v] != clo[u])
				edge2[clo[u]].push_back(clo[v]), out[clo[v]] = 1;
	for (int i = 1; i <= n; ++i)
		if (i == clo[i] && !out[i])
			edge2[0].push_back(i);
	dfs(0);
	for (int i = 1; i <= cnt; ++i)
	{
		for (int j = m - w[pos[i]]; j >= ned[pos[i]]; --j)
			upd(dp[i + 1][j + w[pos[i]]], dp[i][j] + v[pos[i]]);
		for (int j = m; j >= ned[pos[i]]; --j)
			upd(dp[i + sze[pos[i]]][j], dp[i][j]);
	}
	cout << dp[cnt + 1][m];
	return 0;
}