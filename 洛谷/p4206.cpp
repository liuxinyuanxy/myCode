#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 2005;
int n, e, c, m;
int cnt, head[MAXN], nxt[MAXN], to[MAXN], step[MAXN], step2[MAXN][MAXN], val[MAXN];
int dis[MAXN];
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	++val[v];
}
int qu[MAXN + 5], l, r;
void bfs(int s)
{
	fill(dis + 1, dis + 1 + n, 0);
	l = r = 0;
	qu[r++] = s;
	dis[s] = 1;
	step[s] = s;
	while (l != r)
	{
		int u = qu[l++];
		if (l > MAXN)
			l = 0;
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!dis[v])
			{
				step[v] = u, dis[v] = dis[u] + 1, qu[r++] = v;
				if (r > MAXN)
					r = 0;
			}
			else if (dis[v] == dis[u] + 1 && u < step[v])
				step[v] = u;
	}
}
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		bfs(i);
		for (int j = 1; j <= n; ++j)
			step2[i][j] = step[step[j]];
	}
}
bool vis[MAXN][MAXN];
double dp[MAXN][MAXN];
double get(int u, int v)
{
	if (vis[u][v])
		return dp[u][v];
	vis[u][v] = 1;
	if (step2[u][v] == u)
		return vis[u][v] = 1, dp[u][v] = 1;
	double ans = (get(u, step2[u][v]) + 1.0) / (val[u] + 1.0);
	for (int i = head[u]; i; i = nxt[i])
		ans += (get(to[i], step2[u][v]) + 1.0) / (val[u] + 1.0);
	return vis[u][v] = 1, dp[u][v] = ans;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> e >> c >> m;
	for (int i = 1; i <= e; ++i)
	{
		int u, v;
		cin >> u >> v;
		ins(u, v);
		ins(v, u);
	}
	init();
	for (int i = 1; i <= n; ++i)
		dp[i][i] = 0, vis[i][i] = 1;
	printf("%.3lf", get(m, c));
	return 0;
}