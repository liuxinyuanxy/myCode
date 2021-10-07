#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int MAXN = 60000;
int h[MAXN], maxh;
int dp[MAXN];
typedef pair<int, int> P;
P qu[MAXN], t;
int l, r;
signed main()
{
	ios::sync_with_stdio(0);
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
		maxh = max(maxh, h[i]);
	}
	for (int i = h[1]; i <= maxh; ++i)
		dp[i] = (i - h[1]) * (i - h[1]);
	for (int i = 2; i <= n; ++i)
	{
		int minl = 0x7ffffffffffffff;
		l = r = 0;
		for (int j = h[i - 1]; j <= maxh; ++j)
		{
			t.first = j, t.second = dp[j] + j * c;
			while (l < r && qu[r - 1].second > t.second)
				--r;
			qu[r++] = t;
		}
		for (int j = h[i - 1]; j < h[i]; ++j)
			minl = min(minl, dp[j] - j * c);
		for (int j = h[i]; j <= maxh; ++j)
		{
			while (l < r && qu[l].first < j)
				++l;
			if (j >= h[i - 1])
				minl = min(minl, dp[j] - j * c);
			dp[j] = min(j * c + minl, -j * c + qu[l].second) + (j - h[i]) * (j - h[i]);
		}
	}
	int ans = 0x7ffffffffffffff;
	for (int i = h[n]; i <= maxh; ++i)
		ans = min(ans, dp[i]);
	cout << ans << endl;
}