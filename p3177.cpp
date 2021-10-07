#include <iostream>
#include <cstdio>
#include <algorithm>
#define mid(a, b) ((a + b) >> 1)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define __ 2005
#define _ 4005
using namespace std;
ll dp[__][__][2];
int head[__], nxt[_], to[_], val[_];
int tot, k;
void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
void dfs(rt u, rt fa)
{
	rt v;
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == fa)
			continue;
		dfs(v, u);
		for (rt j = k; j >= 0; --j)
		{
			for (rt x = 0; x <= j; ++x)
			{
				dp[u][j][0] = max(dp[u][j][0], dp[u][j-x][0] + max(dp[v][x][0] + val[i], dp[v][x][1]));
				dp[u][j][1] = max(dp[u][j][1], dp[u][j-x][1] + max(dp[v][x][0], dp[v][x][1] + val[i]));
			}
//			dp[u][j][0] = max(dp[u][j][0], max(dp[v][j][1], dp[v][j][0] + val[i]));
//			dp[u][j][1] = max(dp[u][j][1], max(dp[v][j - 1][0], dp[v][j - 1][1] + val[i]));
		}
	}
}
int main()
{
	rt n = rd(), u, v, w;
	k = rd();
	for (rt i = 1; i < n; ++i)
		add(u = rd(), v = rd(), w = rd()),
		add(v, u, w);
	for (rt i = 1; i <= n; ++i)
		for (rt j = 0; j <= k; ++j)
			dp[i][j][0] = dp[i][j][1] = -0x3fffffff;
	for (rt i = 1; i <= n; ++i)
		dp[i][0][0] = dp[i][1][1] = 0;
	dfs(1, -1);
	printf("%lld", max(dp[1][k][0], dp[1][k][1]));
	return 0;
}


