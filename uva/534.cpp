#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
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
#define sqr(x) ((x) * (x))
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
double maxDis[300];
pii point[1000];
bool vis[1000];
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il double dis(const pii& a, const pii& b)
{
	return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}
typedef pair<double, pii> pdp;
priority_queue<pdp, vector<pdp>, greater<pdp> > pq;
pdp now;
int main()
{
	rt n, tmp, tot = 0;
	while (n = rd(), n != 0)
	{
		rep (i, 1, n)
			point[i].first = rd(),
			point[i].second = rd(),
			vis[i] = 0,
			maxDis[i] = 0;
		pq.push(mp(0, mp(1, 1)));
		rep (i, 2, n)
			pq.push(mp(dis(point[1], point[i]), mp(i, 1)));
		while (!pq.empty())
		{
			now = pq.top();
			pq.pop();
			tmp = now.second.first;
			if (vis[tmp])
				continue;
			maxDis[tmp] = max(maxDis[now.second.second], now.first);
			vis[tmp] = 1;
			rep (i, 1, n)
				if (!vis[i])
					pq.push(mp(dis(point[tmp], point[i]), mp(i, tmp)));
		}
		printf("Scenario #%d\nFrog Distance = ", ++tot);
		printf("%.3lf\n\n", maxDis[2]);
	}
	return 0;
}

