#include <iostream>
#include <cstdio>
#include <cstring>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 30000
using namespace std;
int head[_], nxt[_], val[_], to[_];
int tot;
int cnt[_], qu[_], l, r, g[_];
il void add(int u, int v, int w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
bool SPFA(int u, int n)
{
	memset(g, 0x7f, (sizeof(int) * (n + 1)));
	rt o, v;
	register bool vis[_] = {0};
	l = r = 0;
	qu[r++] = u;
	g[u] = 0;
	cnt[u] = 1;
	while (l != r)
	{
		o = qu[l++];
		vis[o] = 0;
		if (l > n)
			l = 0;
		for (rt i = head[o]; i; i = nxt[i])
		{
			v = to[i];
			if (g[v] > g[u] + val[i])
			{
				g[v] = g[u] + val[i];
				if (!vis[v])
				{
					vis[v] = 1;
					cnt[v] = cnt[u] + 1;
					if (cnt[v] >= n)
						return true;
					if (g[v] < g[qu[l]])
					{
						--l;
						if (l < 0)
							l = n;
						qu[l] = v;
					}
					else
					{
						qu[r++] = v;
						if (r > n)
							r = 0;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("in.txt", "r", stdin);
	int n, m;
	int k, x, y, c; 
	scanf ("%d%d", &n, &m);
//	fill(g + 1, g + 1 + n, 0x3fffffff);
	for (rt i = 1; i <= m; ++i)
	{
		scanf ("%d%d%d", &k, &x, &y);
		if (k == 3)
			add(x, y, 0),
			add(y, x, 0);
		else
		{
			scanf ("%d", &c);
			if (k == 1)
				add(y, x, -c);
			else
				add(x, y, c);
		}
	}
	for (rt i = 1; i <= n; ++i)
	{		
		if (!cnt[i] && SPFA(i, n))
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}


