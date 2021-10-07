#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll d[3000005];
int main()
{
    ll n, p;
    scanf("%lld%lld", &n, &p);
    d[1] = 1;
    printf("%lld\n", d[1]);
    for (int i = 2; i <= n; ++i)
    {
        d[i] = (-(p / i) * d[p % i]);
        while (d[i] < 0)
            d[i] += p;
        printf("%lld\n", d[i]);
    }
    return 0;
}
//ax = 1 (mod p)
//ax + pb = 1
//
