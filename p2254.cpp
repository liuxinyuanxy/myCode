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
#define INF 0x3fffffff
#define _ 205
#define __ 2000000
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
const int mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1};
int dp[_][_][_];
pii qu[__];
int l, r;
int a[_][_];
int len[_], to[_];
int n, m, K;
il void push();
void run(rt i, rt fi, rt fj)
{
	
}
int main()
{
	rc ch;
	rt x, y, d, s, t;
	sf2(n, m),
	sf2(x, y),
	sf(K);
	rep (i, 1, n)
		rep (j, 1, m)
		{
			ch = getchar();
			while (ch != '.' && ch != 'x')
				ch = getchar();
			if (ch == '.')
				a[i][j] = 1;
		}
	rep (i, 1, K)
	{
		sf2(s, t),
		sf(d);
		len[i] = t - s + 1;
		to[i] = d;
	}
	rep (i, 0, K)
		rep (j, 1, n)
			rep (k, 1, m)
				dp[i][j][k] = -INF;
	dp[0][x][y] = 0;
	rep (i, 1, K)
	switch(to[i])
	{
		case 1: rep (j, 1, m) run(i, n, j); break;
		case 2: rep (j, 1, m) run(i, 1, j); break;
		case 3: rep (j, 1, n) run(i, j, n); break;
		case 4: rep (j, 1, n) run(i, j, 1); break;
	}
	return 0;
}

