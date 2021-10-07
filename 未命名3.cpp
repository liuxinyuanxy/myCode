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
il void exgcd(rll a, rll b, rll& x, rll& y, rll& gcd)
{
	if (!b)
		gcd = a, x = 1, y = 0;
	else
		exgcd(b, a % b, y, x, gcd),
		y -= (a / b) * x;
}
int main()
{
	ll x, y, m, n, l, a, b, c, G;
	scanf ("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
	a = (n - m),
	b = l,
	c = x - y;
	if (a < 0)
		a = -a,
		c = -c;
	exgcd(a, b, x, y, G);
	if (c % G)
		printf("Impossible");
	else
	{
		x = x * c / G;
		printf("%lld", (x % (b / G) + (b / G)) % (b / G));
	}
	return 0;
}
