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
#define INF 0x7fffffffffffffff
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
ll dis[105][105];
int main()
{
//	freopen("gouliang.in", "r", stdin);
//	freopen("gouliang.out", "w", stdout);
	rt c, s, q, x, y;
	rll d, cnt = 0;
	while (sf2(c, s), sf(q), c + s + q != 0)
	{
		rep (i, 1, c)
			rep (j, 1, c) 
				dis[i][j] = i == j ? 0 : INF;
		rep (i, 1, s)
		{
			sf2(x, y);
			sfl(d);
			dis[x][y] = dis[y][x] = d;
		}
		rep (k, 1, c)
			rep (i, 1, c)
				rep (j, 1, c)
					dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
		printf("Case #%lld\n", ++cnt);
		rep (i, 1, q)
		{
			sf2(x, y);
			dis[x][y] == INF ? printf("no path") : pfl(dis[x][y]);
			putchar('\n');
		}		
	}
	return 0;
}

