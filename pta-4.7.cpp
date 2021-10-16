#include <stdio.h>
#define int long long
signed main()
{
    int a, n, s;
    scanf("%lld%lld", &a, &n);
    int tot = 0;
    s = a;
    for (int i = 1; i <= n; ++i)
    {
        tot += s;
        s = s * 10 + a;
    }
    printf("s = %lld", tot);
    return 0;
}