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
#define rep(x, a, b) for (rll (x) = 2; (x) <= (a); (x) += (b))
using namespace std;
ll f[100];
void print(string& s, rll l, rll r)
{
	for (rll i = l; i <= r; ++i)
		putchar(s[i]);
}
void search(rll i, rll l, rll r)
{
//	if (l > r)
//		return;
//	cout << i << "\t" << l << "\t" << r << endl;
	if (i < 2)
	{
		putchar(i + '0');
		return;
	}
	if (l >= f[i - 2])
		search(i - 1, l - f[i - 2], r - f[i - 2]);
	else
		if (r < f[i - 2])
			search(i - 2, l, r);
		else
			search(i - 2, l, f[i - 2] - 1),
			search(i - 1, 0, r - f[i - 2]);
}
int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	rll n, l, r, p;
	rll sp = 0;
	string f1, f2, f3;
	rll l1, l2, l3;
	sfl(n), sfl2(l, r);
	f[0] = f[1] = 1;
	rep(i, n, 1)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > r)
		{
			p = i;
			break;
		}
	}
	search(p, l, r);
	return 0;
}

