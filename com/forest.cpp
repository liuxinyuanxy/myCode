#include <iostream>
#include <algorithm>
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
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int a[300];
ll s = 0, ans = 0;
int fa[300];
int gra[300][300];
bool vis[300][300];
bool p;
vector<int> v;
pii edge[80000];
int find(rt x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
il void merge(rt x, rt y, rt w)
{
	x = find(x);
	y = find(y);
	if (x != y)
		fa[x] = y,
		++s,
		ans += w;
}
int main()
{
	rt len;
	rt n;
	sf(n);
	p = 0;
	rep (i, 1, n)
	{
		fa[i] = i;
		sf(a[i]);
		if (a[i] == 1)
			v.push_back(i);
	}
	rep (i, 1, n)
		rep (j, 1, n)
		{
			sf(gra[i][j]);
			if (i == j)
				continue;
			edge[(i - 1) * n + j].first = gra[i][j],
			edge[(i - 1) * n + j].second = (i - 1) * n + j;
		}
	len = v.size();
	if (len > 0)
	{
		rep (i, 0, len - 1)
		{
			rep (j, 1, n)
			{
				if (!vis[v[i]][j] && v[i] != j)
					++ans,
					s += gra[v[i]][j],
					vis[v[i]][j] = vis[j][v[i]] = 1;
			}
		}
	}
	else
	{
		rt x, y, w;
		sort(edge + 1, edge + 1 + n * n);
		rep (i, 1, n * n)
		{
			w = edge[i].first;
			x = edge[i].second / n + 1;
			y = edge[i].second - (x - 1) * n;
			merge(x, y, w);
		}
	}
	pfl (ans), putchar(' '), pfl (s);
	return 0;
}

