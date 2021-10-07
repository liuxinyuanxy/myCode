#include <algorithm>
#include <iostream>
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
#define jia(a, b) (((a) + (b) + MOD) % MOD)
#define jian(a, b) (((a) - (b) + MOD) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b) + MOD) % MOD
#define selfjian(a, b) (a) = ((a) - (b) + MOD) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) ((x) + (y) >> 1)
#define MOD 100007
#define INF 100007
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
#define rep2(x, a, b) for (rt (x) = 0; (x) <= (a); (x) += (b))
using namespace std;
int tree[INF][20][2];
int dp[50055][20][2];
int n;
pii point[50055];
bool cmp(pii a, pii b)
{
	return a.first < b.first;
}
il int lowbit(rt x)
{
	return x & -x;
}
il void add(rt x, rt s, rt k, rt p)
{
	while (x < INF)
		selfjia(tree[x][k][p], s),
		x += lowbit(x);
}
il int query(rt x, rt k, rt p)
{
	rt s = 0;
	while (x)
		selfjia(s, tree[x][k][p]),
		x -= lowbit(x);
	return s;
}
int main()
{
	int k;
	rt ans = 0;
	sf2(n, k);
	rep(i, n, 1)
		sf2(point[i].first, point[i].second);
	sort(point + 1, point + 1 + n, cmp);
	rep(i, n, 1)
	{
//		cout << point[i].first << "\t" << point[i].second << endl;
		dp[i][0][1] = dp[i][0][0] = 1;
	}
	rep2(j, k, 1)
	{
//		cout << endl;
		rep(i, n - 1, 1)
		{
//			cout << j << "\t" << i << endl;
//			cout << i << "\t" << j << "\t" << dp[i][j][0] << "\t" << dp[i][j][1] << endl;
			add(point[i].second, dp[i][j][0], j, 0);
			add(point[i].second, dp[i][j][1], j, 1);
			if (j)selfjia(dp[i + 1][j][0], query(point[i + 1].second - 1, j, 0));
			selfjia(dp[i + 1][j + 1][1], query(INF - 5, j, 0) - query(point[i + 1].second, j, 0));
			selfjia(dp[i + 1][j + 1][0], query(point[i + 1].second - 1, j, 1));
			if (j)selfjia(dp[i + 1][j][1], query(INF - 5, j, 1) - query(point[i + 1].second, j, 1));
//			dp[i][j][0] = jia(, query(point[i].second - 1, j - 1, 1));
//			dp[i][j][1] = jia(query(INF, j, 1) - query(point[i].second, j, 1), query(INF, j - 1, 0) - query(point[i].second, j - 1, 0));
		}
	}
//	rep2(j, k, 1)
//		rep(i, n, 1)
//			cout << i << "\t" << j << "\t" << dp[i][j][0] << "\t" << dp[i][j][1] << endl;
	rep(i, n, 1)
		selfjia(ans, jia(dp[i][k][0], dp[i][k][1]));
	pf(k ? ans : ans / 2);
	return 0;
}
