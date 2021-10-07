#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define il inline
#define re register
#define ll long long
#define rt int
#define rc char
#define rll long long
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
ll a[500005];
ll change[500005];
int bl[500005];
vector<ll> v[50000];
int blo, tot;
int n;
il void reset(rt x)
{
	v[x].clear(); 
	rep(i, (x - 1) * blo + 1, min(x * blo, n))
		v[x].push_back(a[i]);
	sort(v[x].begin(), v[x].end());
} 
il void add(rt l, rt r, rt c)
{
	rt to = min(bl[l] * blo, r);
	rep(i, l, to)
		a[i] += c;
	reset(bl[l]);
	if (bl[l] != bl[r])
	{
		rep(i, (bl[r] - 1) * blo + 1, r)
			a[i] += c;
		reset(bl[r]);
	}
	rep(i, bl[l] + 1, bl[r] - 1)
		change[i] += c;
}
il int check(rt i, rll c)
{
	rt len = lower_bound(v[i].begin(), v[i].end(), c - change[i]) - v[i].begin(); 
//	cout << v[i].size() << "\t" << c << endl;
	return len;
}
il void query(rt l, rt r, rll c)
{
	rt ans = 0;
	rt to = min(bl[l] * blo, r);
	rep(i, l, to)
		if (a[i] + change[bl[i]] < c)
			++ans;
	if (bl[l] != bl[r])
	{
		rep(i, (bl[r] - 1) * blo + 1, r)
			if (a[i] + change[bl[i]] < c)
				++ans;
	}
	rep(i, bl[l] + 1, bl[r] - 1)
		ans += check(i, c);
	pf(ans);
	putchar('\n');
}
int main()
{
//	freopen("out.txt", "w", stdout);
	rt opt, l, r, c;
	sf(n);
	blo = sqrt(n);
	rep(i, 1, n)
		sfl(a[i]);
	rep(i, 1, n)
		bl[i] = (i - 1) / blo + 1; 
	rep(i, 1, bl[n])
		reset(i);
	rep(i, 1, n)
	{
		sf2(opt, l),
		sf2(r, c);
		if (opt)
			query(l, r, c * 1ll * c);
		else
			add(l, r, c);
	}
	return 0;
}

