#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y)	scanf ("%lld%lld", &x, &y)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
#define repd(x, b, a) for (rt (x) = (b); (x) >= (a); --(x))
using namespace std;
int a[2505][2505];
int can1[2505][2505], can2[2505][2505];
int dp[2505][2505];
int main()
{
	rt n, m, MAX = 0;
	sf2(n, m);
	rep (i, 1, n)
		rep (j, 1, m)
		{
			sf(a[i][j]);
			dp[i][j] = a[i][j];
			selfmax(MAX, dp[i][j]);
			if (!a[i][j])
				can1[i][j] = can1[i][j - 1] + 1,
				can2[i][j] = can2[i - 1][j] + 1;
		}
	rep (i, 1, n)
		rep (j, 1, m)
			if (a[i][j])
			{
				dp[i][j] = min(min(can1[i][j - 1], can2[i - 1][j]), dp[i - 1][j - 1]) + 1,
				selfmax(MAX, dp[i][j]);
			}
	
	rep (i, 1, n)
		repd (j, m, 1)
		{
			dp[i][j] = a[i][j];
			selfmax(MAX, dp[i][j]);
			if (!a[i][j])
				can1[i][j] = can1[i][j + 1] + 1;
		}
	rep (i, 1, n)
		repd (j, m, 1)
			if (a[i][j])
			{	
				dp[i][j] = min(min(can1[i][j + 1], can2[i - 1][j]), dp[i - 1][j + 1]) + 1,
				selfmax(MAX, dp[i][j]);
			}
	pf(MAX);
	return 0;
}

