#include <ctype.h>
#include <stdio.h>
int main()
{
    int m, n;
    bool p = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j < i; ++j)
            if (i % j == 0)
                cnt += j;
        if (i == cnt)
        {
            p = 1;
            printf("%d = 1", i);
            for (int j = 2; j < i; ++j)
                if (i % j == 0)
                    printf(" + %d", j);
            printf("\n");
        }
    }
    if (!p)
        printf("None\n");
    return 0;
}