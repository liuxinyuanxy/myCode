#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define LL long long
#define gc getchar
#define D() \
	cerr << __LINE__ << endl
using namespace std;
const int MAXN = 500;
vector<int> edge[MAXN], edge2[MAXN];
int dfn[MAXN], low[MAXN], vis[MAXN], val[MAXN];
int sta[MAXN], top;
int clo[MAXN];
int in[MAXN], out[MAXN];
int tot, cnt;
void tarjan(int u)
{
	vis[u] = 1;
	dfn[u] = low[u] = ++tot;
	sta[++top] = u;
	for (auto v : edge[u])
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	if (low[u] == dfn[u])
	{
		int y;
		while ((y = sta[top--]) != u)
			vis[y] = 0, clo[y] = u, ++val[u];
		vis[u] = 0, clo[u] = u, ++val[u];
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	for (int u = 1; u <= n; ++u)
		for (auto v : edge[u])
			if (clo[u] != clo[v])
			{
				edge2[clo[u]].push_back(clo[v]);
				++in[clo[v]];
			}
}