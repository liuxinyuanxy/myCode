#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
using namespace std;
template <typename T>
void rd(T &s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
		;
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
struct Edge
{
	int from, to, cap, flow, rev;
	Edge() {}
	Edge(int _from, int _to, int _cap, int _flow, int _rev) : from(_from), to(_to), cap(_cap), flow(_flow), rev(_rev) {}
};
typedef vector<Edge>::iterator vi;
const int INF = 0x3f3f3f3f;
const int MAXM = 204050;
const int MAXN = 10000;
vector<Edge> e[MAXN];
int d[MAXM], k[MAXN];
pair<int, int> it[MAXM];
vi cur[MAXN];
int dis[MAXN];
int qu[MAXM], l, r;
int cnt = 0;
int n, m, s, t;
il pair<int, int> insert(int u, int v, int c)
{
	e[v].push_back(Edge(v, u, 0, 0, e[u].size()));
	e[u].push_back(Edge(u, v, 0, c, e[v].size() - 1));
	return make_pair(u, e[u].size() - 1);
}
bool bfs()
{
	for (int i = 1; i <= t; ++i)
	{
		cur[i] = e[i].begin();
	}
	fill(dis + 1, dis + t + 1, 0);
	l = r = 0;
	qu[r++] = s;
	dis[s] = 1;
	while (l != r)
	{
		int now = qu[l++];
		for (auto x : e[now])
		{
			int to = x.to;
			if (!dis[to] && x.cap < x.flow)
			{
				qu[r++] = to;
				dis[to] = dis[now] + 1;
				if (to == t)
					return true;
			}
		}
	}
	return false;
}
int dfs(int u, int maxflow)
{
	if (u == t)
		return maxflow;
	int ans = 0, to;
	for (vi &x = cur[u]; x != e[u].end(); ++x)
	{
		to = x->to;
		if (dis[to] != dis[u] + 1 || x->cap >= x->flow)
			continue;
		int temp = dfs(to, min(maxflow - ans, x->flow - x->cap));
		ans += temp;
		x->cap += temp;
		e[to][x->rev].cap -= temp;
		if (ans >= maxflow)
			break;
	}
	if (!ans)
		dis[u] = -2;
	return ans;
}
il int dinic()
{
	int ans = 0;
	while (bfs())
		ans += dfs(s, INF);
	return ans;
}
int main()
{
	int u, v, lower, upper;
	rd(n, m);
	for (int i = 1; i <= m; ++i)
	{
		rd(u, v, lower, upper);
		d[i] = lower;
		k[u] -= lower;
		k[v] += lower;
		it[i] = insert(u, v, upper - lower);
	}
	s = n + 1;
	t = s + 1;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (k[i] < 0)
			insert(i, t, -k[i]);
		if (k[i] > 0)
			insert(s, i, k[i]),
				sum += k[i];
	}
	int maxflow = dinic();
	if (maxflow != sum)
	{
		printf("NO");
		return 0;
	}
	printf("Yes\n");
	for (int i = 1; i <= m; ++i)
	{
		printf("%d\n", d[i] + e[it[i].first][it[i].second].cap);
	}
	return 0;
}