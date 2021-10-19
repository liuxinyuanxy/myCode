#include <math.h>
#include <stdio.h>
int main()
{
    int cnt = 0;
    double x, s = 0, ans = 0, sum = 1;
    scanf("%lf", &x);
    while (1)
    {
        s = pow(x, cnt) / sum;
        ans += s;
        ++cnt;
        sum *= cnt;
        if (fabs(s) < 0.00001)
            break;
    }
    printf("%.4lf", ans);
}