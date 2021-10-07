#include <iostream>
#include <cstdio>
#include <queue>
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define sf3(x, y, z) scanf ("%d%d%d", &x, &y, &z)
#define pf(x) printf ("%d", x)
#define pf2(x, y) printf("%d%d", x, y)
#define pf3(x, y, z) printf("%d%d%d", x, y, z)
#define sfl(x) scanf ("%lld", &x)
#define sfl2(x, y) scanf ("%lld%lld", &x, &y)
#define sfl3(x, y, z) scanf ("%lld%lld%lld", &x, &y, &z)
#define pfl(x) printf ("%lld", x)
#define pfl2(x, y) printf("%lld%lld", x, y)
#define pfl3(x, y, z) printf("%lld%lld%lld", x, y, z)
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
#define _ 200000
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
int head[_], nxt[_], to[_], val[_];
int dis[_];
int tot;
bool done[_];
struct node{
	int id, val, Min, Max;
}tmp;
bool operator < (const node& a, const node& b)
{
	return a.val < b.val;
}
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
p_q<node> pq;
int main()
{
	int id, u, v, w, n, m, ans = 0, t1, t2, s, t;
	while (sf2(n, m) != EOF)
	{
		rep (i, 1, m)
		{
			sf3(u, v, w);
			add(u, v, w);
			add(v, u, w);
		}
		sf2(t1, t2);
		ans = t1 + t2;
		sf2(s, t);
		pq.push({s, 0, 0, 0});
		while (!pq.empty())
		{
			tmp = pq.top();
			pq.pop();
			id = tmp.id;
		}
	}
	return 0;
}

