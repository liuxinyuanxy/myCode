#include <cstdio>
#include <iostream>
using namespace std;
int tot = 1;
int is[MAX], bck[MAX];
int s, t;
int head[MAX], nxt[MAX], to[MAX], ret[MAX];
inline void add(int u, int v, int w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	ret[tot] = w;
}
inline bool bfs()
{
}
int main()
{
	int t, n;
	int p;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &is[i]);
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &p);
			if (is[i])
				bck[i] = p;
		}
	}
	return 0;
}
