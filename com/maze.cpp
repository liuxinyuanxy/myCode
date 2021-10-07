#include <iostream>
#include <cstdio>
#include <queue>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, u) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y)	scanf ("%lld%lld", &x, &y)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define selfmax(x, y) (x) = max((x), (y))
#define mid(x, y) ((x) + (y) >> 1)
#define MAX 1000000
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
int tot;
bool done[MAX], ned[MAX];
int head[MAX], nxt[MAX], to[MAX], val[MAX];
int g1[MAX], g2[MAX];
priority_queue<pii, vector<pii>, greater<pii> > pq; 
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
int main()
{
	pii now;
	rt n, m, id;
	rt x, y, z, v;
	sf2(n, m);
	rep(i, m, 1)
	{
		sf(x);
		sf2(y, z);
		add(x, y, z);
		add(y, x, z);
	}
	rep(i, n, 1)
		g1[i] = g2[i] = -1;
	g1[1] = g2[1] = 0;
	pq.push(pii(0, 1));
	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();
		id = now.second;
		if (done[id] && !ned[id])
			continue;
		done[id] = 1;
		ned[id] = 0;
		for (rt i = head[id]; i; i = nxt[i])
		{
			v = to[i];
			if (g1[v] == -1 || g1[v] > g1[id] + val[i])
			{
				g2[v] = g1[v];
				g1[v] = g1[id] + val[i];
				pq.push(pii(g1[v], v));
				if ((g2[v] == -1 || g2[v] > g2[id] + val[i]) && g2[id] + val[i] > g1[v])
				{
					g2[v] = g2[id] + val[i];
					ned[v] = 1;
				}
			}
			else
				if ((g2[v] == -1 || g2[v] > g1[id] + val[i]) && g1[id] + val[i] > g1[v])
				{
					g2[v] = g1[id] + val[i];
					pq.push(pii(g1[v], v));
					ned[v] = 1;
				}
		}
	}
	pf(g2[n]);
	return 0;
}

