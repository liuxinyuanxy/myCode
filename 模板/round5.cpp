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
#define MAX 50005
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int bl[MAX], blo;
int a[MAX], sum[MAX];
bool tag[MAX];
il void solve(rt x)
{
	if (tag[x])
		return;
	tag[x] = 1;
	sum[x] = 0;
	rep (i, (x - 1) * blo + 1, x * blo)
	{
		a[i] = sqrt(a[i]);
		sum[x] += a[i];
		if (a[i] > 1)
			tag[x] = 0;
		
	}
}
il void change(rt l, rt r)
{
	rt to = min(r, bl[l] * blo);
	rep (i, l, to)
		sum[bl[i]] -= a[i],
		a[i] = sqrt(a[i]),
		sum[bl[i]] += a[i];
	if (bl[l] != bl[r])
		rep (i, (bl[r] - 1) * blo + 1, r)
			sum[bl[i]] -= a[i],
			a[i] = sqrt(a[i]),
			sum[bl[i]] += a[i];
	rep (i, bl[l] + 1, bl[r] - 1)
		solve(i);
}
il void query(rt l, rt r)
{
	ll ans = 0;
	rt to = min(r, bl[l] * blo);
	rep (i, l, to)
		ans += a[i];
	if (bl[l] != bl[r])
		rep (i, (bl[r] - 1) * blo + 1, r)
			ans += a[i];
	rep (i, bl[l] + 1, bl[r] - 1)
		ans += sum[i];
	pfl(ans);
	putchar('\n');
}
int main()
{
	rt n, opt, l, r, c;
	sf(n);
	blo = sqrt(n);
	rep (i, 1, n)
		bl[i] = (i - 1) / blo + 1,
		sf(a[i]),
		sum[bl[i]] += a[i];
	rep (i, 1, n)
	{
		sf2(opt, l),
		sf2(r, c);
		if (opt)
			query(l, r);
		else
			change(l, r);
	}
	return 0;
}

