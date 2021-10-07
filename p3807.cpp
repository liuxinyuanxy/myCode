#include <iostream>
#include <cstdio>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y) scanf ("%lld%lld", &x, &y)
#define sfl3(x, y, z) scanf ("%lld%lld%lld", &x, &y, &z)
#define pfl(x) printf ("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define pfl3(x, y, z) printf("%lld%lld%lld", x, y, z)
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define _ 1000000
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
ll fac[_], facinv[_];
ll lucas(rll n, rll m, rll p)
{
	if (n > m)
		return 0;
	if (m < p)
		return fac[m] * facinv[n] % p * facinv[m - n] % p;
	return lucas(n / p, m / p, p) * lucas(n % p, m % p, p) % p;
}
il ll qpow(rll x, rll y, rll p)
{
	rll s = 1;
	for (;y; y >>= 1, x = (x * x) % p)
		if (y & 1)
			s = (s * x) % p;
	return s;
}
int main()
{
	rll n, m, p, t;
	sfl(t);
	while (t--)
	{
		sfl2(n, m);
		sfl(p);
		fac[1] = fac[0] = 1;
		facinv[0] = 1;
		rep (i, 2, p - 1)
			fac[i] = fac[i - 1] * i % p;
		facinv[p - 1] = qpow(fac[p - 1], p - 2, p);
		for (rll i = p - 2; i >= 1; --i)
			facinv[i] = facinv[i + 1] * (i + 1) % p; 
		pfl(lucas(m, m + n, p));		
		putchar('\n');
	}
	return 0;
}

