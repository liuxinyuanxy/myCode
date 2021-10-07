#include <cstdio>
#include <iostream>
#define gc getchar
#define LL long long
#define il inline
#define re register
using namespace std;
template <typename T>
void rd(T &s)
{
	s = 0;
	char ch;
	while (ch = gc(), ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
		;
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
const int MAXN = 500000;
int n;
int qu[MAXN], l, r;
int dis[MAXN];
int cur[MAXN];
int head[MAXN], to[MAXN], nxt[MAXN];
LL du[MAXN];
LL ret[MAXN];
int cnt = 1;
void insert(int u, int v, LL c)
{
	to[++cnt] = v;
	nxt[cnt] = head[u];
	ret[cnt] = c;
	head[u] = cnt;

	to[++cnt] = u;
	nxt[cnt] = head[v];
	ret[cnt] = 0;
	head[v] = cnt;
}
bool bfs(int s, int t)
{
	fill(dis + 1, dis + n + 3, 0);
	for (int i = 1; i <= n + 2; ++i)
	{
		cur[i] = head[i];
	}
	int u, v;
	l = r = 0;
	qu[r++] = s;
	dis[s] = 1;
	while (l != r)
	{
		u = qu[l++];
		for (int i = head[u]; i; i = nxt[i])
		{
			v = to[i];
			if (!dis[v] && ret[i])
			{
				dis[v] = dis[u] + 1;
				qu[r++] = v;
				if (v == t)
					return true;
			}
		}
	}
	return false;
}
LL dfs(int u, LL maxflow, int t)
{
	if (u == t)
		return maxflow;
	LL ans = 0, temp;
	int v;
	for (int &i = cur[u]; i; i = nxt[i])
	{
		v = to[i];
		if (dis[v] != dis[u] + 1 || ret[i] <= 0)
			continue;
		temp = dfs(v, min(maxflow - ans, ret[i]), t);
		ans += temp;
		ret[i] -= temp;
		ret[i ^ 1] += temp;
		if (ans >= maxflow)
			break;
	}
	if (!ans)
		dis[u] = -2;
	return ans;
}
const LL INF = 0x3fffffff3fffffff;
LL dinic(int s, int t)
{
	LL ans = 0;
	while (bfs(s, t))
		ans += dfs(s, INF, t);
	return ans;
}
int main()
{
	int m, s, t, ss, tt, u, v;
	LL sum = 0, lower, upper;
	rd(n, m, s, t);
	ss = n + 1;
	tt = ss + 1;
	for (int i = 1; i <= m; ++i)
	{
		rd(u, v, lower, upper);
		insert(u, v, upper - lower);
		du[v] += lower;
		du[u] -= lower;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (du[i] > 0)
			sum += du[i],
				insert(ss, i, du[i]);
		else
			insert(i, tt, -du[i]);
	}
	LL f = dinic(ss, tt);
	insert(t, s, INF);
	f += dinic(ss, tt);
	if (f != sum)
		cout << "please go home to sleep";
	else
		cout << INF - ret[cnt - 1];
	return 0;
}