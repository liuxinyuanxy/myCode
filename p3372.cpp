#include <iostream>
#include <cstdio>
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
#define lowbit(x) ((x) & -(x))
#define _ 1000000
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
il ll rd()
{
	rll s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
ll sum[_], del1[_], del2[_];
ll n = rd();
il void add(ll* del, rll x, rll d)
{
	while (x <= n)
		del[x] += d,
		x += lowbit(x);
}
il ll query(ll* del, rll x)
{
	rll ans = 0;
	while (x)
		ans += del[x],
		x -= lowbit(x);
	return ans;
}
il ll ask(rll x, rll y)
{
	return (sum[y] + (y + 1) * query(del1, y) - query(del2, y)) - (sum[x - 1] + x * query(del1, x - 1) - query(del2, x - 1));
}
il void change(rll x, rll y, rll k)
{
	add(del1, x, k),
	add(del1, y + 1, -k),
	add(del2, x, k * x),
	add(del2, y + 1, -k * (y + 1));
} 
int main()
{
	rll m = rd(), opt, x, y, k;
	rep (i, 1, n)
		sum[i] = sum[i - 1] + rd();
	rep (i, 1, m)
	{
		opt = rd(), x = rd(), y = rd();
		if (opt == 1)
		{
			k = rd();
			change(x, y, k);
		}
		else
		{
			pfl(ask(x, y)); 
			putchar('\n');
		}
	}
	return 0;
}

