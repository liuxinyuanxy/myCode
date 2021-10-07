#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
inline ll qpow(ll x, ll p, ll m)
{
	ll s = 1, a = x % m;
	for (; p; p >>= 1, a = a * a % m)
		if (p & 1)
			s = s * a % m;
	return s;
}
int main()
{
	int n, m, k, x;
	scanf ("%d%d%d%d", &n, &m, &k, &x);
	printf("%lld", (x + m * qpow(10, k, n)) % n);
	return 0;
}
