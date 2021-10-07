#include <iostream>
#include <cstdio>
//#include <deque> 
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 100000
using namespace std;
//deque<int> qu;
bool vis[_];
int cnt[_];
int qu[_], l, r;
int dis[_];
int head[_], nxt[_], to[_], val[_];
int tot, n, T;
il int rd()
{
	rt s = 0, p = 0; rc ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return p ? -s : s;
}
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
bool SPFA()
{
//	qu.clear();
	fill(vis + 1, vis + 1 + n, 0);
	fill(cnt + 1, cnt + 1 + n, 0);
	fill(dis + 1, dis + 1 + n, 0x7fffffff);
	rt now;
	l = r = 0;
	qu[r++] = 1;
//	qu.push_back(1);
	cnt[1] = 1;
	dis[1] = 0;
	while (l != r)
	{
		now = qu[l++];
		vis[now] = 0;
		if (l > _ - 1)
			l = 0;
		for (rt i = head[now]; i; i = nxt[i])
		{
			rt v = to[i];
			if (dis[v] > dis[now] + val[i])
			{
				dis[v] = dis[now] + val[i];
				if (!vis[v])
				{
					++cnt[v];
					vis[v] = 1;
					if (cnt[v] >= n)
						return true;
					if (dis[v] < dis[now])
					{
//						qu.push_front(v);
						--l;
						if (l < 0)
							l = _ - 1;
						qu[l] = v;
					}		
					else
					{
//						qu.push_back(v);
						qu[r++] = v;
						if (r > _ - 1)
							r = 0;
					}		
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	rt m, u, v, w;
	T = rd();
	while (T--)
	{
		tot = 0;
		n = rd(), m = rd();
		for (rt i = 1; i <= m; ++i)
		{
			u = rd(), v = rd(), w = rd();
			add(u, v, w);
			if (w >= 0)
			{
				add(v, u, w);
			}
		}
		puts(SPFA() ? "YE5" : "N0");
		fill(head + 1, head + 1 + n, 0);	
	}
	return 0;
}
