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
ll n;
il ll gcd(rll a, rll b)
{
	return !b ? a : gcd(b, a % b);
}
ll ans = 0;
int main()
{
	ll GCD;
	for (rll n = 1; n <= 300; ++n)
	{
	ans = 0;
	for (rll i = 1; i < n; ++i)
	{
		for (rll j = i + 1; j <= n; ++j)
		{
			GCD = gcd(i, j);
			if (i * j / GCD == n)
			{
				++ans;
			}
		}
	}
	printf("%lld %lld\n", n, ans * 2 + 1);
	}
	return 0;
}


