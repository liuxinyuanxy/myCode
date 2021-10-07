#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%I64d", &x)
#define sfl2(x, y) scanf ("%I64d%I64d", &x, &y)
#define sfl3(x, y, z) scanf ("%I64d%I64d%I64d", &x, &y, &z)
#define pfl(x) printf ("%I64d", x)
#define pfl2(x, y) printf("%I64d%I64d", x, y)
#define pfl3(x, y, z) printf("%I64d%I64d%I64d", x, y, z)
#define rep(i, a, b) for (rt i = (a); i <= (b); ++i)
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
#define _ 1000000
p_q<pll, vector<pll>, greater<pll> > pq;
int head[_], nxt[_], to[_], val[_];
int lst[_], dis[_];
bool done[_];
int tot = 0;
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
int main()
{
	pll temp;
	rt n, m, u, v, w, id;
	sf2(n, m);
	rep (i, 1, m)
	{
		sf2(u, v), sf(w);
		add(u, v, w);
		add(v, u, w);
	}
	memset(dis, -1, sizeof(dis));
	pq.push(mp(0, n));
	dis[n] = 0;
	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();
		id = temp.second;
		if (id == 1)
			break;
		if (done[id])
			continue;
		done[id] = 1;
		w = temp.first;
		for (rt i = head[id]; i; i = nxt[i])
			if (!done[to[i]] && (dis[to[i]] == -1 || dis[to[i]] > dis[id] + val[i]))
				dis[to[i]] = dis[id] + val[i],
				lst[to[i]] = id,
				pq.push(mp(dis[to[i]], to[i]));
	}
	if (dis[1] == -1)
	{
		pf(-1);
		return 0;
	}
	for (rt i = 1; i != n; i = lst[i])
		pf (i),
		putchar(' ');
	pf (n);
	return 0;
}

