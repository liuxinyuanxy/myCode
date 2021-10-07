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
#define pii pair<int, int>
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
il ll r_d()
{
	rll s = 0, p = 1;
	rc ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-')
		p = -1,
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s * p;
}
ll n, x, y; 
char str[300000];
int s[200005][5]; //1:U 2:D 3:L 4:R 
bool check(rll m)
{
	rll mx, my, dis;
	rep (i, 1, n - m + 1)
	{
		mx = s[i - 1][4] - s[i - 1][3];
		my = s[i - 1][1] - s[i - 1][2];
		mx += s[n][4] - s[(i + m - 1)][4];
		mx -= s[n][3] - s[(i + m - 1)][3];
		my += s[n][1] - s[(i + m - 1)][1];
		my -= s[n][2] - s[(i + m - 1)][2];
		mx = x - mx;
		my = y - my;
		dis = (mx < 0 ? -mx : mx) + (my < 0 ? -my : my);
		if (m >= dis && (m & 1) == (dis & 1))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ll l, r, m, dis;
	n = r_d();
	rep (i, 1, n)
	{
		str[i] = getchar();
		while (str[i] < 'A' || str[i] > 'Z')
			str[i] = getchar();
		rep (j, 1, 4)
			s[i][j] = s[i - 1][j];
		++s[i][str[i] == 'U' ? 1 : str[i] == 'D' ? 2 : str[i] == 'L' ? 3 : 4]; 
	}
	x = r_d(),
	y = r_d();
	dis = (x < 0 ? -x : x) + (y < 0 ? -y : y);
	if (n < dis || (n & 1) != (dis & 1))
	{
		pf(-1);
		return 0;
	}
	l = 0, r = n;
	while (l != r)
	{
		m = mid(l, r);
		if (check(m))
			r = m;
		else
			l = m + 1;
	}
	cout << l;
	return 0;
}

