#include <iostream>
#include <algorithm>
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
#define mid(x, y) ((x) + (y) >> 1)
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
#define MAX 200000
using namespace std;
int h[MAX];
int l0, l1;
int g0[MAX], g1[MAX]; // g0[i]: 长度为i的结尾递减的最小的 
int main()			  // g1[i]: 长度为i的结尾递增的最大的 
{
	rt n;
	sf(n);
	rep(i, n, 1)
		sf(h[i]);
	l0 = l1 = 1;
	g0[1] = g1[1] = h[1];
	rep(i, n, 1)
	{
		if (h[i] > g0[l0])
			
	}
	return 0;
}

