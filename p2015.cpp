#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 305
using namespace std;
int q;
int dp[_][_];
int head[_], to[_], val[_], nxt[_], tot;
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
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
		for (rt j = q; j >= 1; --j)
			for (rt k = 1; k <= j; ++k)
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k - 1] + val[i]);
	}
}
int main()
{
	rt n = rd(), u, v, w;
	q = rd();
	for (rt i = 1; i < n; ++i)
	{
		u = rd(), v = rd(), w = rd();
		dp[i][0] = 0;
		for (rt j = 1; j <= q; ++j)
			dp[i][j] = -0x3fffffff;
		add(u, v, w);
		add(v, u, w);	
	} 
	for (rt j = 1; j <= q; ++j)
		dp[n][j] = -0x3fffffff;
	dfs(1, -1);
	printf("%d", dp[1][q]);
	return 0;
}


