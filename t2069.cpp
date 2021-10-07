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
using namespace std;
ll n;
ll ans = 0;
int tot = 0;
int cnt[10000000];
int main()
{
	scanf("%lld", &n);
	for (rll i = 2; i * i < n; ++i)
	{
		if (n % i == 0)
		{
			++tot;
			cnt[tot] = 1;
			n /= i;
			while (n % i == 0)
			{
				n /= i;
				++cnt[tot];
			}
		}
	}
	if (n != 1)
		cnt[++tot] = 1;
	ans = 1;
	for (rt i = 1; i <= tot; ++i)
		ans *= (2 * cnt[i] + 1);
	printf("%lld", ans);
	return 0;
}


