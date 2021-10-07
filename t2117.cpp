#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define MOD 1000000007
using namespace std;
ll f[10000005];
ll cnt[5];
int main()
{
	ll n, ans = 1, p, p1, p2, temp;
	scanf ("%lld", &n);
	f[2] = 1;
	for (rll i = 3; i <= n; ++i)
	{
		for (rt j = 2; j < i; ++j)
		{
			if (i % j != 0)
			{
				p = (f[j] + 1) % MOD;
				break;
			}
		}
		if (i < 10000000)
			f[i] = p;
		ans = ans * p % MOD;
		++cnt[p];
//		cout << p << " ";
//		printf("%lld %lld %lld %lld %lld\n", i, cnt[2], cnt[3], cnt[4], ans);
	}
	printf("%lld", ans);
	return 0;
}


