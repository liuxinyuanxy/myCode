//ÊýÂÛ½× 
#include <iostream>
#include <cstdio>
#include <cstring>
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
#define mid (a, b) ((a + b) >> 1)
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
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b) % MOD)using namespace std;
using namespace std;
il ll gcd(rll a, rll b)
{
	return b ? gcd(b, a % b) : a;
}
il ll phi(rll x)
{
	ll sum = x;
	for (rll i = 2; i * i <= x; ++i)
		if (x % i == 0)
		{
			sum -= sum / i;
			while (x % i == 0)
				x /= i;
		}
	if (x != 1)
		sum -= sum / x;
	return sum;
}
il ll mul(rll a, rll b, rll m)
{
	ll s = 0;
	for (; b; b >>= 1, a = (a + a) % m)
		if (b & 1)
			s = (s + a) % m;
	return s;
}
il ll qpow(rll a, rll b, rll m)
{
	ll s = 1;
	for (; b; b >>= 1, a = mul(a, a, m))
		if (b & 1)
			s = mul(s, a, m);
	return s;
}
il void run(rll a, rll m)
{
	ll GCD = gcd(a, m);
	if (GCD != 1)
	{
		puts("Let's go Blue Jays!");
		return;
	}
	ll cnt = phi(m);
	ll prime[1000], primecnt[1000];
	ll tot = 0;
	memset(primecnt, 0, sizeof(primecnt));
	ll temp = cnt;
	for (rll i = 2; i * i <= temp; ++i)
		if (temp % i == 0)
		{
			prime[++tot] = i;
			while (temp % i == 0)
				++primecnt[tot],
				temp /= i;
		}
	if (temp != 1)
	{
		prime[++tot] = temp;
		primecnt[tot] = 1;
	}
	for (rll i = 1; i <= tot; ++i)
	{
		for (rll j = 1; j <= primecnt[i]; ++j)
		{
			if (qpow(a, cnt / prime[i], m) == 1)
				cnt /= prime[i];
		}
	}
	pfl(cnt);
}
int main()
{
	ll m, k, to;
//	cout << qpow(323, 322, 1000000009);
	sfl2(m, k);
	run(k, m);
	return 0;
}
/*
19260817 31
19260816
*/
