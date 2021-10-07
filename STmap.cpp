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
#define _ 1000005
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
int two[100], lg2[_];
int st[_][21];
il int rd()
{
	rt s = 0; rc ch; 
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s; 
}
il void ST(rt n)
{
	rep (i, 1, lg2[n])
		rep (j, 1, n - two[i] + 1)
			st[j][i] = max(st[j][i - 1], st[j + two[i - 1]][i - 1]);
}
int main()
{
	rt n = rd(), m = rd(), a, b, s;
	rep (i, 2, n)
		lg2[i] = lg2[i >> 1] + 1;
	two[0] = 1;
	rep (i, 1, lg2[n])
		two[i] = two[i - 1] << 1;
	rep (i, 1, n)
		st[i][0] = rd();
	ST(n);
	rep (i, 1, m)
	{
		a = rd(), b = rd();
		s = lg2[b - a + 1];
		pf (max(st[a][s], st[b - two[s] + 1][s]));
		putchar('\n');
	}
	return 0;
}

