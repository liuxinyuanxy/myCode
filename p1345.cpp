#include <iostream>
#include <cstring>
#include <cstdio>
#define tx to[x]
#define MAX 8000
#define INF 0x7fffffff
using namespace std;
int nxt[MAX], head[MAX], to[MAX], ret[MAX];
int dis[MAX];
int qu[MAX], l, r;
int n, m;
int s, t;
int tot = 1;
inline void add(int u, int v, int w)
{
	++tot;
	nxt[tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	ret[tot] = w;
}
bool bfs()
{
	l = r = 0;
	memset(dis, 0, (sizeof(int) * 2 * (n + 1)));
	int now;
	qu[r++] = s;
	dis[s] = 1;
	while (l != r)
	{
		now = qu[l++];
		if (l > n * 2)
			l = 0;
		for (int x = head[now]; x; x = nxt[x])
		{
			if (!dis[tx] && ret[x] != 0)
			{
				dis[tx] = dis[now] + 1;
				qu[r++] = tx;
				if (r > n * 2)
					r = 0;
				if (tx == t)
					return true;
			}
		}
	}
	return false;
}
int dfs(int f, int maxflow)
{
	if (f == t)
		return maxflow;
	int ans = 0;
	for (int x = head[f]; x && ans < maxflow; x = nxt[x])
	{
		if (dis[tx] != dis[f] + 1)
			continue;
		if (ret[x] != 0)
		{
			int temp = dfs(tx, min(maxflow - ans, ret[x]));
			ans += temp;
			ret[x] -= temp;
			ret[x ^ 1] += temp;
		}
	}
	if (ans == 0)
		dis[f] = -2;
	return ans;
}
int main()
{
	int a, b;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		add(a + n, b, INF);
		add(b, a + n, 0);
		add(b + n, a, INF);
		add(a, b + n, 0);
	}
	s += n; 
	for (int i = 1; i <= n; ++i)
	{
		add(i, i + n, 1);
		add(i + n, i, 0);
	}
	int ans = 0;
	while (bfs())
		ans += dfs(s, INF);
	printf("%d", ans);
	return 0;
}

