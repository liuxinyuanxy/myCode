#include <iostream>
#include <bitset>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, u) printf("%d %d", x, y)
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
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
bitset<1000005> B;
int a[1000005];
int n, k, ma;
bool check(rt mm)
{
	rt kk = k;
	B = 0;
	rep(i, n, 1)
	{
		if (!B[(a[i] % mm)])
		{
			B[(a[i] % mm)] = 1;
		}
		else
		{
			if (kk)
				--kk;
			else
				return false;
		}
	}
	return true;
}
int main()
{
	sf2(n, k);
	ma = 0;
	rep(i, n, 1)
	{
		sf(a[i]);
		ma = max(ma, a[i]);
	}
	rep(i, ma + 1, 1)
		if (check(i))
		{
			pf(i);
			return 0;
		}
	return 0;
}

