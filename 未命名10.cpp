#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 300000 
using namespace std;
int qu[_], dis[_], l, r;
int head[_], nxt[_], to[_], ret[_];
int tot = 1;
int n, m, s, t;
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	ret[tot] = w;
}
bool bfs()
{
	fill(dis + 1, dis + 1 + n, 0);
	rt now;
	l = r = 0;
	qu[r++] = s;
	dis[s] = 1;
	while (l != r)
	{
		now = qu[l++];
		if (l > _ - 1)
			l = 0;
		for (rt i = head[now]; i; i = nxt[i])
		{
			rt v = to[i];
			if (ret[i] && !dis[v])
			{
				dis[v] = dis[now] + 1;
				qu[r++] = v;
				if (r > _ - 1)
					r = 0;
				if (v == t)
					return true;
			}
		}
	}
	return false;
}
ll dfs(rt u, rt maxflow)
{
	ll ans = 0, tmp;
	if (u == t)
		return maxflow;
	for (rt i = head[u]; i; i = nxt[i])
	{
		rt v = to[i];
		if (ret[i] && dis[u] + 1 == dis[v])
		{
			tmp = dfs(v, min(maxflow - ans, 1ll * ret[i]));
			ret[i] -= tmp;
			ret[i^1] += tmp;
			ans += tmp;
		}
		if (ans >= maxflow)
			break;
	}
	if (!ans)
		dis[u] = -2;
	return ans;
}
void dinic()
{
	ll ans = 0;
	while (bfs())
		ans += dfs(s, 0x7fffffff);
	printf("%lld", ans);
}
int main()
{
	rt u, v, w;
	n = rd(), m = rd(), s = rd(), t = rd();
	for (rt i = 1; i <= m; ++i)
	{
		u = rd(), v = rd(), w = rd();
		add(u, v, w),
		add(v, u, 0); 
	}
	dinic();
	return 0;
}
