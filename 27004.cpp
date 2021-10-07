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
#define rep(x, y, z) for(rt x = (y); x <= (z); ++x)
#define mid (a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define m_p make_pair
#define p_q priority_queue
#define pii pair <int, int>
#define piii pair <pii, int>
#define piiii pair <pii, pii>
#define pll pair <ll, ll>
#define plll pair <pll, ll>
#define pllll pair <pll, pll>
#define lowbit(x) ((x) & (-x))
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)
using namespace std;
int s[105];
int cnt[3000];
int two[30];
int a[2][1025][1025];
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
il int count(rt x)
{
	rt s = 0;
	while (x)
		++s,
		x -= lowbit(x);
	return s;
}
int main()
{
	rc ch;
	rt n = rd(), m = rd(), ans = 0;
	two[0] = 1;
	rep (i, 1, m)
		two[i] = two[i - 1] << 1;
	rep (i, 0, two[m] - 1)
		cnt[i] = count(i);
	rep (i, 1, n)
		rep (j, 1, m)
		{
			ch = gc();
			while (ch != 'H' && ch != 'P')
				ch = gc();
			s[i] = (s[i] << 1) + (ch == 'H' ? 1 : 0);
		}
	rep (j, 0, two[m] - 1)
	{
		if (j & s[1] || (j & (j << 1)) || (j & (j << 2)))
			a[1][j][0] = -0x3fffffff;
		else
			a[1][j][0] = cnt[j];
	}
	rep (i, 2, n)
	{
		rep (j, 0, two[m] - 1)
		{
			if (j & s[i])
				continue;
			if ((j & (j << 2)) || (j & (j << 1)))
				continue;
			rep (k, 0, two[m] - 1)
			{
				if (k & s[i - 1])
					continue;
				if ((k & (k << 2)) || (k & (k << 1)))
					continue;
				if (j & k)
					continue;
//				if (i == 2)
//				{
//					a[i & 1][j][k] = cnt[j] + cnt[k];
//				}
//				else
				rep (l, 0, two[m] - 1)
				{
					if (l & s[i - 2])
						continue;
					if ((l & (l << 2)) || (l & (l << 1)))
						continue;
					if (j & l || k & l)
						continue;
					a[(i & 1)][j][k] = max(a[(i & 1)][j][k], a[(i & 1) ^ 1][k][l] + cnt[j]); 
				}
				ans = max(ans, a[i & 1][j][k]);
			}
		}
	}
	pf (ans);
	return 0;
}
