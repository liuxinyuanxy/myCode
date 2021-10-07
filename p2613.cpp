#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define ll long long
#define rt register int
#define rc register char
#define rll register long long
#define pf(x) printf("%d", x)
#define sf(x) scanf ("%d", &x)
#define pfl(x) printf("%lld", x)
#define sfl(x) scanf ("%lld", &x)
#define jia(a, b) (((a) + (b)) % MOD)
#define jian(a, b) (((a) - (b)) % MOD)
#define cheng(a, b) (((a) * (b)) % MOD)
#define selfjia(a, b) (a) = ((a) + (b)) % MOD
#define selfjian(a, b) (a) = ((a) - (b)) % MOD
#define selfcheng(a, b) (a) = ((a) * (b)) % MOD
#define mid(x, y) ((x) + (y) >> 1)
#define MOD 19260817
using namespace std;
il ll read()
{
	rll s = 0;
	rc ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = (s * 10 + ch - '0') % MOD,
		ch = getchar();
	return s;
}
il ll qpow(rll a, rll p)
{
	ll s = 1;
	for (; p; p >>= 1, selfcheng(a, a))
		if (p & 1)
			selfcheng(s, a);
	return s;
}
int main()
{
	rll a = read(), b = read();
	if (b == 0)
		printf("Angry!");
	else
		pfl(cheng(a, qpow(b, MOD - 2))); 
	return 0;
}

