#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int MAXN = 600000;
typedef pair<int, int> P;
int dp[MAXN], s[MAXN];
P qu[MAXN], t;
int l, r;
signed main()
{
	int n, m;
	// freopen("data.in", "r", stdin);
	// freopen("my.out", "w", stdout);
	while (~scanf("%lld%lld", &n, &m))
	{
		l = r = 0;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			scanf("%lld", &x);
			s[i] = s[i - 1] + x;
		}
		qu[r++] = P(0, 0);
		for (int i = 1; i <= n; ++i)
		{
			while (r - l > 1 && (qu[l + 1].second - qu[l].second) <= (qu[l + 1].first - qu[l].first) * 2 * s[i])
				++l;
			dp[i] = qu[l].second - 2 * s[i] * qu[l].first + s[i] * s[i] + m;
			t.first = s[i], t.second = dp[i] + s[i] * s[i];
			while (r - l > 1 && (t.second - qu[r - 1].second) * (qu[r - 1].first - qu[r - 2].first) <= (qu[r - 1].second - qu[r - 2].second) * (t.first - qu[r - 1].first))
				--r;
			qu[r++] = t;
			// printf("%lld\n", dp[i]);
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}