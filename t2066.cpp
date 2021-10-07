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
#define MOD 1000000007
using namespace std;
il ll rd()
{
	rll s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
il ll qpow(rll a, rll b)
{
	rll s = 1;
	for (; b; b >>= 1, a = a * a % MOD)
		if (b & 1)
			s = s * a % MOD;
	return s;
}
int main()
{
	rll s, qq = 1;
	rll n = rd(), m = rd(), k = rd(), q = rd();
	q %= MOD;
	qq = q;
	s = rd();
	for (rt i = 1; i <= m; ++i)
	{
		s = (s + rd() * qq) % MOD;
		qq = q * qq % MOD;
	}
	q = 1;
	for (rt i = 1; i <= k; ++i)
		q = (q * qpow(i, MOD - 2) % MOD * (n - k + i)) % MOD; 
	printf("%lld", s * q % MOD);
	return 0;
}
