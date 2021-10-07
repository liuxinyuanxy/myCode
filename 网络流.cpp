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
#define _ 200000
using namespace std;
int head[_], to[_], ret[_], nxt[_];
int dis[_];
int tot = 1;
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
int n = rd(), m = rd(), s = rd(), t = rd(); 
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	ret[tot] = w;
	
	nxt[++tot] = head[v];
	head[v] = tot;
	to[tot] = u;
	ret[tot] = 0;
}
bool bfs()
{
	
}
int main()
{
	for (rt i = 1; i <= m; ++i)
		add(rd(), rd(), rd());
	ll ans = 0;
	while (bfs())
		ans += dfs(s, 0x7fffffff);
	printf("%lld", ans);
	return 0;
}


