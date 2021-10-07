#include <iostream>
#include <cstdio>
#include <map>
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
int pri[2000005], vis[2000005];
int ans[2000005];
map<int, int> id;
int cnt, tot;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n;
	sf(n);
	vis[1] = 1;
	rep (i, 2, 1000159)
	{
		if (!vis[i])
		{
			pri[++cnt] = i;
			id[i] = cnt;
			if (!vis[cnt])
				ans[++tot] = i;
		}
		for (rt j = 1; j <= cnt && pri[j] * i <= 1000159; ++j)
		{
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	rt l = 1, r = tot, m;
	while (l != r)
	{
		m = mid(l, r);
		if (ans[m] >= n)
			r = m;
		else
			l = m + 1;
	}
	pf (ans[l]);
	return 0;
}

