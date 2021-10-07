#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define int long long
#define il inline
using namespace std;
const int MAXN = 1000000;
int cnt, tot;
int in[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], clo[MAXN];
int head2[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], top, vis[MAXN];
int minR[MAXN], minlen[MAXN];
il void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
il void ins2(int u, int v)
{
	nxt[++cnt] = head2[u];
	++in[v];
	head2[u] = cnt;
	to[cnt] = v;
}
il void upt(int u, int y)
{
	if (minR[y] < minR[u])
		minR[u] = minR[y], minlen[u] = minlen[y];
	else if (minR[y] == minR[u])
		minlen[u] = min(minlen[u], minlen[y]);
}
void tarjan(int u)
{
	int y;
	dfn[u] = low[u] = ++tot;
	vis[u] = 1;
	sta[++top] = u;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (!dfn[v])
			tarjan(v), low[u] = min(low[u], low[v]);
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	if (dfn[u] == low[u])
		do
			y = sta[top--], vis[y] = 0, clo[y] = u, upt(u, y);
		while (y != u);
}
map<string, int> M;
string temp;
int n;
int essay[MAXN];
int num;
int read()
{
	cin >> temp;
	int tr = 0;
	for (auto &x : temp)
		x = toupper(x), tr += x == 'R';
	if (!M[temp])
		M[temp] = ++num, minR[num] = tr, minlen[num] = temp.length();
	return M[temp];
}
typedef pair<int, int> P;
vector<P> edge;
int qu[MAXN], l, r;
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	P temp;
	int m, M;
	cin >> m;
	for (int i = 1; i <= m; ++i)
		essay[i] = read();
	cin >> M;
	for (int i = 1; i <= M; ++i)
	{
		int u = read(), v = read();
		ins(v, u);
		temp.first = v, temp.second = u;
		edge.push_back(temp);
	}
	for (int i = 1; i <= num; ++i)
		if (!dfn[i])
			tarjan(i);
	for (auto x : edge)
		if (clo[x.first] != clo[x.second])
			ins2(clo[x.first], clo[x.second]);
	l = r = 0;
	for (int i = 1; i <= num; ++i)
		if (i == clo[i] && !in[i])
			qu[r++] = i;
	while (l != r)
	{
		int u = qu[l++];
		for (int i = head2[u], v = to[i]; i; i = nxt[i], v = to[i])
		{
			--in[v];
			upt(v, u);
			if (!in[v])
				qu[r++] = v;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= m; ++i)
		ans1 += minR[clo[essay[i]]], ans2 += minlen[clo[essay[i]]];
	cout << ans1 << " " << ans2;
	return 0;
}