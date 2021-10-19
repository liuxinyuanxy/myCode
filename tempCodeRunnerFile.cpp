#include <stdio.h>
#include <math.h>
int is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int m, n;
    int cnt, tot;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; ++i)
        if (is_prime(i))
            ++cnt, tot += i;
    printf("%d %d", cnt, tot);
    return 0;
}