#include <iostream>
#include <cmath>
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
#define mid (a, b) ((a + b) >> 1)
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
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
int blo, bl[_], n;
int a[_], op[_], fl[_];
il int rd()
{
	rt s = 0;
	rc ch = gc();
	while (ch < '0' || ch > '9')
		ch = gc();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = gc();
	return s;
}
il void reset(rt x)
{
	fl[x] = 1;
	if (op[x])
		a[blo * (x - 1) + 1] = op[x];
	rt to = min(n, bl[x] * blo);
	rep (i, blo * (x - 1) + 2, to)
		if (op[x])
			a[i] = op[x];
		else
			if (a[i] != a[i - 1])
				fl[x] = 0;
	op[x] = 0;
}
il void change(rt x, rt y, rt opt)
{
	rt to = min(y, blo * bl[x]);
	reset(bl[x]);
	rep (i, x, to)
		a[i] = opt;
	reset(bl[x]);
	if (bl[x] != bl[y])
	{
		reset(bl[y]);
		rep (i, blo * (bl[y] - 1) + 1, y)
			a[i] = opt;
		reset(bl[y]);
	}
	rep (i, bl[x] + 1, bl[y] - 1)
		op[i] = opt;		
}
il int one(rt x)
{
	if (x == 0)
		return -1;
	if (x == n + 1)
		return -2;
	if (op[bl[x]])
		return op[bl[x]];
	else
		return a[x];
}
il void query(rt x, rt y)
{
	if (one(x - 1) == one(y + 1))
	{
		puts("No");
		return;
	}
	rt to = min(y, bl[x] * blo);
	rep (i, x, to)
		if (one(i) != one(x))
		{
			puts("No");
			return;
		}
	if (bl[x] != bl[y])
		rep (i, blo * (bl[y] - 1) + 1, y)
			if (one(i) != one(x))
			{
				puts("No");
				return;	
			}
	rep (i, bl[x] + 1, bl[y] - 1)
		if (!fl[i])
		{
			puts("No");
			return;
		}
		else
		{
			if (op[i] != one(x))
			{
				puts("No");
				return;
			}
		}
	puts("Yes");
}
int main()
{
	rc ch;
	rt k, x, y, opt;
	n = rd();
	blo = sqrt(n);
	rep (i, 1, n)
		bl[i] = (i - 1) / blo + 1;
	rep (i, 1, n)
	{
		ch = gc();
		while (ch < 'A' || ch > 'C')
			ch = gc();
		a[i] = ch - 'A' + 1;
//		cout << a[i];
	}
	rep (i, 1, bl[n])
		reset(i);
	k = rd();
	rep (i, 1, k)
	{
		ch = gc();
		while (ch < 'A' || ch > 'B')
			ch = gc();
		x = rd(), y = rd();
		if (ch == 'A')
			opt = rd(),
			change(x, y, opt);
		else
			query(x, y);
	}
	return 0;
}
