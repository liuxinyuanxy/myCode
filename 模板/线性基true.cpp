//ÏßÐÔ»ù 
#include <iostream>
#include <cstdio>
#include <vector> 
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
#define jia(a, b) (((a) + (b)) % MOD)
#define cheng(a, b) ((a) * (b) % MOD)
#define MAXL 62
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
ll two[100], Bit[100], n;
vector<ll> v;
il ll rd()
{
	ll s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
il void insert(ll x)
{
	for (rt i = MAXL; i >= 0; --i)
	{
		if (x & two[i])
		{
			if (Bit[i])
			{
				x ^= Bit[i];
			}
			else
			{
				rep (j, 0, i - 1)
					if (x & two[j])
						x ^= Bit[j];
				rep (j, i + 1, MAXL)
					if (Bit[j] & two[i])
						Bit[j] ^= x;
				Bit[i] = x;
				return;
			}
		}
	}
}
il void INIT()
{
	rep (i, 0, MAXL)
		if (Bit[i])
			v.push_back(Bit[i]);
}
il ll query(rll k)
{
	if ((int)v.size() != n)
		--k;
	if (k > two[(int)v.size()] - 1)
		return -1;
	ll ans = 0;
	rep (i, 0, (int)v.size() - 1)
		if (k & two[i])
			ans ^= v[i];
	return ans;
}
int main()
{
	rll T, q, tn;
	T = rd();
	two[0] = 1;
	rep (i, 1, MAXL)
		two[i] = two[i - 1] << 1;
	rep (i, 1, T)
	{
		printf("Case #%d:\n", i);
		v.clear();
		tn = n = rd();
		while (insert(rd()), --tn);
		INIT();
		q = rd();
		while (pfl(query(rd())), putchar('\n'), --q);
		fill(Bit, Bit + MAXL + 1, 0);
	}
	return 0;
}

