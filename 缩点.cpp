#include <iostream>
#include <cstdio>
#define MAX 300000
#define ti to[i]
using namespace std;
int n, m;
int v[MAX];
int head[MAX], nxt[MAX], to[MAX];
int vvv[MAX];
int h2[MAX];
int dfn[MAX], low[MAX], cnt;
bool vis[MAX];
int col[MAX];
int ru[MAX];
int tot;
int st[MAX], top, l, r;
inline void add(int* h, int u, int v)
{
	nxt[++tot] = h[u];
	h[u] = tot;
	to[tot] = v;
}
void tarjan(int x)
{
	st[++top] = x;
	vis[x] = 1;
	dfn[x] = low[x] = ++cnt;
	for (int i = head[x]; i; i = nxt[i])
	{
		if (!dfn[ti])
		{
			tarjan(ti);
			low[x] = min(low[x], low[ti]);
		}
		else
			if (vis[ti])
				low[x] = min(low[x], dfn[ti]);
	}
	if (dfn[x] == low[x])
	{
		while (st[top] != x && top)
		{
			v[x] += v[st[top]];
			vis[st[top]] = 0;
			col[st[top--]] = x;
		}
		vis[st[top]] = 0;
		col[st[top--]] = x;
	}
}
int topo()
{
	int ans = 0;
	l = r = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (col[i] == i && ru[i] == 0)
			ans = max(ans, v[i]),
			st[r++] = i,
			vvv[i] = v[i];
	}
	while (l != r)
	{
		int now = st[l++];
		if (l > n)
			l = 0;
		for (int i = h2[now]; i; i = nxt[i])
		{
			--ru[ti];
			vvv[ti] = max(vvv[ti], vvv[now] + v[ti]);
			ans = max(ans, vvv[ti]);
			if (!ru[ti])
			{
				st[r++] = ti;
				if (r > n)
					r = 0;
			}
		}
	}
	return ans;
}
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &v[i]);
	}
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
				++ru[col[ti]];
				add(h2, col[j], col[ti]);
			}
		}
	}
	printf("%d\n", topo());
	return 0;
}

