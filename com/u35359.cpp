#include <iostream>
#include <cstdio>
#define ll long long 
#define MAXN 500010
using namespace std;
long long a[MAXN], id[MAXN];
int main()
{
    long long s = 0;
    ll n, m, ch, x, y;
    scanf("%lld%lld", &n, &m);
    ll cnt = n;
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        id[i] = i;
        s += a[i];
    }
    for (ll i = 1; i <= m; ++i)
    {
        ch = getchar();
        while (ch != 'C' && ch != 'I' && ch != 'D' && ch != 'Q')
            ch = getchar();
        if (ch == 'C')
        {
            scanf("%lld%lld", &x, &y);
            a[x] -= y;
            s -= y;
        }
        else
        {
            if (ch == 'I')
            {
                scanf("%lld%lld", &x, &y);
                id[++cnt] = x;
                s -= a[x];
                s += y;
                a[x] = y;
            }
            else
            {
                if (ch == 'D')
                {
                    scanf("%lld", &x);
                    s -= a[id[x]];
                    a[id[x]] = 0;
                }
                else
                {
                    if (ch == 'Q')
                    {
                        printf("%lld\n", s);
                    }
                }
            }
        }
    }
    
    return 0;
}
