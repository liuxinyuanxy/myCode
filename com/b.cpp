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
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int tot;
int a[10000000];
void run(rll x)
{
	if (x == 1)
		return;
	register bool p = 1;
	rll to = sqrt(x);
	rep (i, 2, to)
	{
		if (x % i == 0)
		{
			p = 0;
			a[++tot] = 1;
			x /= i;
			while (x % i == 0)
				++a[tot],
				x /= i;
		}	
	}
	if (p)
		a[++tot] = 1;
	else
		run(x);
}
int main()
{
	ll b, ans = 1;
	cin >> b;
	if (b == 1)
	{
		cout << 1;
		return 0;
	}
	run(b); 
	rep (i, 1, tot)
		ans *= (a[i] + 1);
	cout << ans;
	return 0;
}

