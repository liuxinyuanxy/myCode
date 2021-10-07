#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define gc getchar
using namespace std;
const signed MOD = 19260817;
const signed MAXN = 300000;
long long lst[MAXN];
signed len[MAXN];
vector<signed> v[MAXN];
vector<signed> hs;
struct qu{
	int x, y, z;
}que[MAXN];
int rd()
{
	int s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * (p ? -1 : 1);
}
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= p ? -1 : 1;
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
long long ans = 0;
signed main()
{
	//9630409
	int n, m, t, tot;
	rd(n, m);
	for (int i = 1; i <= n; ++i)
		v[i].push_back(rd());
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= v[i][0]; ++j)
		{
			rd(t);
			v[i].push_back(t);
			hs.push_back(t);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		rd(que[i].x, que[i].y, que[i].z);
		hs.push_back(que[i].z);
	}
	sort(hs.begin(), hs.end());
	tot = unique(hs.begin(), hs.end()) - hs.begin();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= v[i][0]; ++j)
		{
			v[i][j] = lower_bound(hs.begin(), hs.begin() + tot, v[i][j]) - hs.begin() + 1;
		}
	}
	for (int i = 1; i <= m; ++i)
		que[i].z = lower_bound(hs.begin(), hs.begin() + tot, que[i].z) - hs.begin() + 1;
	set<int> S[n + 1][tot + 1];
	long long ans[n + 1][tot + 1];
	ans[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= v[i][0]; ++j)
		{
			// cout << v[i][j] << " ";
			S[i][v[i][j]].insert(j);
			int k;
			if (lst[v[i][j]] / 1000000ll != i)
			{
				k = j - 1;
			}
			else
			{
				k = j - (lst[v[i][j]] - i * 1000000ll) - 1;
			}
			ans -= (k * 9630409ll * (k - 1)) % MOD;
			ans %= MOD;
			lst[v[i][j]] = i * 1000000ll + j;
			// cout << i << " " << j << endl;
		}
	}
	printf("%d", ans);
	return 0;
}