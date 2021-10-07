#include <iostream>
#include <cstdio>
#define gc getchar
using namespace std;
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
const int MOD = 1000000007;
const int MAXN = 200005;
int a[MAXN];
int cnt = 0, cir, tot = 0;
int dis[MAXN];
int vis[MAXN];
void dfs(int u)
{
	vis[u] = ++tot;
	dis[u] = ++cnt;
	while (!dis[a[u]])
	{
		u = a[u];
		dis[u] = ++cnt;
		vis[u] = tot;
	}
	if (vis[a[u]] != tot)
		return;
	else
		cir = dis[u] - dis[a[u]] + 1;
}
long long qpow(long long a, long long b)
{
	long long ans = 1;
	for (; b; b >>= 1, a = (a * a) % MOD)
		if (b & 1)
			ans = (ans * a) % MOD;
	return ans;
}
int main()
{
	int n;
	long long s = 0, ans = 1;
	rd(n);
	for (int i = 1; i <= n; ++i)
	{
		rd(a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!dis[i])
		{
			dfs(i);
			if (cir)
			{
				s += cir;
				ans *= (qpow(2, cir) - 2);
				ans %= MOD;
				cir = 0;
			}
		}
	}
	ans *= qpow(2, n - s);
	ans %= MOD;
	printf("%lld", ans);
	return 0;
}