#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int a[100050], m[100001][20], temp;
long long ans = 0;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        m[i][0] = a[i];
        if (a[i] == 1)
            ++ans;
    }
    int to = int(log(n) / log(2) + 0.001) + 1;
    for (int i = 1, j = 2; i <= to; ++i, j *= 2)
    {
        for (int k = 1; k + j - 1 <= n; ++k)
        {
            m[k][i] = max(m[k][i - 1], m[k + j / 2][i - 1]);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            temp = int(log(j - i + 1) / log(2) + 0.001);
            if (a[i]*a[j] <= max(m[i][temp], m[j-(1<<temp)+1][temp]))
                ++ans;
        }
    }
    printf("%lld", ans);
    return 0;
}