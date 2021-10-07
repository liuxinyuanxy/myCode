#include <iostream>
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
#define mid(x, y) ((x) + (y) >> 1)
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = 2; (x) <= (a); (x) += (b))
using namespace std;
void print(string& s, rll l, rll r)
{
	for (rll i = l; i <= r; ++i)
		putchar(s[i]);
}
int main()
{
	rll n, l, r;
	rll sp = 0;
	string f1, f2, f3;
	rll l1, l2, l3;
	sfl(n), sfl2(l, r);
	f1 = "0";
	f2 = "1";
	l1 = l2 = 1;
	rep(i, n, 1)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		l3 = l1 + l2;
		l1 = l2;
		l2 = l3;
		if (l3 > r)
		{
			print(f3, l, r);
			return 0;
		}
	}
	return 0;
}

