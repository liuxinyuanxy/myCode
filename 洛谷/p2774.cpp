#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define D() cerr << __LINE__ << endl;
#define il inline
#define LL long long
#define gc getchar
#define int LL
using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 2000000;
int cur[MAXN];
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
	for (int i = 1; i <= N; ++i)
		cur[i] = head[i];
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
const int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> m >> n;
	S = n * m + 1;
	T = S + 1;
	N = T;
	int ans = 0, x;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> x;
			ans += x;
			if ((i & 1) ^ (j & 1))
			{
				insert(S, (i - 1) * n + j, x);
				for (int k = 0; k < 4; ++k)
				{
					int tx = i + mx[k], ty = j + my[k];
					if (tx > 0 && ty > 0 && tx <= m && ty <= n)
						insert((i - 1) * n + j, (tx - 1) * n + ty, INF);
				}
			}
			else
				insert((i - 1) * n + j, T, x);
		}
	while (bfs())
		ans -= dfs(S, INF);
	cout << ans << endl;
	return 0;
}