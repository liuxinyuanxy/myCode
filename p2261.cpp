#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
signed main()
{
	int n, k;
	scanf("%lld%lld", &n, &k);
    long long ans = n * k;
    if (n > k)
    {
        n = k;
    }
	for (int l = 1, r; l <= n; l = r + 1)
	{
		r = k / (k / l);
        if (r > n)
            r = n;
		ans -= (l + r) * (r - l + 1) / 2 * (k / l);
	}
	printf("%lld", ans);
	return 0;
}