#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct EDGE{
	int u, v, w;
}edge[2000];
int fa[300], n, m;
bool cmp(const EDGE& x, const EDGE& y)
{
	return x.w < y.w;
}
int find_root(int x)
{
	return x == fa[x] ? x : fa[x] = find_root(fa[x]);
}
bool same(int x, int y)
{
	x = find_root(x),
	y = find_root(y);
	return x == y;
}
bool merge(int x, int y)
{
	x = find_root(x),
	y = find_root(y);
	fa[x] = y;
	return x != y;
}
int kru(int u, int v)
{
	int ans = 0x3fffffff;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
			fa[j] = j;
		for (int j = i; j <= m; ++j)
			if (merge(edge[j].u, edge[j].v) && same(u, v))
				ans = min(ans, edge[j].w - edge[i].w);
	}
	return ans;
}
int main()
{
	int u, v, w, ans, k;
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			edge[i] = {u, v, w};
		}
		sort(edge + 1, edge + 1 + m, cmp);
		scanf("%d%d", &u, &v);
		ans = u + v;
		scanf("%d", &k);
		for (int i = 1; i <= k; ++i)
		{
			scanf("%d%d", &u, &v);
			printf("%d\n", ans + kru(u, v));
		}
	}
	return 0;
}
