#include <stdio.h>
int main()
{
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - i + 1; ++j)
        {
            putchar(cnt + 'A');
            ++cnt;
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}