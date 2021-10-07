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
#define sqr(x) ((x) * (x))
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
ll a[20][2050];
int two[20];
bool check(rt x, rt c)
{
	rt lst = 0;
	for (rt i = 1; x; x >>= 1, ++i)
		if (x & 1)
		{
			if (((i - 1- lst) & 1))
				return true;
			else
				lst = i;
		}
	return ((c - lst) & 1);
}
int main()
{
	rt h, w;
	two[0] = 1;
	rep (i, 1, 12)
		two[i] = two[i - 1] << 1;
	while (sf2(h, w), h + w != 0)
	{
		a[0][0] = 1;
		rep (i, 1, h)
			rep (j, 0, two[w] - 1)
				a[i][j] = 0;
		rep (i, 1, h)
			rep (j, 0, two[w] - 1)
				rep (k, 0, two[w] - 1)
				{
					if ((j & k) || check((j | k), w))
						continue;
					a[i][j] += a[i - 1][k];	
				}
		pfl (a[h][0]);
		putchar('\n');			
	}
	return 0;
}

