#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, cnt = 0;
    scanf("%d", &x);
    for (int i5 = 20; i5 >= 1; --i5)
        for (int i2 = 50; i2 >= 1; --i2)
        {
            int i = x - i5 * 5 - i2 * 2;
            if (i <= 0)
                continue;
            ++cnt;
            printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i5, i2, i, i5 + i2 + i);
        }
    printf("count = %d", cnt);
    return 0;
}