#include <iostream>
#include <cstdio>
#include <cstring>
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
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
char ch[500000];
int a[5005][5005];
int aa[5005][5005];
int len; 
int check(rt l, rt r)
{
	if (ch[l] == ch[r])
		if (l + 1 >= r - 1)
			return aa[l][r] = 1;
		else
			if(!aa[l+1][r-1])
				return aa[l][r] = 0;
			else
				return aa[l][r] = 1;
	else
		return aa[l][r] = 0;
}
int main()
{
	int s, l, r;
	cin >> (ch + 1);
	len = strlen(ch + 1);
	rep (i, 1, len)
		a[i][i] = aa[i][i] = 1;
	rep (j, 1, len - 1)
		rep (i, 1, len - j)
			a[i][i+j] = a[i+1][i+j] + a[i][i+j-1] - a[i+1][i+j-1] + check(i, i+j);
	sf(s);
	rep (i, 1, s)
	{
		sf2(l, r);
		pf(a[l][r]);
		putchar('\n');
	}
	return 0;
}

