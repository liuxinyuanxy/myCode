#include <iostream>
#include <cstdio>
using namespace std;
int n, k;
int ans = 0;
int s[10005][10005];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &s[i][i]);
    }
    for (int k = 1; k < n; ++k)
    {
        ans = 0;
        for (int i = 1 + k; i <= n; ++i)
        {
            s[i][i-k] = gcd(s[i][i-k+1], s[i-1][i-k]);
            ans = max(ans, s[i][i-k]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
