#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define il inline
#define LL long long
#define gc getchar
using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 2000000;
int head[MAXN], nxt[MAXN], to[MAXN], ret[MAXN];
int cnt = 1;
int qu[MAXN + 5], l, r;
int dis[MAXN];
int S, T, N;
il void ins(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	ret[cnt] = w;
}
il void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, 0);
}
bool bfs()
{
	fill(dis + 1, dis + 1 + N, 0);
	l = r = 0;
	qu[r++] = S;
	dis[S] = 1;
	while (l != r)
	{
		int u = qu[l++];
		if (l > MAXN)
			l = 0;
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (ret[i] && !dis[v])
			{
				dis[v] = dis[u] + 1;
				if (v == T)
					return 1;
				qu[r++] = v;
				if (r > MAXN)
					r = 0;
			}
	}
	return 0;
}
int dfs(int u, int maxflow)
{
	if (u == T)
		return maxflow;
	int ans = 0;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
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
const int mx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, my[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool wrong[250][250];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		wrong[x][y] = 1;
	}
	S = n * n + 1;
	T = S + 1;
	N = T;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (wrong[i][j])
				continue;
			if ((i & 1) ^ (j & 1))
				insert((i - 1) * n + j, T, 1);
			else
			{
				insert(S, (i - 1) * n + j, 1);
				for (int k = 0; k < 8; ++k)
				{
					int tx = i + mx[k], ty = j + my[k];
					if (tx > 0 && ty > 0 && tx <= n && ty <= n && !wrong[tx][ty])
						insert((i - 1) * n + j, (tx - 1) * n + ty, 1);
				}
			}
		}
	int ans = n * n - m;
	while (bfs())
		ans -= dfs(S, INF);
	cout << ans << endl;
	return 0;
}