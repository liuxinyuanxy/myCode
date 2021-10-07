#include <iostream>
#include <cstdio>
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
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
ll Bit[100];
ll two[100];
il ll rd()
{
	ll s = 0;
	rc ch = gc();
	while (ch < '0' || ch > '9')
		ch = gc();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = gc();
	return s;
}
il void change(rll x)
{
	for (rt i = 62; i >= 0; --i)
		if (x & two[i])
		{
			if (!Bit[i])
			{
				Bit[i] = x;
				return;
			}
			else
				x ^= Bit[i];
		}
}
int main()
{
	ll ans = 0;
	ll n;
	sfl(n);
	two[0] = 1;
	rep (i, 1, 62)
		two[i] = two[i - 1] << 1;
	rep (i, 1, n)
		change(rd());
	for (rt i = 62; i >= 0; --i)
		if ((ans ^ Bit[i]) > ans)
			ans ^= Bit[i];
	pfl(ans);
	return 0;
}

