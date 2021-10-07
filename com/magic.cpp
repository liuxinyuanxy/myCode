#include <iostream>
#include <cstdio>
#include <cmath>
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
#define selfmin(x, y) (x) = min((x), (y))
#define mid(x, y) (((x) + (y)) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
int a[50005];
double s, ans;
il int rd()
{
	rt o = 0;
	rc ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		o = o * 10 + ch - '0',
		ch = getchar();
	return o;
}
void bigger(rt l, rt r, rt d)
{
	for (rt i = l; i <= r; ++i)
		selfmin(a[i], d);
}
void smaller(rt l, rt r, rt d)
{
	for (rt i = l; i <= r; ++i)
		selfmax(a[i], d);
}
void query(rt l, rt r)
{
	ans = 0;
	s = 0;
	for (rt i = l; i <= r; ++i)
		s += a[i];
	s /= (r - l + 1);
	for (rt i = l; i <= r; ++i)
		ans += (a[i] - s) * (a[i] - s);
	ans /= (r - l + 1);
	printf("%.1lf\n", sqrt(ans));
}
int main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	rt n, m, l, r, d;
	rc ch;
	n = rd();
	rep(i, n, 1)
		a[i] = rd();
	m = rd();
	rep(i, m, 1)
	{
		ch = getchar();
		while (ch != 'U' && ch != 'D' && ch != 'A')
			ch = getchar();
		l = rd(),
		r = rd();
		if (ch == 'A')
			query(l, r);
		else
		{
			d = rd();
			if (ch == 'U')
				smaller(l, r, d);
			else
				bigger(l, r, d);
		}
	}
	return 0;
}

