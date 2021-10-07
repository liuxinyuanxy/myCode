#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define _ 300000
#define mp make_pair
using namespace std;
typedef pair<int, int> p;
vector<p> v[_];
int cnt[_];
int frm[_], to[_], du[_];
p vis[_];
signed main()
{
	int n, m;
	while (scanf("%lld%lld", &n, &m) != EOF)
	{
		long long ans = 0;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%lld%lld", &frm[i], &to[i]);
			++du[frm[i]];
			++du[to[i]];
		}
		for (int i = 1; i <= m; ++i)
		{
			if (du[frm[i]] < du[to[i]] || (du[frm[i]] == du[to[i]] && frm[i] > to[i]))
				swap(frm[i], to[i]);
			v[frm[i]].push_back(mp(to[i], i));
		}
		for (int i = 1; i <= n; ++i)
		{
			for (auto j : v[i])
				vis[j.first] = mp(i, j.second);
			for (auto j : v[i])
				for (auto k : v[j.first])
					if (vis[k.first].first == i)
					{
						++cnt[vis[k.first].second];
						++cnt[vis[j.first].second];
						++cnt[k.second];
					}
		}
		for (int i = 1; i <= m; ++i)
		{
			if (cnt[i])
				ans += (cnt[i] * (cnt[i] - 1)) / 2;
		}
		cout << ans << endl;
		for (int i = 1; i <= n; ++i)
		{
			du[i] = 0;
			vis[i] = mp(0, 0);
			v[i].clear();
		}
		for (int i = 1; i <= m; ++i)
			cnt[i] = 0;
	}
	return 0;
}