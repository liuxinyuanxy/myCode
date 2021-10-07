#include <iostream>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
ll dp[2000][200];
ll a[2000][2000];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (m > n)
	{
		printf("0");
		return 0;
	}
	for (rt i = 1; i <= n; ++i)
		scanf("%lld", &a[i][i]);
	for (rt i = 1; i <= n; ++i)
		for (rt j = 1; j + i <= n; ++j)
			a[j][j + i] = a[j][j + i - 1] ^ a[i + j][i + j];
	for (rt i = 0; i <= n; ++i)
	{
		for (rt j = 0; j <= m; ++j)
			dp[i][j] = -0x7fffffff;
	}
	dp[0][0] = 0;
	for (rt i = 1; i <= n; ++i)
		for (rt j = 1; j <= min(m, i); ++j)
			for (rt k = 0; k < i; ++k)
			{
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + a[k + 1][i]);
			}
	printf("%lld", dp[n][m]);
	return 0;
}
