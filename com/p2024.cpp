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
#define MAXN 6000000
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int fa[MAXN];
il int f(rt x)
{
	return x == fa[x] ? x : fa[x] = f(fa[x]);
}
il void merge(rt x, rt y)
{
	x = f(x),
	y = f(y);
	if (x != y)
		fa[x] = y;
}
il bool same(rt x, rt y)
{
	x = f(x), y = f(y);
	return x == y;
}
int main()
{
	int ans = 0;
	int n, k, p, a, b;
	sf2(n, k);
	rep (i, 1, 3 * n)
		fa[i] = i;
	rep (i, 1, k)
	{
		sf(p),
		sf2(a, b);
		if (a > n || b > n)
		{
			++ans;
			continue;
		}
		if (p == 1)
		{
			if (same(a, b + n) || same(a + n, b + n + n)
			  ||same(a + n + n, b) || same(b, a + n) ||
			    same(b + n, a + n + n) || same(b + n + n, a))
			    ++ans;
			else
				merge(a, b),
				merge(a + n, b + n),
				merge(a + n + n, b + n + n);
		}
		else
		{
			if (same(a, b) || same(a + n, b + n) || same(a + n + n, b + n + n)||
				same(b, a + n) || same(b + n, a + n + n) || same(b + n + n, a))
				++ans;
			else
				merge(a, b + n),
				merge(a + n, b + n + n),
				merge(a + n + n, b);
		}
	}
	pf(ans);
	return 0;
}

