#include <iostream>
#include <cstdio>
#include <algorithm>
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
#define _ 1000000
#define lowbit(x) ((x) & -(x))
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
int tree[_], a[_];
il int rd()
{
	rt s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
int n;
il void add(rt x, rt y)
{
	a[x] = y;
	while (x <= n)
	{
		tree[x] = a[x];
		rt t = lowbit(x);
		for (rt j = 1; j < t; j <<= 1)
			tree[x] = max(tree[x], tree[x - j]);
		x += lowbit(x);
	}
}
il int query(rt x, rt y)
{
	rt ans = a[y];
	while (true)
	{
		ans = max(ans, a[y]);
		if (y == x)
			break;
		--y;
		while (y - x >= lowbit(y))
			ans = max(ans, tree[y]),
			y -= lowbit(y);
	}
	return ans;
}
int main()
{
	rt m, x, y;
	rc ch;
	while (sf2(n, m) != EOF)
	{
	rep (i, 1, n)
	{
		a[i] = rd();
		tree[i] = a[i];
		rt t = lowbit(i);
		for (rt j = 1; j < t; j <<= 1)
			tree[i] = max(tree[i], tree[i - j]);
	}
	rep (i, 1, m)
	{
		while (ch = gc(), ch != 'Q' && ch != 'U');
		x = rd(), y = rd();
		if (ch == 'Q')
			pf(query(x, y)),
			putchar('\n');
		else
			add(x, y);
	}
	rep (i, 1, n)
		a[i] = tree[i] = 0;
	}
	return 0;
}

