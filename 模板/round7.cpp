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
#define MAX 500000
#define MOD 10007
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int n;
int blo;
int bl[MAX], tag1[MAX], tag2[MAX];
int a[MAX];
il void reset(rt x)
{
	rt to = min(n, x * blo);
	rep (i, (x - 1) * blo + 1, to)
		a[i] = jia(cheng(a[i], tag1[x]), tag2[x]);
	tag1[x] = 1;
	tag2[x] = 0;
}
il void add(rt l, rt r, rt c)
{
	rt to = min(r, bl[l] * blo);
	reset(bl[l]);
	rep (i, l, to)
		selfjia(a[i], c);
	if (bl[l] != bl[r])
	{
		reset(bl[r]);
		rep (i, (bl[r] - 1) * blo + 1, r)
			selfjia(a[i], c);
	}
	rep (i, bl[l] + 1, bl[r] - 1)
		selfjia(tag2[i], c);
}
il void mul(rt l, rt r, rt c)
{
	rt to = min(r, bl[l] * blo);
	reset(bl[l]);
	rep (i, l, to)
		selfcheng(a[i], c);
	if (bl[l] != bl[r])
	{
		reset(bl[r]);
		rep (i, (bl[r] - 1) * blo + 1, r)
			selfcheng(a[i], c);
	}
	rep (i, bl[l] + 1, bl[r] - 1)
		selfcheng(tag1[i], c),
		selfcheng(tag2[i], c);
}
il void query(rt x)
{
	pf(jia(cheng(a[x], tag1[bl[x]]), tag2[bl[x]]));
	putchar('\n');
}
int main()
{
	rt opt, l, r, c;
	sf(n);
	blo = sqrt(n);
	rep (i, 1, n)
		sf(a[i]);
	rep (i, 1, n)
		bl[i] = (i - 1) / blo + 1;
	rep (i, 1, bl[n])
		tag1[i] = 1;
	rep (i, 1, n)
	{
		sf2(opt, l), sf2(r, c);
		if (opt == 0)
			add(l, r, c);
		else
			if (opt == 1)
				mul(l, r, c);
			else
				query(r);
	}
	return 0;
}

