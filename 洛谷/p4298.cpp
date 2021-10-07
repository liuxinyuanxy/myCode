#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2000;
const int MOD = 31011;
struct edge
{
	int u, v, w;
};
struct point
{
	vector<edge>::iterator l, r;
	int val, ned;
} P[MAXN];
int tot;
vector<edge> E;
bool cmp(const edge &x, const edge &y)
{
	return x.w < y.w;
}
int fa[MAXN];

int find(int x)
{
	return fa[x] == x ? x : find(fa[x]);
}
void kruskal(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (auto it = E.begin(); it != E.end(); ++it)
	{
		if (it->w == P[tot].val)
			P[tot].r = it;
		else
			++tot, P[tot].l = P[tot].r = it, P[tot].val = it->w;
		int x = find(it->u), y = find(it->v);
		if (x != y)
			fa[x] = y, ++P[tot].ned, ++sum;
	}
	if (sum != n - 1)
	{
		printf("0\n");
		exit(0);
	}
}
int dfs(vector<edge>::iterator it, int cnt, int k)
{
	if (it == P[k].r + 1)
		return int(cnt == P[k].ned);
	int ans = 0;
	int x = find(it->u), y = find(it->v);
	if (x != y)
	{
		fa[x] = y;
		ans += dfs(it + 1, cnt + 1, k);
		fa[x] = x;
	}
	ans += dfs(it + 1, cnt, k);
	return ans % MOD;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back(edge{u, v, w});
	}
	sort(E.begin(), E.end(), cmp);
	kruskal(n);
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= tot; ++i)
	{
		ans *= dfs(P[i].l, 0, i);
		ans %= MOD;
		for (auto it = P[i].l; it <= P[i].r; ++it)
		{
			int x = find(it->u), y = find(it->v);
			fa[x] = y;
		}
	}
	cout << ans << endl;
	return 0;
}