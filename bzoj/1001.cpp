#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 2000005
#define MAXM 6000015
using namespace std;
int q[MAXN];
int l, r;
int head[MAXN], nxt[MAXM], ret[MAXM], to[MAXM];
int dis[MAXN];
int tot = 1;
int n, m;
inline void add(int a, int b, int c)
{
	++tot;
	nxt[tot] = head[a];
	to[tot] = b;
	ret[tot] = c;
	head[a] = tot;
	++tot;
	nxt[tot] = head[b];
	to[tot] = a;
	ret[tot] = c;
	head[b] = tot;
	return;
}
bool bfs()
{
	l = r = 0;
	int t;
	memset(dis, 0, sizeof(dis));
	q[r++] = 1;
	while (l != r)
	{
		t = q[l++];
		for (int i = head[t]; i; i = nxt[i])
		{
			if (ret[i] > 0 && !dis[to[i]] && to[i] != 1)
			{
				dis[to[i]] = dis[t] + 1;
				if (to[i] == n * m)
					return true;
				q[r++] = to[i];
			}
		}
	}
	return false;
}
int dfs(int u, int maxf)
{
	if (u == n * m)
		return maxf;
	int ans = 0;
	for (int i = head[u]; i && ans < maxf; i = nxt[i])
	{
		if (!ret[i] || dis[to[i]] != dis[u] + 1)
			continue;
		int temp = dfs(to[i], min(ret[i], maxf - ans));
		ret[i] -= temp;
		ret[i ^ 1] += temp;
		ans += temp;
	}
	if (!ans)
		dis[u] = -2;
	return ans;
}
int main()
{
	int t;
	int ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
		{
			scanf("%d", &t);
			add((i - 1) * m + j, (i - 1) * m + j + 1, t);		
		}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &t);
			add((i - 1) * m + j, i * m + j, t);		
		}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
		{
			scanf("%d", &t);
			add((i - 1) * m + j, i * m + j + 1, t);		
		}
	while (bfs())
	{
		ans += dfs(1, 0x7fffffff);
	}
	printf("%d", ans);
	return 0;
}
