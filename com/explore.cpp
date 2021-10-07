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
#define MAX 200005
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int a[MAX], s;
il void cl(rt l, rt r)
{
	rep (i, l, r)
		a[i] = 0;
}
il void add(rt l, rt r)
{
	rep (i, l, r)
		a[i] = 1;
}
il void query(rt k)
{
	rt l = k, r = k;
	if (a[k])
		printf("0\n");
	else
	{
		while (!a[l] && l >= 1) --l;
		while (!a[r] && r <= s) ++r;
		if (l == 0|| r == s + 1)
			printf("INF\n");
		else
			printf("%d\n", r - l - 1);
	}
}
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	rt opt, l, r;
	rt q;
	sf2(s, q);
	rep (i, 1, q)
	{
		sf2(opt, l);
		if (opt == 3)
			query(l);
		else
		{
			sf(r);
			if (opt == 2)
				cl(l, r);
			else
				add(l, r);
		}
	}
	return 0;
}

