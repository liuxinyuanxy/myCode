#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, u) printf("%d %d", x, y)
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
#define mid(x, y) ((x) + (y) >> 1)
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
#define rep2(x, a, b) for (rt (x) = 0; (x) <= (a); (x) += (b))
#define MAX 4000
#define tot(i, j, k, l) ((i) + 2 * (j) + 3 * (k) + 4 * (l) + 1)
using namespace std;
int a[MAX], sum[5];
int s[41][41][41][41];
int main()
{
	rt n, m, b;
	sf2(n, m);
	rep(i, n, 1)
		sf(a[i]);
	rep(i, m, 1)
	{
		sf(b);
		++sum[b];
	}
	s[0][0][0][0] = a[1];
	rep2(i, sum[1], 1)
		rep2(j, sum[2], 1)
			rep2(k, sum[3], 1)
				rep2(l, sum[4], 1)
				{
					selfmax(s[i+1][j][k][l], s[i][j][k][l] + a[tot(i+1, j, k, l)]);
					selfmax(s[i][j+1][k][l], s[i][j][k][l] + a[tot(i, j+1, k, l)]);
					selfmax(s[i][j][k+1][l], s[i][j][k][l] + a[tot(i, j, k+1, l)]);
					selfmax(s[i][j][k][l+1], s[i][j][k][l] + a[tot(i, j, k, l+1)]);
				}
	pf(s[sum[1]][sum[2]][sum[3]][sum[4]]);
	return 0;
}
