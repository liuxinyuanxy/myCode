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
#define MAX 100005
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
int n;
int a[MAX], b[MAX];
bool p[3];
int ned[3][MAX];
int num[3][MAX];
il int shd(rt i, rt j)
{
	if (i == 1 && j == 0)
		return 1;
	if (i == 1 && j == 1)
		return 2;
	if (i == 0 && j == 0)
		return 0;
	printf("NO");
	exit(0);
}
il void check(rt k)
{
	rep(i, 3, n)
	{
		num[k][i] = ned[k][i - 1] - num[k][i - 1];
		if (num[k][i] < 0 || num[k][i] > 1)
			return;
	}
	p[k] = 1;
}
int main()
{
	sf(n);
	rep(i, 1, n - 1)
		sf(a[i]);
	rep(i, 1, n - 1)
		sf(b[i]);
	rep(i, 1, n - 1)
	{
		ned[1][i] = shd(bool(a[i] & 2), bool(b[i] & 2));
	}
	rep(i, 1, n - 1)
		ned[2][i] = shd(a[i] & 1, b[i] & 1);
	rep(i, 1, 2)
	{
		if (ned[i][1] == 1)
		{
			num[i][1] = 1;
			num[i][2] = 0;
			check(i);
			if (p[i]) continue;
			num[i][1] = 0;
			num[i][2] = 1;
			check(i);
		}
		else
		{
			if (ned[i][1] == 2)
			{
				num[i][1] = 1;
				num[i][2] = 1;
				check(i);
			}
			else
			{
				num[i][1] = 0;
				num[i][2] = 0;
				check(i);
			}
		}
	}
	if (p[1] && p[2])
	{
		printf("YES\n");
		rep(i, 1, n)
		{
			pf(num[1][i] * 2 + num[2][i]);
			putchar(' ');
		}
	}
	else
	{
		printf("NO");
	}
	return 0;
}

