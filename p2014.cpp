#include <iostream>
#include <cstdio>
#include <vector>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
using namespace std;
vector<int> son[400];
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
int val[400];
int dp[400][400];
int n = rd(), m = rd(); 
void dfs(rt u)
{
	for (auto v : son[u])
	{
		dfs(v);
		if (!u)
			continue;
		for (rt i = m - 1; i >= 1; --i)
			for (rt j = 1; j <= i; ++j)
				dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
	}
	if (!u)
		return;
	for (rt i = m; i >= 1; --i)
		dp[u][i] = dp[u][i - 1] + val[u];
}
int main()
{
	for (rt i = 1; i <= n; ++i)
		son[rd()].push_back(i),
		val[i] = rd();
	dfs(0);
	for (auto x : son[0])
		for (rt i = m; i >= 0; --i)
			for (rt j = 0; j <= i; ++j)
				dp[0][i] = max(dp[0][i], dp[0][i - j] + dp[x][j]);
	printf("%d", dp[0][m]);
	return 0;
}


