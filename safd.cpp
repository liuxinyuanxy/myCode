#include <cstdio>
#include <vector>
#include <iostream>
#define MOD 19260817
using namespace std;
int c;
long long ans = 0;
bool vis[20];
long long hs[20][20];
vector<int> to[20];
long long ddd[20];
int n, k;
void dfs(int i, bool sum, bool l, long long aaa)
{
//	if (ddd[i])
//	{
//		ans += aaa * ddd[i] % MOD;
//		ans %= MOD;
//		return;
//	}
	if (i == n)
	{
		if (l == c)
			ans += aaa;
		ans %= MOD;
		return ;
	}
	for (auto x : to[i])
	{
		if (!vis[x])
		{
			vis[x] = 1;
			hs[i][x] %= MOD;
			dfs(x, (sum + x) & 1, ((sum && (x & 1)) + l) & 1, aaa * hs[i][x] % MOD);
			vis[x] = 0;
//			ddd[i] += ddd[x] * hs[i][x] % MOD;
//			ddd[i] %= MOD;
		}
	}
}
int main()
{
//	freopen("in.txt", "r", stdin);
	int u, v;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d%d", &u, &v);
		if (u == v)
			continue; 
		if (hs[u][v] >= 1)
		{
			++hs[u][v];
			++hs[v][u];
			if (hs[u][v] == MOD + 1)
				hs[u][v] = hs[v][u] = 1;
			continue;
		}
		hs[u][v] = hs[v][u] = 1;
		to[u].push_back(v);
		to[v].push_back(u);
	}
//	ddd[n] = 1;
	scanf("%d", &c);
	vis[1] = 1;
	dfs(1, 1, 0, 1);
	printf("%lld", ans % MOD);
	return 0;
}
