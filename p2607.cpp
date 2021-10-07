#include <iostream>
#include <cstdio>
#include <vector>
#define gc getchar
#define rt register int
using namespace std;
const int MAXN = 2000005;
typedef pair<int, int> P;
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
long long dp[MAXN][2];
int val[MAXN];
bool vis[MAXN];
int l, r, p;
int cnt, tot = 1;
int head[MAXN], nxt[MAXN], to[MAXN];
void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
void dfs(rt u, rt f)
{
	rt v;
	vis[u] = 1;
	for (rt i = head[u]; i; i = nxt[i])
	{
		if (~p)
			return;
		if (i == (f ^ 1))
			continue;
		v = to[i];
		if (vis[v])
		{
			l = v,
			r = u,
			p = i;
			return;
		}
		else
			dfs(v, i);
	}
	// for (auto x : edge[u])
	// {
	// 	if (x.second == f)
	// 		continue;
	// 	if (vis[x.first])
	// 		l = x.first,
	// 		r = u,
	// 		p = x.second;
	// 	else
	// 		dfs(x.first, x.second);
	// }
}
void solve(rt u, rt f)
{
	vis[u] = 1;
	dp[u][1] = val[u];
	dp[u][0] = 0;
	for (rt i = head[u]; i; i = nxt[i])
	{
		if (i == p || i == (p ^ 1) || (i == (f ^ 1)))
			continue;
		int v = to[i];
		solve(v, i);
		dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
	// for (auto x : edge[u])
	// {
	// 	if (x.second == f || x.second == p)
	// 		continue;
	// 	solve(x.first, x.second);
	// 	dp[u][1] += dp[x.first][0];
	// 	dp[u][0] += max(dp[x.first][0], dp[x.first][1]);
	// }
}
int main()
{
	int n;
	long long t, ans = 0;
	rd(n);
	for (rt i = 1; i <= n; ++i)
	{
		rd(val[i], t);
		// edge[t].push_back(P(i, ++cnt));
		// edge[i].push_back(P(t, cnt));
		add(i, t);
		add(t, i);
	}
	for (rt i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			p = -1;
			l = r = 0;
			dfs(i, -1);
			solve(l, -1);
			t = dp[l][0];
			solve(r, -1);
			ans += max(t, dp[r][0]);
		}
	}
	printf("%lld", ans);
	return 0;
}