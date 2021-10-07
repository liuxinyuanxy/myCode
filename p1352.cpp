#include <iostream>
#include <cstdio>
#include <vector>
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
#define MAX 6005
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int n, r[MAX], fa[MAX];
int dp[MAX][2];
vector<int> son[MAX];
void dfs(rt u)
{
	rt v, len;
	dp[u][1] = r[u];
	len = son[u].size();
	rep (i, 0, len - 1)
		v = son[u][i],
		dfs(v),
		dp[u][1] += dp[v][0],
		dp[u][0] +=	max(dp[v][0], dp[v][1]);
}
int main()
{
	rt k, l, root;
	sf(n);
	rep (i, 1, n)
		sf(r[i]);
	rep (i, 1, n - 1)
	{
		sf2(l, k);
		fa[l] = k;	
		son[k].push_back(l);
	}
	rep (i, 1, n)
		if (!fa[i])
			root = i;
	dfs(root);
	pf(max(dp[root][0], dp[root][1]));
	return 0;
}

