#include <cstdio>
#include <iostream>
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void rd(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
    rd(s);
    rd(args...);
}
const int MAXN = 50000;
int mu[MAXN + 5];
int vis[MAXN + 5], cnt, pri[MAXN];
void init()
{
    mu[1] = 1;
    for (int i = 2; i <= MAXN; ++i)
    {
        if (!vis[i])
        {
            pri[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && pri[j] * i <= MAXN; ++j)
        {
            vis[pri[j] * i] = 1;
            if (i % pri[j])
                mu[i * pri[j]] = -mu[i];
            else
                break;
        }
    }
    for (int i = 1; i <= MAXN; ++i)
        mu[i] += mu[i - 1];
}
LL query(int n, int m)
{
    LL ans = 0;
    int t = min(n, m);
    for (int l = 1, r; l <= t; l = r + 1)
    {
        r = min(n / (n / l), m / (m / l));
        ans += (n / l) * 1ll * (m / l) * (mu[r] - mu[l - 1]);
    }
    return ans;
}
int main()
{
    init();
    int n;
    rd(n);
    int k, a, b;
    for (int i = 1; i <= n; ++i)
    {
        rd(a, b, k);
        printf("%lld\n", query(a / k, b / k));
    }
    return 0;
}