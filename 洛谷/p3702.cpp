#include <cctype>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define LL long long
#define gc getchar
using namespace std;
const int N = 100;
const int MOD = 20170408;
template <typename T>
void read(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
struct Mat
{
    int n, m;
    int g[N][N];
    Mat(int _n = 0, int _m = 0) : n(_n), m(_m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                g[i][j] = 0;
    }
};
Mat operator*(const Mat &x, const Mat &y)
{
    Mat t(x.n, y.m);
    for (int k = 0; k < x.m; ++k)
        for (int i = 0; i < x.n; ++i)
            for (int j = 0; j < y.m; ++j)
                t.g[i][j] = (t.g[i][j] + x.g[i][k] * 1ll * y.g[k][j] % MOD) % MOD;
    return t;
}
Mat qpow(Mat a, int b)
{
    Mat ans(a.n, a.n);
    for (int i = 0; i < a.n; ++i)
        ans.g[i][i] = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ans = ans * a;
    return ans;
}
const int MAXM = 30000000;
int pri[MAXM], vis[MAXM], cnt;
int sum[N];
int p;
void init(int n)
{
    vis[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            pri[++cnt] = i;
        else
            ++sum[i % p];
        for (int j = 1; j <= cnt && i * pri[j] <= n; ++j)
        {
            vis[i * pri[j]] = 1;
            if (!i % pri[j])
                break;
        }
    }
}
int n, m;
int solve()
{
    Mat zero(1, p);
    zero.g[0][0] = 1;
    Mat orz(p, p);
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < p; ++j)
            orz.g[i][(i + j) % p] = sum[j] % MOD;
    zero = zero * qpow(orz, n);
    return zero.g[0][0];
}
int main()
{
    read(n), read(m), read(p);
    for (int i = 1; i <= m; ++i)
        ++sum[i % p];
    int ans = solve();
    for (int i = 0; i < p; ++i)
        sum[i] = 0;
    init(m);
    ans -= solve();
    if (ans < 0)
        ans += MOD;
    printf("%d", ans);
    return 0;
}