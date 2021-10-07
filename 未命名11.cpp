#include <iostream>
#include <cstdio>
#include <cstring>
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
int a[10], cnt;
int dp[10][10];
struct node{
	int w, s;
	 node() {w = 0, s = 1;}
};
int dfs(rt pos, rt pre, rt led, rt limit)
{
	if (pos > cnt)
		return 1 && !led;
	if (dp[pos][pre] != -1 && !led && !limit)
		return dp[pos][pre];
	rt res = !limit ? 9 : a[cnt - pos + 1];
	rt ret = 0;
	for (rt i = 0; i <= res; ++i)
	{
		if (i == 4 || (i == 2 && pre == 6))
			continue;
		if (!i && led)
			ret += dfs(pos + 1, 0, 1, limit && i == res);
		else
			ret += dfs(pos + 1, i, 0, limit && i == res);
	}
	if (!led && !limit)
		dp[pos][pre] = ret;
	return ret;
}
il int query(rt n)
{
	cnt = 0;
	while (n)
		a[++cnt] = n % 10,
		n /= 10;
	memset(dp, -1, sizeof(dp));
	return dfs(1, 0, 1, 1);
}
int main()
{
	int n, m;
	while (scanf ("%d%d", &n, &m), n + m)
		printf("%d\n", query(m) - ((n - 1) ? query(n - 1) : 0));
	return 0;
}


