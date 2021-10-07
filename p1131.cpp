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
#define _ 1000005
using namespace std;
ll dis[_];
ll ans = 0;
int head[_], nxt[_], to[_], val[_], tot;
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il void add(rt u, rt v, rt w)
{ 
	if (!u || !v)
	{
		cout << "???";
		exit(0);
	}
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
void dfs(rt u, rt fa)
{
	rt v;
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == fa)
			continue;
		dfs(v, u);
		dis[u] = max(dis[u], dis[v] + val[i]);
	}
	for (rt i = head[u]; i; i = nxt[i])
	{
		v = to[i];
		if (v == fa)
			continue;
		ans += dis[u] - (dis[v] + val[i]);
	}
}
int main()
{
	rt n = rd(), s = rd(), u, v, w;
	for (rt i = 1; i < n; ++i)
		u = rd(), v = rd(), w = rd(),
		add(u, v, w),
		add(v, u, w);
	dfs(s, 0);
	printf("%lld", ans);
	return 0;
}
