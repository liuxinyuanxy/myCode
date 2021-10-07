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
using namespace std;
il ll rd()
{
	rll s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s; 
}
ll fac[100005], facinv[100005];
il ll qpow(rll a, rll b, rll m)
{
	rll s = 1;
	for (; b; b >>= 1, a = a * a % m)
		if (b & 1)
			s = (s * a) % m;
	return s;
}
il ll lucas(rll n, rll m, rll p)
{
	if (n > m)
		return 0;
	if (m < p)
		return fac[m] * facinv[n] % p * facinv[m - n] % p;
	return lucas(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
int main()
{
	ll T = rd(), n, m, p;
	fac[0] = facinv[0] = 1;
	while (T--)
	{
		n = rd(), m = rd(), p = rd();
		for (rll i = 1; i < p; ++i)
		{
			fac[i] = (fac[i - 1] * i) % p;
		}
		facinv[p - 1] = qpow(fac[p - 1], p - 2, p);
		for (rll i = p - 2; i >= 1; --i)
			facinv[i] = (i + 1) * facinv[i + 1] % p;
		printf("%lld\n", lucas(m, m + n, p));
	}
	return 0;
}


