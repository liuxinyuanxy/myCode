#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define sf(x) scanf ("%d", &x)
#define sf2(x, y) scanf ("%d%d", &x, &y)
#define pfl(x) printf("%I64d", x)
#define pfl2(x, y) printf("%I64d%I64d", x, y)
#define sfl(x) scanf ("%I64d", &x)
#define sfl2(x, y)	scanf ("%I64d%I64d", &x, &y)
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
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int cnt[1005][256], small = 0x7f, big = 0;
char s[1005];
il void print(rt f, rt t)
{
	rep (i, f, t)
		putchar(s[i]);
}
int main()
{
	int n;
	cin >> n;
	cin >> (s + 1);
	rep (i, 1, n)
	{
		rep (j, small, big)
			cnt[i][j] = cnt[i - 1][j];
		small = min(small, (int)s[i]);
		big = max(big, (int)s[i]);
		++cnt[i][(int)s[i]];
	}
	bool p;
	rep (i, 1, n)
		rep (j, i, n)
		{
			p = 1;
			rep (k, small, big)
				if (cnt[j][k] - cnt[i - 1][k] > (j - i + 1) / 2)
				{
					p = 0;
					break;
				}
			if (p)
			{
				puts("YES");
				print(i, j);
				return 0;
			}
		}
	puts("NO");
	return 0;
}

