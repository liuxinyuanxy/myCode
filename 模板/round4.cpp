#include <iostream>
#include <cstdio>
#include <cmath>
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
#define MAX 50005
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int n;
int blo;
int bl[MAX], a[MAX];
ll ans[MAX], change[MAX];
il void add(rll l, rll r, rll c)
{
	rt to = min(r, 1ll * bl[l] * blo);
	rep(i, l, to)
	{
		a[i] += c;
		ans[bl[i]] += c;
	}
	if (bl[l] != bl[r])
		rep(i, (bl[r] - 1) * blo + 1, r)
		{
			a[i] += c;
			ans[bl[i]] += c;
		}
	rep (i, bl[l] + 1, bl[r] - 1)
		change[i] += c;
}
il void query(rll l, rll r, rll c)
{
	ll s = 0;
	rt to = min(r, bl[l] * blo * 1ll);
	rep (i, l, to)
		s = (s + (a[i] + change[bl[i]]) % (c + 1)) % (c + 1);
	if (bl[l] != bl[r])
		rep (i, (bl[r] - 1) * blo + 1, r)
			s = (s + (a[i] + change[bl[i]]) % (c + 1)) % (c + 1);
	rep (i, bl[l] + 1, bl[r] - 1)
		s = (s + (ans[i] + change[i] * blo % (c + 1)) % (c + 1)) % (c + 1);
	pfl(s);
	putchar('\n');
}
int main()
{
	rll opt, l, r, c;
	sf(n);
	blo = sqrt(n);
	rep (i, 1, n)
		sf(a[i]),
		bl[i] = (i - 1) / blo + 1;
	rep (i, 1, n)
		ans[bl[i]] += a[i];
	rep (i, 1, n)
	{
		sfl2(opt, l),
		sfl2(r, c);
		if (!opt)
			add(l, r, c);
		else
			query(l, r, c);
	}	
	return 0;
}

