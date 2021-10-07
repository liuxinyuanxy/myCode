#include <iostream>
#include <cstdio>
#define max(a, b) (((a) > (b) ? (a) : (b)))
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
int a[1000000], b[1000000];
int dp[1005][1005];
int main()
{
	int n, ans = 0;
	scanf ("%d", &n);
	for (rt i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (rt i = 1; i <= n; ++i)
		scanf ("%d", &b[i]);
	for (rt i = 1; i <= n; ++i)
		for (rt j = 1; j <= n; ++j)
			dp[i][j] = (a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1])),
			ans = max(ans, dp[i][j]);
	printf("%d", ans);
	return 0;
}


