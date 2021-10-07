//exgcd
#include <iostream>
#include <cstdio>
using namespace std;
void exgcd(int a, int b, int &x, int &y, int &gcd)
{
    if (!b)
        x = 1,
        y = 0,
        gcd = a;
    else
        exgcd(b, a % b, y, x, gcd),
        y -= (a / b) * x;
}
int main()
{
    int a, b, x, y, gcd;
    scanf("%d%d", &a, &b);
    exgcd(a, b, x, y, gcd);
    printf("%d\n", x);
    return 0;
}
