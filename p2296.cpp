#include <iostream>
#include <cstdio>
#define MAX 500000
using namespace std;
bool can[MAX];
int real[MAX], ru[MAX];
int h1[MAX], h2[MAX], nxt[MAX], to[MAX];
int qu[MAX], l, r;
int dis[MAX];
int tot;
int s, t;
inline void add(int* head, int u, int v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
void bfs1()
{
	int now;
	l = r = 0; 
	qu[r++] = t;
	while (l != r)
	{
		now = qu[l++];
		for (int i = h2[now]; i; i = nxt[i])
		{
			if (!real[to[i]])
			{
				qu[r++] = to[i];
			}
			++real[to[i]];
			if (real[to[i]] == ru[to[i]])
				can[to[i]] = 1;
		}
	}
}
void bfs2()
{
	int now;
	l = r = 0;
	qu[r++] = s;
	while (l != r)
	{
		now = qu[l++];
		for (int i = h1[now]; i; i = nxt[i])
		{
			if (!can[to[i]])
				continue;
			if (!dis[to[i]])
			{
				dis[to[i]] = dis[now] + 1;
				qu[r++] = to[i];
			} 
			if (to[i] == t)
			{
				printf("%d", dis[t]);
				exit(0);
			}
		}
	}
}
int main()
{
	int n, m, x, y;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf ("%d%d", &x, &y);
		if (x == y)
			continue;
		add(h2, y, x);
		add(h1, x, y);
		++ru[x];	
	} 
	scanf ("%d%d", &s, &t);
	bfs1();
	can[t] = 1;
	if (can[s])
		bfs2();
	printf("-1");
	return 0;
}
