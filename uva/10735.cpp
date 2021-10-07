#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void rd(T &s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
		;
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
const int INF = 0x3fffffff;
const int N = 500000;
int s, t, n;
int u[N], v[N], d[N];
bool p[N];
int id[N];
int qu[N + 20], l, r, dis[N];
int cnt = 1;
int head[N], nxt[N], to[N], flow[N], cap[N];
vector<int> E[500];
int cur[N];
void ins(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	cap[cnt] = w;
	flow[cnt] = 0;
}
void insert(int u, int v, int w)
{
	ins(u, v, w);
	ins(v, u, 0);
}
bool bfs()
{
	fill(dis + 1, dis + 1 + n, 0);
	copy(head + 1, head + 1 + n, cur + 1);
	l = r = 0;
	qu[r++] = s;
	dis[s] = 1;
	while (l != r)
	{
		int u = qu[l++];
		if (l > N)
			l = 0;
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = to[i];
			if (cap[i] > flow[i] && !dis[v])
			{
				dis[v] = dis[u] + 1;
				if (v == t)
					return true;
				qu[r++] = v;
				if (r > N)
					r = 0;
			}
		}
	}
	return false;
}
int dfs(int u, int maxflow)
{
	if (u == t)
		return maxflow;
	int ans = 0;
	for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
	{
		if (cap[i] > flow[i] && dis[v] == dis[u] + 1)
		{
			int temp = dfs(v, min(maxflow - ans, cap[i] - flow[i]));
			ans += temp;
			flow[i] += temp;
			flow[i ^ 1] -= temp;
			if (ans == maxflow)
				break;
		}
	}
	if (!ans)
		dis[u] = -2;
	return ans;
}
void dfs(int u)
{
	printf("%d ", u);
	while (E[u].size())
	{
		int y = *E[u].rbegin();
		E[u].pop_back();
		dfs(y);
	}
}
int main()
{
	char ch;
	int m, sum = 0;
	int T;
	rd(T);
	while (T--)
	{
		rd(n, m);
		for (int i = 1; i <= m; ++i)
		{
			rd(u[i], v[i]);
			while (ch = gc(), !isalpha(ch))
				;
			if (ch == 'U')
				id[i] = cnt + 1, insert(u[i], v[i], 1);
			else
				id[i] = -1;
			++d[u[i]], --d[v[i]];
		}
		s = n + 1;
		t = s + 1;
		sum = 0;
		bool pp = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (d[i] & 1)
			{
				pp = 1;
				printf("No euler circuit exist\n");
				break;
			}
			d[i] >>= 1;
			if (d[i] > 0)
				sum += d[i], insert(s, i, d[i]);
			else
				insert(i, t, -d[i]);
		}
		if (pp)
			continue;
		n = t;
		int ans = 0;
		while (bfs())
			ans += dfs(s, INF);
		if (ans != sum)
		{
			printf("No euler circuit exist\n");
			continue;
		}
		for (int i = 1; i <= m; ++i)
			if (id[i] == -1 || flow[id[i]] == 0)
				E[u[i]].push_back(v[i]);
			else
				E[v[i]].push_back(u[i]);
		dfs(1);
		puts("");
		if (T)
			puts("");
		cnt = 1;
		fill(head + 1, head + 1 + n, 0);
		fill(d + 1, d + 1 + n, 0);
		fill(p + 1, p + 1 + n, 0);
	}
	return 0;
}