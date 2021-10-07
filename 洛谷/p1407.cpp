#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> M;
const int MAXN = 200000;
int cnt;
int head[MAXN], nxt[MAXN], to[MAXN];
int tot;
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
int dfn[MAXN], low[MAXN], clo[MAXN];
int vis[MAXN], sta[MAXN], top;
void tarjan(int u)
{
	sta[++top] = u;
	dfn[u] = low[u] = ++tot;
	vis[u] = 1;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	if (low[u] == dfn[u])
	{
		clo[u] = u;
		vis[u] = 0;
		int y;
		while ((y = sta[top--]) != u)
			clo[y] = u, vis[y] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	int u, v;
	string girl, boy;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> girl;
		u = M[girl] = ++tot;
		cin >> boy;
		v = M[boy] = ++tot;
		ins(u, v);
	}
	cin >> m;
	tot = 0;
	for (int i = 1; i <= m; ++i)
	{
		cin >> girl;
		cin >> boy;
		v = M[girl];
		u = M[boy];
		ins(u, v);
	}
	for (int i = 1; i <= (n << 1); ++i)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; ++i)
		if (clo[i << 1] == clo[(i << 1) - 1])
			cout << "Unsafe\n";
		else
			cout << "Safe\n";
	return 0;
}