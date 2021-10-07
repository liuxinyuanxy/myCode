#include <cctype>
#include <cstdio>
#include <iostream>
#define LL long long
#define gc getchar
using namespace std;
const int MOD = 12356789;
template <typename T>
void read(T &s)
{
    bool p = 0;
    char ch;
    s = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = (s * 10 + ch - '0') % (MOD - 1), ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
struct Mat
{
    int n, m;
    int g[3][3];
    Mat(int _n = 0, int _m = 0) : n(_n), m(_m)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                g[i][j] = 0;
    }
};
Mat operator*(const Mat &a, const Mat &b)
{
    Mat t(a.n, b.m);
    for (int k = 1; k <= a.m; ++k)
        for (int i = 1; i <= a.n; ++i)
            for (int j = 1; j <= b.m; ++j)
                t.g[i][j] = (t.g[i][j] + a.g[i][k] * 1ll * b.g[k][j] % MOD) % MOD;
    return t;
}
Mat qpow(Mat a, LL b)
{
    Mat ans(a.n, a.m);
    for (int i = 1; i <= a.n; ++i)
        ans.g[i][i] = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ans = ans * a;
    return ans;
}
int main()
{
    LL n;
    read(n);
    Mat zero(1, 2);
    zero.g[1][1] = 1;
    Mat mo(2, 2);
    mo.g[1][1] = mo.g[2][2] = 4;
    mo.g[1][2] = mo.g[2][1] = 2;
    zero = zero * qpow(mo, n);
    int ans = zero.g[1][1];
    printf("%d", ans);
    return 0;
}