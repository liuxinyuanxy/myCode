#include <algorithm>
#include <vector>
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
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define MAX 100005
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int n;
int blo;
ll bl[MAX], a[MAX];
ll change[MAX];
vector<ll> v[MAX];
il void reset(rt x)
{
	v[x].clear();
	rep (i, (x - 1) * blo + 1, min(n, x * blo))
		v[x].push_back(a[i]);
	sort(v[x].begin(), v[x].end());
}
il void add(rll l, rll r, rll c)
{
	rll to = min(r, (bl[l] * blo));
	rep (i, l, to)
		a[i] += c;
	reset(bl[l]);
	if (bl[l] != bl[r])
	{
		rep (i, (bl[r] - 1) * blo + 1, r)
			a[i] += c;
		reset(bl[r]);
	}
	rep (i, bl[l] + 1, bl[r] - 1)
		change[i] += c;
}
il ll ask(ll i, ll c)
{
	vector<ll>::iterator p = lower_bound(v[i].begin(), v[i].end(), c - change[i]);
//	cout << c << "\t" << *p << endl;
	if (p == v[i].begin())
		return -1;
	else
		return *(p - 1) + change[i];
}
il void query(rll l, rll r, rll c)
{
	ll ans = -1;
	rll to = min(r, (bl[l] * blo));
	rep (i, l, to)
		if (a[i] + change[bl[i]] < c)
			selfmax(ans, a[i] + change[bl[i]]);
	if (bl[l] != bl[r])
		rep (i, (bl[r] - 1) * blo + 1, r)
			if (a[i] + change[bl[i]] < c)
				selfmax(ans, a[i] + change[bl[i]]);	
	rep (i, bl[l] + 1, bl[r] - 1)
		selfmax(ans, ask(i, c));
	pfl(ans);
	putchar('\n');
}
int main()
{
	ll opt, l, r, c;
	sf(n);
	rep(i, 1, n)
		sfl(a[i]);
	blo = sqrt(n);
	rep(i, 1, n)
		bl[i] = (i - 1) / blo + 1;
	rep(i, 1, bl[n])
		reset(i);
	rep(i, 1, n)
	{
		sfl2(opt, l),
		sfl2(r, c);
		if (opt)
			query(l, r, c);
		else
			add(l, r, c);
	}
	return 0;
}

