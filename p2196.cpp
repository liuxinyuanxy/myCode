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
int a[50];
int g[50];
int n;
int gra[50][50];
int nxt[50];
int ans = 0, from;
int main()
{
	sf(n);
	rep (i, 1, n)
		sf(a[i]);
	rep (i, 1, n)
		rep (j, i + 1, n)
			sf(gra[i][j]);
	ans = g[n] = a[n];
	from = n;
	nxt[n] = 0;
	for (rt i = n - 1; i >= 1; --i)
	{
		rep (j, i + 1, n)
		if (gra[i][j])
		{
			if (g[j] > g[i])
				nxt[i] = j,
				g[i] = g[j];	
		}
		g[i] += a[i];
		if (g[i] > ans)
			ans = g[i],
			from = i;
	}
	for (rt x = from; x; x = nxt[x])
		pf(x),
		putchar(' ');
	putchar('\n');
	pf(ans);
	return 0;
}

