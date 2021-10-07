#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 500000
using namespace std;
bool p;
bool vis[_];
ll dfn[_];
int head[_], nxt[_], to[_], val[_], tot;
ll ans;
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
	val[tot] = w;
}
int n = rd();
void travel(rt u)
{
	rt v;
	for (rt i = head[u]; i; i = nxt[i])
	{
		if (p)
			break;
		v = to[i];
		if (!vis[v])
		{
			if (!dfn[v])
			{	
				dfn[v] = dfn[u] + val[i];
				travel(v);				
			}
			else
			{
				ans = max(ans, dfn[u] + val[i] - dfn[v]);
				p = 1;
				break;
			}
		}
	}
	vis[u] = 1;
}
int main()
{
	rt v, w;
	for (rt i = 1; i <= n; ++i)
	{
		v = rd(), w = rd();
		add(i, v, w);
	}
	for (rt i = 1; i <= n; ++i)
		if (!dfn[i])
		{
			p = 0;
			dfn[i] = 1;
			travel(i);
		}
	printf("%lld", ans);
	return 0;
}


