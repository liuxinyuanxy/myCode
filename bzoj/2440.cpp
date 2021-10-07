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
const int MAXN = 1000000;
int mu[MAXN + 5];
int pri[MAXN + 5], vis[MAXN + 5], cnt;
void init()
{
    mu[1] = 1;
    vis[1] = 1;
    for (int i = 2; i <= MAXN; ++i)
    {
        if (!vis[i])
            mu[i] = -1,
            pri[++cnt] = i;
        for (int j = 1; j <= cnt && pri[j] * i <= MAXN; ++j)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
            else
                mu[i * pri[j]] = -mu[i];
        }
    }
}
LL calc(LL n)
{
    LL ans = 0;
    for (LL i = 1; i * i <= n; ++i)
    {
        ans += mu[i] * (n / (i * i));
    }
    return ans;
}
int main()
{
    init();
    int T;
    LL k;
    rd(T);
    while (T--)
    {
        rd(k);
        LL l = 0, r = 2147483647ll, m;
        while (l != r)
        {
            m = (l + r) >> 1;
            // cout << m << endl;
            if (calc(m) < k)
                l = m + 1;
            else
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}