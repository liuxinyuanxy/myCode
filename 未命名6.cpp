#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register ll
#define rll register ll
#define mp make_pair
using namespace std;
void exgcd(rt a, rt b, rt& x, rt& y, rt& gcd)
{
	if (!b)
		gcd = a, x = 1, y = 0;
	else
		exgcd(b, a % b, y, x, gcd),
		y -= (a / b) * x;
}
ll cal(rt a, rt b, rt c)
{
	ll x, y, G, ans, xx, yy, aa, bb;
	exgcd(a, b, x, y, G);
	if (c % G)
		return -1;
	aa = a / G, bb = b / G;
	x = x * c / G, y = y * c / G;
	xx = (x % bb + bb) % bb;
	yy = (c - a * xx) / b;
	if (yy < 0)
		yy = -yy;
	ans = xx + yy;
	yy = (y % aa + aa) % aa;
	xx = (c - b * yy) / a;
	if (xx < 0)
		xx = -xx;
	return min(ans, xx + yy);
}
int main()
{
	ll T, A, B, a, b;
	scanf ("%lld", &T);
	while (T--)
	{
		scanf ("%lld%lld%lld%lld", &A, &B, &a, &b);
		printf("%lld\n", cal(a, b, B - A));
	}
	return 0;
}


