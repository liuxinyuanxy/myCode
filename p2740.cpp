#include <iostream>
#include <cstdio>
#define gc getchar
using namespace std;
const int MAX = 0x7fffffff;
const int MAXN = 1000;
const int MAXM = 1000;
int tot = 1;
int dis[MAXN];
int head[MAXN], from[MAXM], to[MAXM], nxt[MAXM], ret[MAXM];
int qu[MAXN], l, r;
int n, m;
template <typename T> void rd(T& s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
inline void add(int s, int e, int c)
{
	nxt[++tot] = head[s];
	head[s] = tot;
	from[tot] = s;
	to[tot] = e;
	ret[tot] = c;

	nxt[++tot] = head[e];
	head[e] = tot;
	from[tot] = e;
	to[tot] = s;
	ret[tot] = 0;
}
bool bfs(int u, int v)
{
	fill(dis, dis + MAXN, 0);
	l = r = 0;
	qu[r++] = u;
	dis[u] = 1;
	while (l != r)
	{
		int t = qu[l++];
		if (l > MAXN - 10)
			l = 0;
		for (int i = head[t]; i; i = nxt[i])
		{
			if (ret[i] <= 0 || dis[to[i]])
				continue;
			dis[to[i]] = dis[t] + 1;
			if (to[i] == v)
				return true;
			qu[r++] = to[i];
			if (r > MAXN - 10)
				r = 0;
		}
	}
	return false;
}
int dinic(int u, int maxflow)
{
	if (u == m)
		return maxflow;
	int ans = 0;
	for (int i = head[u]; i; i = nxt[i])
	{
		int t = to[i], p;
		if (dis[t] != dis[u] + 1 || ret[i] <= 0)
			continue;
		p = dinic(t, min(maxflow - ans, ret[i]));
		ans += p;
		ret[i] -= p;
		ret[i ^ 1] += p;
		if (ans == maxflow)
			return ans;
	}
	if (!ans)
		dis[u] = -2;
	return ans;
}
int main()
{
	int s, e, c;
	rd(n, m);
	for (int i = 1; i <= n; ++i)
	{
		rd(s, e, c);
		add(s, e, c);
	}
	int ans = 0;
	while (bfs(1, m))
	{
		ans += dinic(1, MAX);
	}
	printf("%d", ans);
	return 0;
}