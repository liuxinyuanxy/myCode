#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf("%lld", &x)
#define sfl2(x, y) scanf("%lld%lld", &x, &y)
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
#define rep(x, a, b) for (rt(x) = (a); (x) <= (b); ++(x))
using namespace std;
ll a[10][100][2000];
int two[11], count[2000];
int n, m;
il int cou(rt k)
{
	rt s = 0;
	for (; k; k >>= 1)
		if (k & 1)
			++s;
	return s;
}
il bool check(rt x)
{
	return (x & (x << 1)) || (x & (x >> 1));
}
int main()
{
	ll ans = 0;
	sf2(n, m);
	two[0] = 1;
	rep(i, 1, 10)
		two[i] = two[i - 1] << 1;

	rep(k, 0, two[n] - 1)
		count[k] = cou(k);
	a[0][0][0] = 1;
	rep(i, 1, n)
		rep(j, 0, m)
			rep(k, 0, two[n] - 1)
	{
		if (count[k] > j)
			continue;
		rep(l, 0, two[n] - 1)
		{
			if (count[l] + count[k] > j || k & l || check(k | l))
				continue;
			a[i][j][k] += a[i - 1][j - count[k]][l];
		}
	}
	rep(k, 0, two[n] - 1)
		ans += a[n][m][k];
	pfl(ans);
	return 0;
}
