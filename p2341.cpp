#include <iostream>
#include <cstdio>
#define MAX 300000
#define ti to[i]
#define stop st[top]
using namespace std;
int head[MAX], nxt[MAX], to[MAX];
int n, m;
int tot, col[MAX];
int cnt;
int num[MAX];
bool vis[MAX], chu[MAX];
int dfn[MAX], low[MAX]; 
int head2[MAX];
int st[MAX], l, r, top;
inline void add(int* h, int u, int v)
{
	nxt[++tot] = h[u];
	h[u] = tot;
	to[tot] = v;
}
void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	vis[x] = 1;
	st[++top] = x;
	for (int i = head[x]; i; i = nxt[i])
	{
		if (!dfn[ti])
		{
			tarjan(ti);
			low[x] = min(low[x], low[ti]);
		}
		else
			if (vis[x])
				low[x] = min(low[x], dfn[ti]);
	}
	if (low[x] == dfn[x])
	{
		while (stop != x && top)
			++num[x],
			vis[stop] = 0,
			col[stop] = x,
			--top;
		++num[x],
		vis[stop] = 0,
		col[stop] = x,
		--top;
	}	
}
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		add(head, a, b);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int j = 1; j <= n; ++j)
	{
		for (int i = head[j]; i; i = nxt[i])
		{
			if (col[j] != col[ti])
			{
				chu[col[j]] = 1;
			}
		}
	}
	bool ppp = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (col[i] == i && !chu[i])
		{
			if (ppp)
			{
				printf("0\n");
				return 0;
			}
			ppp = 1;
			ans = i;
		}
	}
	printf("%d", num[ans]);
	return 0;
}

