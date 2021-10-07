#include <iostream>
#include <cstdio>
#include <algorithm>
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
pii edge[500000];
int point[1000000];
int del[500000];
int main()
{
	int n, k, tot = 0, ans = 0, t = 0;
	char ch;
	int x = 0, mv;
	cin >> n >> k;
	rep (i, 1, n)
	{
		cin >> mv;
		cin >> ch;
		if (ch == 'R')
		{
			point[++tot] = edge[i].first = x;
			point[++tot] = edge[i].second = x = x + mv;
		}
		else
		{
			point[++tot] = edge[i].second = x;
			point[++tot] = edge[i].first = x = x - mv;
		}
	}
	sort(point + 1, point + 1 + tot);
	tot = unique(point + 1, point + 1 + tot) - point - 1;
	rep (i, 1, n)
		++del[lower_bound(point + 1, point + 1 + tot, edge[i].first) - point],
		--del[lower_bound(point + 1, point + 1 + tot, edge[i].second) - point];
	rep (i, 1, tot - 1)
	{
		t += del[i];
		if (t >= k)
		{
//			cout << point[i + 1] << "\t" << point[i] << endl;
			ans += (point[i + 1] - point[i]);
//			cout << t << "\t" << i << "\t" << ans << endl;
		}
	}
	pf(ans);
	return 0;
}

