#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define read(x) scanf("%d", &x)

int a[50][50];
int b[50][50];
int MyNegative(int x)
{
    if (x >= 0)
    {
        x = x ^ 10000000000000000000000000000000;
        return x;
    }
    else
    {
        x = x & 0x7fffffff;
        return x;
    }
}
int main()
{
    int n;
    read(n);
    printf("%d", MyNegative(n));
    return 0;
}