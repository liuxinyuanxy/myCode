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
#define pfl(x) printf("%I64d", x)
#define pfl2(x, y) printf("%I64d%I64d", x, y)
#define sfl(x) scanf ("%I64d", &x)
#define sfl2(x, y)	scanf ("%I64d%I64d", &x, &y)
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
int main()
{
	ll n, m, k, l, b, e, mi;
	cin >> n >> m >> k >> l;
	if ((n / m) * m - k < l)
	{
		cout << -1;
		return 0;
	}
	b = 1, e = (n / m);
	while (b != e)
	{
		mi = mid(b, e);
		if (mi * m - k >= l)
			e = mi;
		else
			b = mi + 1;
	}
	cout << b;
	return 0;
}

