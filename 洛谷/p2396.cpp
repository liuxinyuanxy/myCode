// #pragma GCC optimize(3, "Ofast", "inline")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define il inline
#define re
#define gc getchar
#define LL long long
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> PP;
// __gnu_pbds::gp_hash_table<P, int> hs;
// __gnu_pbds::gp_hash_table<PP, int> hs2;
map<__int128_t, int> hs;
map<__int128_t, int> hs2;
il __int128_t modify(re P x)
{
	re __int128_t w = 0;
	w = x.first;
	w = (w << 32) + x.second;
	return w;
}
il __int128_t modify(re PP x)
{
	re __int128_t w = 0;
	w = x.first.first;
	w = (w << 32) + x.first.second;
	w = (w << 32) + x.second.first;
	w = (w << 32) + x.second.second;
	return w;
}
const int MOD = 1000000007;
int a[30];
int f[30];
int n, mid;
namespace part1
{
int unlucky;
int t_ans;
void dfs_l(re int d, re int sum, re int c)
{
	if (d > mid)
		return;
	if (sum > unlucky)
		return;
	++hs[modify(P(sum + a[d], c + 1))];
	dfs_l(d + 1, sum + a[d], c + 1);
	dfs_l(d + 1, sum, c);
}
il void zero()
{
	t_ans = 0;
	++hs[modify(P(0, 0))];
	for (int i = 1; i <= mid; ++i)
		t_ans = (t_ans + hs[modify(P(unlucky, i))] * 1ll * f[i] % MOD * f[n - i] % MOD) % MOD;
}
void dfs_r(re int d, re int sum, re int c)
{
	if (d > n)
		return;
	if (sum > unlucky)
		return;
	for (re int i = 0; i <= mid; ++i)
		// printf("%d\n", t_ans), // if (hs.find(P(unlucky - sum - a[d], i)) != hs.end())
		t_ans = (t_ans + hs[modify(P(unlucky - sum - a[d], i))] * 1ll * f[i + c + 1] % MOD * 1ll * f[n - i - c - 1] % MOD) % MOD;
	dfs_r(d + 1, sum + a[d], c + 1);
	dfs_r(d + 1, sum, c);
}
} // namespace part1
namespace part2
{
int un1, un2;
int t_ans;
void dfs_l(re int d, re int sum1, re int c1, re int sum2, re int c2)
{
	if (d > mid)
		return;
	if (sum1 > un1)
		return;
	if (sum1 + sum2 > un2)
		return;
	++hs2[modify(PP(P(sum1 + a[d], c1 + 1), P(sum2, c2)))];
	dfs_l(d + 1, sum1 + a[d], c1 + 1, sum2, c2);
	++hs2[modify(PP(P(sum1, c1), P(sum2 + a[d], c2 + 1)))];
	dfs_l(d + 1, sum1, c1, sum2 + a[d], c2 + 1);
	dfs_l(d + 1, sum1, c1, sum2, c2);
}
il int get(re int sum1, re int c1, re int sum2, re int c2)
{
	if (sum1 > un1)
		return 0;
	if (sum1 + sum2 > un2)
		return 0;
	re int t = 0;
	for (re int i = 0; i <= mid; ++i)
		for (re int j = 0; j <= mid; ++j)
			t = (t + hs2[modify(PP(P(un1 - sum1, i), P(un2 - un1 - sum2, j)))] * 1ll * f[i + c1] % MOD * f[j + c2] % MOD * f[n - i - c1 - j - c2] % MOD) % MOD;
	return t;
}
il void zero()
{
	++hs2[modify(PP(P(0, 0), P(0, 0)))];
	t_ans = get(0, 0, 0, 0);
}
void dfs_r(re int d, re int sum1, re int c1, re int sum2, re int c2)
{
	if (d > n)
		return;
	if (sum1 > un1)
		return;
	if (sum1 + sum2 > un2)
		return;
	t_ans = (t_ans + get(sum1 + a[d], c1 + 1, sum2, c2)) % MOD;
	dfs_r(d + 1, sum1 + a[d], c1 + 1, sum2, c2);
	t_ans = (t_ans + get(sum1, c1, sum2 + a[d], c2 + 1)) % MOD;
	dfs_r(d + 1, sum1, c1, sum2 + a[d], c2 + 1);
	dfs_r(d + 1, sum1, c1, sum2, c2);
}
} // namespace part2
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	mid = n >> 1;
	mid = min(n, mid + 3);
	f[0] = 1;
	for (re int i = 1; i <= n; ++i)
		f[i] = (f[i - 1] * 1ll * i) % MOD;
	for (re int i = 1; i <= n; ++i)
		cin >> a[i];
	re int k, ans;
	cin >> k;
	if (k == 0)
		ans = f[n];
	else if (k == 1)
	{
		cin >> part1::unlucky;
		part1::dfs_l(1, 0, 0);
		part1::zero();
		part1::dfs_r(mid + 1, 0, 0);
		ans = (f[n] - part1::t_ans) % MOD;
	}
	else
	{
		re int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		part1::unlucky = x;
		part1::dfs_l(1, 0, 0);
		part1::zero();
		part1::dfs_r(mid + 1, 0, 0);
		ans = (f[n] - part1::t_ans) % MOD;
		hs.clear();
		part1::unlucky = y;
		part1::dfs_l(1, 0, 0);
		part1::zero();
		part1::dfs_r(mid + 1, 0, 0);
		ans = (ans - part1::t_ans) % MOD;
		part2::un1 = x, part2::un2 = y;
		cout << 1 << endl;
		part2::dfs_l(1, 0, 0, 0, 0);
		part2::zero();
		cout << 2 << endl;
		part2::dfs_r(mid + 1, 0, 0, 0, 0);
		cout << 3 << endl;
		ans = (ans + part2::t_ans) % MOD;
	}
	if (ans < 0)
		ans += MOD;
	cout << ans << endl;
	return 0;
}