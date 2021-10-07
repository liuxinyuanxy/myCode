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
const int MAXN = 20000;
vector<int> edge[MAXN], edge2[MAXN];
int dfn[MAXN], low[MAXN], vis[MAXN];
int sta[MAXN], top;
int clo[MAXN];
int in[MAXN], out[MAXN];
int tot, cnt;
int s;
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
			vis[y] = 0, clo[y] = u;
		vis[u] = 0, clo[u] = u;
		// cerr << u << endl;
		++s;
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, w;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w;
		while (w)
		{
			edge[i].push_back(w);
			cin >> w;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	for (int u = 1; u <= n; ++u)
		for (auto v : edge[u])
			if (clo[u] != clo[v])
			{
				edge2[clo[u]].push_back(clo[v]);
				++out[clo[u]];
				++in[clo[v]];
			}
	int ans1 = 0, ans2 = 0;
	if (s == 1)
	{
		cout << 1 << "\n"
			 << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (clo[i] == i && in[i] == 0)
			++ans1;
		if (clo[i] == i && out[i] == 0)
			++ans2;
	}
	cout << ans1 << "\n"
		 << max(ans1, ans2) << endl;
}