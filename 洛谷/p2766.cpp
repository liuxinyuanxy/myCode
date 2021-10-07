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
int a[MAXN], dp[MAXN], s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		for (int j = 1; j < i; ++j)
			if (a[j] <= a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		s = max(s, dp[i]);
	}
	cout << s << endl;
	S = (n << 1) + 1;
	T = S + 1;
	N = T;
	for (int i = 1; i <= n; ++i)
	{
		if (dp[i] == 1)
			insert(S, i, 1);
		if (dp[i] == s)
			insert(i + n, T, 1);
		insert(i, i + n, 1);
		for (int j = 1; j < i; ++j)
			if (a[j] <= a[i] && dp[j] + 1 == dp[i])
				insert(j + n, i, 1);
	}
	int ans = 0;
	while (bfs())
		ans += dfs(S, INF);
	fill(head + 1, head + 1 + N, 0);
	cout << ans << endl;
	S = (n << 1) + 1;
	T = S + 1;
	N = T;
	insert(S, 1, INF);
	if (dp[n] == s)
		insert(n << 1, T, INF);
	insert(1, 1 + n, INF);
	insert(n, n << 1, INF);
	for (int i = 1; i <= n; ++i)
	{
		if (dp[i] == 1)
			insert(S, i, 1);
		if (dp[i] == s)
			insert(i + n, T, 1);
		insert(i, i + n, 1);
		for (int j = 1; j < i; ++j)
			if (a[j] <= a[i] && dp[j] + 1 == dp[i])
				insert(j + n, i, 1);
	}
	ans = 0;
	while (bfs())
		ans += dfs(S, INF);
	fill(head + 1, head + 1 + N, 0);
	cout << ans << endl;
	return 0;
}