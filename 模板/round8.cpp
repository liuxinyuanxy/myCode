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
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int blo, n;
int bl[MAX], a[MAX], tag[MAX];
il void reset(rt x)
{
	if (tag[x] == -1)
		return;
	rt to = min(n, blo * x);
	rep (i, (x - 1) * blo + 1, to)
		a[i] = tag[x];
	tag[x] = -1;
}
il void solve(rt l, rt r, rt c)
{
	rt ans = 0;
	rt to = min(r, bl[l] * blo);
	reset(bl[l]);
	rep (i, l, to)
		if (a[i] != c)
			a[i] = c;
		else
			++ans;
	if (bl[l] != bl[r])
	{
		reset(bl[r]);
		rep (i, (bl[r] - 1) * blo + 1, r)
			if (a[i] != c)
				a[i] = c;
			else
				++ans;
	}
	rep (i, bl[l] + 1, bl[r] - 1)
		if (tag[i] != -1)
			if (tag[i] != c)
				tag[i] = c;
			else
				ans += blo;
		else
		{
			rep (j, (i - 1) * blo + 1, i * blo)
				if (a[j] != c)
					a[j] = c;
				else
					++ans;
			tag[i] = c;
		}
	pf(ans);
	putchar('\n');
}
int main()
{
	rt l, r, c;
	sf(n);
	blo = sqrt(n);
	rep (i, 1, n)
		sf(a[i]),
		bl[i] = (i - 1) / blo + 1;
	rep (i, 1, bl[n])
		tag[i] = -1;
	rep (i, 1, n)
	{
		sf(l),
		sf2(r, c);
		solve(l, r, c);
	}
	return 0;
}

