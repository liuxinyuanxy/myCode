#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
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
#define mid(x, y) (((x) + (y)) >> 1)
#define pii pair<int, int>
#define MAX 500000
#define INF 0x3fffffff
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int tot;
int head[MAX], nxt[MAX], to[MAX], val[MAX], du[MAX];
ll dp[MAX][2];
ll ans;
bool has[MAX];
il void add(rt u, rt v, rt w)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	val[tot] = w;
}
void dfs(rt u, rt lst, rt w)
{
	if (has[u])
		ans += w,
		w = INF;
	for (rt i = head[u]; i; i = nxt[i])
		if (to[i] != lst)
			dfs(to[i], u, min(w, val[i]));
}
void dfs2(rt u, rt lst)
{
	rt temp = INF, id;
	if (has[u])
		dp[u][0] = INF,
		dp[u][1] = 0;
	else
		dp[u][1] = INF,
		dp[u][0] = 0;
	for (rt i = head[u]; i; i = nxt[i])
	{
		if (to[i] == lst)
			continue;
		dfs2(to[i], u);
		if (has[u])
			dp[u][1] += min(dp[to[i]][0], dp[to[i]][1] + val[i]);
		else
		{
			if (dp[to[i]][1] + val[i] < temp)
			{
				id = i;
				temp = dp[to[i]][1];
			}
			dp[u][1] += min(dp[to[i]][1] + val[i], dp[to[i]][0]);
			dp[u][0] += min(dp[to[i]][0], dp[to[i]][1] + val[i]);
		}
	}
	if (temp == INF)
		dp[to[id]][1] = INF;
	else
		dp[to[id]][1] -= val[id] + dp[to[id]][1];
	//	cout << u << "\t" << dp[u][1] << "\t" << dp[u][0] << endl;
}
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	bool flag;
	rt n, k, u, v, w, p;
	sf2(n, k);
	rep (i, 1, n - 1)
	{
		sf2(u, v), sf(w);
		++u, ++v;
		++du[u];
		++du[v];
		if (du[u] > 2 || du[v] > 2)
			flag = false;
		add(u, v, w),
		add(v, u, w);
	}
	rep (i, 1, k)
	{
		sf(p);
		++p;
		has[p] = 1;
	}                 
	if (flag)    
	rep (i, 1, n)                                     
	{
		if (du[i] == 1)
			dfs(i, 0, 0);
		pfl(ans);
		return 0;
	}
	dfs2(1, 0);
	pfl(min(dp[1][0], dp[1][1]));
	return 0;
}

