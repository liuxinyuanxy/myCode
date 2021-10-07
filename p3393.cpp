#include <iostream>
#include <cstdio>
#include <queue>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define pll pair<ll, ll>
#define _ 500000
using namespace std;
priority_queue<pll, vector<pll>, greater<pll> > pq;
int head[_], nxt[_], to[_], tot;
int qu[_ * 3], l, r, n;
ll val[_], form[_], dis[_];
bool done[_];
il void add(rt u, rt v)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v; 
}
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
void bfs(rt u)
{
	rt now;
	qu[r++] = u;
	dis[u] = 0;
	while (l != r)
	{
		now = qu[l++];
		if (l > (_ << 1))
			l = 0;
		for (rt j = head[now]; j; j = nxt[j])
		{
			rt v = to[j];
			if (!dis[v])
			{
				dis[v] = dis[now] + 1;
				qu[r++] = v;
				if (r > (_ << 1))
					r = 0;
			}
		}
	}
} 
void dij(rt s, rt t)
{
	fill(form + 1, form + 1 + n, 0x7fffffffffffffff);
	pll now;
	rt id;
	pq.push(mp(0, s));
	form[s] = 0;
	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();
		id = now.second;
		if (done[id])
			continue;
		if (id == t)
		{
			printf("%lld", now.first);
			return;
		}
		done[id] = 1;
		for (rt i = head[id]; i; i = nxt[i])
		{
			rt v = to[i];
			if (val[v] == -1)
				continue;
			if (form[v] > form[id] + val[id])
			{
				form[v] = form[id] + val[id];
				pq.push(mp(form[v], v));
			}
		}
	}
}
int main()
{
	n = rd();
	rt m = rd(), k = rd(), s = rd();
	rt p = rd(), q = rd(), u, v;
	for (rt i = 1; i <= k; ++i)
		add(n + 1, rd());
	for (rt i = 1; i <= m; ++i)
		add(u = rd(), v = rd()),
		add(v, u);
	bfs(n + 1);
	for (rt i = 1; i <= n; ++i)
	{
		if (dis[i] == 1)
			val[i] = -1;
		else
			if (dis[i] <= s + 1)
				val[i] = q;
			else
				val[i] = p;
	}
	val[1] = val[n] = 0;
	dij(1, n);
	return 0;
}


