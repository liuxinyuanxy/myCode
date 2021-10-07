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
ll a[200005];
ll c[200005];
int main()
{
	ll ans = 0;
	rll n, m, s, t, l, r, x;
	sfl2(n, m),
	sfl2(t, s);
	t = -t;
	s = -s;
	sfl(a[0]);
	rep (i, 1, n) 
		sfl(a[i]),
		c[i] = a[i] - a[i - 1];
	rep (i, 1, n)
		ans += c[i] * (c[i] > 0 ? t : s);
	rep (i, 1, m)
	{
		sfl2(l, r),
		sfl(x);
		ans -= c[l] * (c[l] > 0 ? t : s);
		c[l] += x;
		ans += c[l] * (c[l] > 0 ? t : s);
		++r;
		if (r <= n)
		{
			ans -= c[r] * (c[r] > 0 ? t : s);
			c[r] -= x;
			ans += c[r] * (c[r] > 0 ? t : s);
		}
		pfl (ans);
		putchar('\n');
		
	}
	return 0;
}
//N 200000
//Q 200000
//S 1000000
//T 1000000
