#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define mid(x, y) (((x) + (y)) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
#define rep2(x, a, b) for (rt (x) = 0; (x) <= (a); (x) += (b))
using namespace std;
int can[2005][2005];
int n, r, g;
ll pos[2005];
il int check(rt i, rt j, rt l)
{
	rt now, nxtl, nxtr, nxtm;
	now = can[i][j];
	++now;
	nxtl = now;
	nxtr = n;
	while (nxtl != nxtr)
	{
		nxtm = nxtl + nxtr - mid(nxtl, nxtr);
		if (pos[nxtm] - pos[now] + 1 <= l)
			nxtl = nxtm;
		else
			nxtr = nxtm - 1;
	}
	return nxtl;
}
bool dp(rt x)
{
	rep2(i, r, 1)
		rep2(j, g, 1)
			can[i][j] = 0;
	rep2(i, r, 1)
		rep2(j, g, 1)
		{
			if (i != r) selfmax(can[i + 1][j], check(i, j, x));
			if (j != g) selfmax(can[i][j + 1], check(i, j, x * 2));
			if (can[i+1][j] == n || can[i][j+1] == n)
				return true;
		}
	return false;
}
int main()
{
	sf(n),
	sf2(r, g);
	if (r >= n || g >= n)
	{
		pf(1);
		return 0;
	}
	rep(i, n, 1)
		sfl(pos[i]);
	sort(pos + 1, pos + 1 + n);
	rt l = 1, r = 1000000000, mi;
	while (l != r)
	{
		mi = mid(l, r);
		if (dp(mi))
			r = mi;
		else
			l = mi + 1;
	}
	pf(l);
	return 0;
}

