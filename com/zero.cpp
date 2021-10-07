#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
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
#define selfmin(x, y) (x) = min((x), (y))
#define mid(x, y) ((x) + (y) >> 1)
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
int n;
typedef set<int>::iterator SI;
int g[6][400];
set<int> ans[3];
int main()
{
//	freopen("zero.in", "r", stdin);
//	freopen("zero.out", "w", stdout);
	rt s1 = 0, s2 = 0, p;
	sf(n);
	rep(i, 5, 1)
	{
		rep(j, n, 1)
		{
			sf(g[i][j]);
		}
	}
	rep(i, n, 1)
		rep(j, n, 1)
			ans[0].insert(g[1][i] + g[2][j]);
	rep(i, n, 1)
		rep(j, n, 1)
			ans[1].insert(g[3][i] + g[4][j]);
	s1 = ans[0].size(), s2 = ans[1].size();
	p = s1 < s2 ? 0 : 1;
	if (s1 > s2)
		swap(s1, s2);
	for (re SI x = ans[p].begin(); x != ans[p].end(); ++x)
		rep(j, n, 1)
			ans[2].insert(*x + g[5][j]);
	p = !p;
	for (re SI x = ans[p].begin(); x != ans[p].end(); ++x)
	{
//		for (re SI y = ans[2].begin(); y != ans[2].end(); ++y)
//			if (*x + *y == 0)
//			{
//				printf("YES");
//				return 0;	
//			}
		SI ss = ans[2].lower_bound(-(*x));
		if (*ss == -(*x))
		{
			printf("YES");
			return 0;	
		}	
	}	
	printf("NO");
	return 0;
}

