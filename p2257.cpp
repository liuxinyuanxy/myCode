// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#define re register
#define _ 10000005
using namespace std;
int mu[_];
long long g[_];
int pri[_], cnt;
bool vis[_];
void get_mu(re int n)
{
    mu[1] = vis[1] = 1;
    for (re int i = 2; i <= n; ++i)
    {
        if (!vis[i])
            pri[++cnt] = i,
            mu[i] = -1;
        for (re int j = 1; j <= cnt && pri[j] * i <= n; ++j)
        {
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
            mu[pri[j] * i] = -mu[i];
        }
    }
}
void get_g(re int n)
{
    for (re int i = 1; i <= cnt; ++i)
    {
        for (re int j = pri[i]; j <= n; j += pri[i])
        {
            g[j] += mu[j / pri[i]];
        }
    }
    for (re int i = 1; i <= n; ++i)
    {
        g[i] += g[i - 1];
    }
}
signed main()
{
    get_mu(10000000);
    get_g(10000000);
    int T, n, m, t;
    scanf("%lld", &T);
    while (T--)
    {
        re long long ans = 0;
        scanf("%d%d", &n, &m);
        t = min(n, m);
        for (re int l = 1, r; l <= t; l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans += (g[r] - g[l - 1]) * 1ll * (n / l) * (m / l);
        }
        printf("%lld\n", ans);
    }
    return 0;
}