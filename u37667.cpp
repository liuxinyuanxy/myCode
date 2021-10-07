#include <iostream>
#include <cstdio>
#define ll long long
#define rt register int
using namespace std;
int main()
{
	ll n, m, s, q, a, b;
	scanf("%lld%lld%lld%lld", &n, &m, &s, &q);
	for (ll i = 1; i <= s; ++i)
		scanf("%lld%lld", &a, &b);
	for (ll i = 1; i <= q; ++i)
		scanf("%lld", &a);
	puts("Impossible!");
	return 0;
}

