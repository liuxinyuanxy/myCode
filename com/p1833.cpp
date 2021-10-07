#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
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
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define MAX 5000000
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
string s;
int tot, T;
int t[MAX], c[MAX], p[MAX];
int g[MAX];
il int rd_tm()
{
	rc ch;
	rt hour, min, s = 0;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	hour = s;
	s = 0;
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	min = s;
	min += hour * 60;
	return min;
}
il void zerone(rt x)
{
	for(rt i = T; i >= t[x]; --i)
		g[i] = max(g[i], g[i - t[x]] + c[x]);
}
il void complete(rt x)
{
	for(rt i = t[x]; i <= T; ++i)
		g[i] = max(g[i], g[i - t[x]] + c[x]);
}
il void newone(rt x, rt k)
{
	++tot;
	t[tot] = t[x] * k;
	p[tot] = 1;
	c[tot] = c[x] * k;
}
il void many(rt x)
{
	if (t[x] * p[x] >= T)
		complete(x);
	else
	{
		rt k = 1, s = 1;
		for (; s < p[x]; k *= 2, s += k)
			p[x] -= k,
			newone(x, k);
		newone(x, p[x]);
	}
}
int main()
{
	rt n, ans = 0;
	T = rd_tm() - rd_tm();
	T = -T;
	sf(n);
	tot = n;
	rep(i, n, 1)
	{
		sf(t[i]);
		sf2(c[i], p[i]);
	}
	rep(i, tot, 1)
	{
		if (p[i] == 0)
			complete(i);
		else
			if (p[i] == 1)
				zerone(i);
			else
				many(i);
	}
	rep(i, T, 1)
		ans = max(ans, g[i]);
	pf(ans);
	return 0;
}

