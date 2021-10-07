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
const int three[] = {1,1,1,1,2,2,3,3,4,4,5,5};
il ll qpow(rll a, rll b)
{
	rll s = 1;
	for (; b; b >>= 1, a = a * a % MOD)
		if (b & 1)
			s = (s * a) % MOD;
	return s;
}
int main()
{
	ll n, ans = 1;
	scanf ("%lld", &n);
	ans = qpow(2, (n - 1) >> 1);
	if (n >= 4)
		ans = ans * qpow(3, (n - 4) / 12 * 5 + three[(n - 4) % 12]) % MOD;
	if (n >= 6)
		ans = ans * qpow(4, (n - 6) / 12 + 1) % MOD;
	printf("%lld\n", ans);
	main();
	return 0;
}


