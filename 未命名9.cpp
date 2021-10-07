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
int tot, cnt;
bool del[_];
int dfn[_], low[_];
int head[_], nxt[_], to[_], val[_];
il int rd()
{
	rt s = 0, p = 0; rc ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return p ? -s : s;
}
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
}
void tarjan(rt u, rt fa)
{
	rt child = 0;
	dfn[u] = low[u] = ++cnt;
	for (rt i = head[u]; i; i = nxt[i])
	{
		rt v = to[i];
		if (!dfn[v])
		{
			tarjan(v, u);
			++child;
			if ((child > 1 && fa == -1) || (fa != -1 && low[v] >= dfn[u]))
			{
				tot += !(del[u]);
				del[u] = 1;
			}
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}
int main()
{
	rt n = rd(), m = rd();
	rt u, v;
	for (rt i = 1; i <= m; ++i)
		add(u = rd(), v = rd()),
		add(v, u);
	tot = 0;
	for (rt i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i, -1);
	printf("%d\n", tot);
	for (rt i = 1; i <= n; ++i)
		if (del[i])
			printf("%d ", i);
	return 0;
}
