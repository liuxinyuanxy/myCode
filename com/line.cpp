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
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
il int gcd(rll a, rll b)
{
	return !b ? a : gcd(b, a % b);
}
il void print(rll a, rll b)
{
	rll g = gcd(a, b);
	a /= g, b /= g;
	printf("%lld/%lld", a, b);
}
int main()
{
	freopen("line.in", "r", stdin);
	freopen("line.out", "w", stdout);
	rll n, m, g;
	sfl2(n, m);
	g = gcd(n, m);
	n /= g,
	m /= g;
	if (n > m)
		swap(n, m);
	if (n == m)
		print(1, 1);
	else
		if (n == 1)
			m & 1 ? print(m / 2 + 1, m) : print(1, 2);
		else
			(n * m) & 1 ? print(m / 2 + 1, m) : print(1, 2);
	return 0;
}

