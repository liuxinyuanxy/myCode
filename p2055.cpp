#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 3000
#define tx to[x]
#define INF 0x3fffffff
#define rt register int
using namespace std;
int n;
int head[MAX], nxt[MAX], to[MAX], ret[MAX];
int istay[MAX], isbak[MAX];
int qu[MAX], l, r;
int s, t;
int dis[MAX], tot = 1;
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
	memset(dis, 0, sizeof(dis));
	int now = 0;
	l = r = 0;
	qu[r++] = s;
	dis[s] = 1;
	while (l != r)
	{
		now = qu[l++];
		if (l > n)
		{
			l = 0;
		}
		for (int x = head[now]; x; x = nxt[x])
		{
			if (ret[x] && !dis[tx])
			{
				dis[tx] = dis[now] + 1;
				qu[r++] = tx;
				if (r > n)
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
		if (dis[tx] != dis[f] + 1 || !ret[x])
			continue;
		int temp = dfs(tx, min(maxflow-ans, ret[x]));
		ans += temp;
		ret[x] -= temp;
		ret[x ^ 1] += temp;
	}
	if (!ans)
		dis[f] = -2;
	return ans;
}
int main()
{
	int aaa;
	int T;
	int p;
	scanf("%d", &T);
	while (T--)
	{
		tot = 1;
		aaa = 0;
		memset(head, 0, sizeof(head));
		scanf("%d", &n);
		s = 2 * n + 1;
		t = 2 * n + 2;
		for (rt i = 1; i <= n; ++i)
		{
			scanf("%d", &istay[i]);
		}
		for (rt i = 1; i <= n; ++i)
		{
			scanf("%d", &isbak[i]);
		}
		for (int i = 1; i <= n; ++i)
		{
			if (!istay[i] || !isbak[i])
			{
				++aaa;
				add(s, i, 1);
				add(i, s, 0);
			}
			if (istay[i])
			{
				add(i + n, t, 1);
				add(t, i + n, 0);
			}
		}
		for (rt i = 1; i <= n; ++i)
		{
			for (rt j = 1; j <= n; ++j)
			{
				scanf("%d", &p);
				if (p || i == j)
				{
					if ((!istay[i] || !isbak[i]) && istay[j])
					{
						add(i, j + n, 1);
						add(j + n, i, 0);
					}
				}
			}
		}
		int ans = 0;
		while (bfs())
			ans += dfs(s, INF);
		if (ans == aaa)
			printf("^_^\n");
		else
			printf("T_T\n");
	}
	return 0;
}

