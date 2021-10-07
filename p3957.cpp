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
#define m_p make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAXN 10000000
#define piii pair<int, pii>
#define piiii pair<pii, pii>
#define INF 0x7fffffffffffff
#define rep(x, a, b) for (rt (x) = (a); (x) <= (b); ++(x))
using namespace std;
ll n, d, k;
ll qu[10000000], temp;
ll x[MAXN + 5], s[MAXN + 5];
ll ans[MAXN + 5];
il bool can_jump(rll len, rll g)
{
	return (d - g) <= len && len <= (d + g);  
}
bool check(rt g)
{
	ll can_jump_max = 0;
	rll l, r;
	l = r = 0;
	rll lst;
	rll from = 1;
	while (!can_jump(x[from], g) && from <= n)
		++from;
	if (from > n)
		return false;
	can_jump_max = ans[from] = s[from];
	lst = from;
	rep (i, from + 1, n)
	{
//		cout << lst << " " << ans[lst] << "\t";
		while (x[i] - x[lst] >= max(1ll, d - g))
		{
			while (l != r && ans[lst] >= ans[qu[(r + MAXN) % (MAXN + 1)]])
			{
				--r;
				if (r < 0)
					r = MAXN;
			}
			qu[r++] = lst;
			++lst;
			if (r > MAXN)
				r = 0;
		}
		while (l != r && !can_jump(x[i] - x[qu[l]], g))
		{
			++l;
			if (l > MAXN)
				l = 0;
		}
		if (l == r)
			ans[i] = -INF;
		else
			ans[i] = ans[qu[l]] + s[i];
		selfmax(can_jump_max, ans[i]);
	}
//	cout << g << "\t" << can_jump_max << endl;
	return can_jump_max >= k;
}
int main()
{
	bool p = 0;
	rll l, r, m;
	sfl(n),
	sfl2(d, k); 
	rep (i, 1, n)
		sfl2(x[i], s[i]);
	l = 0, r = 1000000000;
	while (l != r)
	{
		m = mid(l, r);
		if (check(m))
			p = 1,
			r = m;
		else
			l = m + 1;
	}
	if (p)
		pf(l);
	else
		pf(-1);
	return 0;
}
