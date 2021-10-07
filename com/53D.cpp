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
il ll rd()
{
	rll s = 0, p = 1;
	rc ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-')
		p = -1,
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s * p;
}
ll a[300000], s = 0, ans = 0;
int main()
{
	bool p = 1;
	ll n = rd(), t = rd(), anst;
	rep (i, 1, n)
		a[i] = rd(),
		s += a[i];
	ans = (t / s) * n;
	t %= s;
	while (true)
	{
		s = 0;
		p = 1;
		anst = 0;
		rep (i, 1, n)
			if (a[i] <= t)
				p = 0,
				t -= a[i],
				++anst,
				++ans,
				s += a[i];
		if (p)	
			break;
		ans += (t / s) * anst;
		t %= s;
	}	
	pfl(ans);
	return 0;
}

