#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
using namespace std;
typedef pair<int, int> P;
vector<P> land;
vector<int> x, y;
typedef pair<int, int> P;
const int MAXN = 50005;
P qu[MAXN], t;
int l, r;
signed main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		cin >> x >> y;
		land.push_back(P(x, y));
	}
	sort(land.begin(), land.end());
	for (auto it = land.begin(); it != land.end(); ++it)
	{
		while (x.size() && it->second >= *y.rbegin())
			x.pop_back(), y.pop_back();
		x.push_back(it->first), y.push_back(it->second);
	}
	y.push_back(0);
	n = x.size();
	l = r = 0;
	int ans;
	qu[r++] = P(-y[0], 0);
	for (int i = 0; i < n; ++i)
	{
		while (r - l > 1 && (qu[l + 1].second - qu[l].second) <= (qu[l + 1].first - qu[l].first) * (x[i]))
			++l;
		ans = qu[l].second - qu[l].first * x[i];
		t.first = -y[i + 1], t.second = ans;
		while (r - l > 1 && (t.second - qu[r - 1].second) * (qu[r - 1].first - qu[r - 2].first) <= (t.first - qu[r - 1].first) * (qu[r - 1].second - qu[r - 2].second))
			--r;
		qu[r++] = t;
		// cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}