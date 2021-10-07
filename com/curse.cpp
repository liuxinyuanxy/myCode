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
#define rep(x, a, b) for (rt (x) = 1; (x) <= (a); (x) += (b))
using namespace std;
int a[2000][2];
int main()
{
	freopen("curse.in", "r", stdin);
	freopen("curse.out", "w", stdout);
	rt n, l = 0;
	sf(n);
	rep(i, n, 1)
	{
		rc ch;
		ch = getchar();
		l = 0;
		while (ch != '0' && ch != '1')
			ch = getchar();
		while (ch == '0' || ch == '1')
		{
			++a[++l][ch - '0'];
			ch = getchar();
		}
	}
	rep(i, l, 1)
		if (a[i][0] >= a[i][1])
			putchar('0');
		else
			putchar('1');
	return 0;
}

