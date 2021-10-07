#include <iostream>
#include <cstdio>
#include <algorithm>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y) scanf ("%lld%lld", &x, &y)
#define sfl3(x, y, z) scanf ("%lld%lld%lld", &x, &y, &z)
#define pfl(x) printf ("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define pfl3(x, y, z) printf("%lld%lld%lld", x, y, z)
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define lowbit(x) ((x) & -(x))
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
using namespace __gnu_pbds;
gp_hash_table<ll, int> hs;
int n;
ll a[50000];
ll b[50000];
ll low[50000], high[50000];
ll tre[50000];
il int rd()
{
	rc ch; rt s = 0; 
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9'); 
	return s;
}
il void add(rll x, rll p)
{
	while (p <= n)
		tre[p] += x,
		p += lowbit(p);
}
il ll query(rll p)
{
	rll ans = 0;
	while (p)
		ans += tre[p],
		p -= lowbit(p);
	return ans;
}
int main()
{
	ll ans = 0;
	sf(n);
	rep (i, 1, n)
	{
		sfl(a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	rep (i, 1, n)
		hs[b[i]] = i;
	rep (i, 1, n)
		a[i] = hs[a[i]];
	rep (i, 1, n)
		low[i] = query(a[i] - 1),
		add(1, a[i]);
	rep (i, 0, n)
		tre[i] = 0;
	for (rt i = n; i >= 1; --i)
		high[i] = query(n) - query(a[i]),
		add(1, a[i]);
	rep (i, 1, n)
		ans += low[i] * high[i];
	pfl(ans);
	return 0;
}

