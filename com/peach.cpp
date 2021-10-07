#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
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
#define MOD 100000000
#define m_p make_pair
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int a[1005][1005];
map<pii, int> MMP;
pii point[10005], temp;
ll c(rt n, rt m)
{
	if (n == 0 || n == m)
		return 1;
	temp = m_p(n, m);
	if (MMP[temp])
		return MMP[temp];
	return MMP[temp] = jia(c(n - 1, m - 1), c(n, m - 1));
}
il ll check(rt n, rt m)
{
	return c(n, m + n) % MOD;
}
int main()
{
	ll ans;
	rt n, m, k;
	sf2(n, m);
	sf(k);
	rep (i, 1, k)
		sf2(point[i].first, point[i].second);
	++k;
	point[k].first = n;
	point[k].second = m;
	
	for (rt i = 0; i <= 500; ++i)
	{
		for (rt j = 0; j <= i; ++j)
		{
			if (j == 0 || i == j)
				a[j][i] = 1;
			else
				a[j][i] = a[j][i - 1] + a[j - 1][i - 1];
			temp = m_p(j, i);
			MMP[temp] = a[j][i];
		}
	}
	sort (point + 1, point + 1 + k);
	ans = check(point[1].first - 1, point[1].second - 1);
	rep (i, 2, k)
	{
		if (point[i].first >= point[i - 1].first && point[i].second < point[i - 1].second)
		{
			printf("0");
			return 0;
		}
		selfcheng(ans, check(point[i].first - point[i - 1].first, point[i].second - point[i - 1].second));
	}
	pfl(ans);
	return 0;
}

