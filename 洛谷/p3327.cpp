#include <cctype>
#include <cstdio>
#include <iostream>
#define il inline
#define gc getchar
#define LL long long
#define re register
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
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
int mu[MAXN + 5], f[MAXN + 5];
LL d[MAXN + 5];
int pri[MAXN + 5], vis[MAXN + 5], cnt;
void init()
{
    d[1] = 1;
    mu[1] = 1;
    vis[1] = 1;
    for (int i = 2; i <= MAXN; ++i)
    {
        if (!vis[i])
            d[i] = 2,
            f[i] = 1,
            mu[i] = -1,
            pri[++cnt] = i;
        for (int j = 1; j <= cnt && pri[j] * i <= MAXN; ++j)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
            {
                f[i * pri[j]] = f[i] + 1;
                d[i * pri[j]] = (d[i] / (f[i] + 1)) * (f[i] + 2);
                break;
            }
            else
                f[i * pri[j]] = 1, d[i * pri[j]] = d[i] * 2, mu[i * pri[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= MAXN; ++i)
        mu[i] += mu[i - 1], d[i] += d[i - 1];
}
int main()
{
    init();
    int T;
    rd(T);
    while (T--)
    {
        LL ans = 0;
        int n, m;
        rd(n, m);
        int t = min(n, m);
        for (int l = 1, r; l <= t; l = r + 1)
        {
            r = min(n / (n / l), m / (m / l));
            ans += (mu[r] - mu[l - 1]) * d[n / l] * d[m / l];
        }
        printf("%lld\n", ans);
    }
    return 0;
}