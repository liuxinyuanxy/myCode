#include <cstdio>
#include <iostream>
#define il inline
#define gc getchar
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int N = 120;
const int MOD = 45989;
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
    {
        for (int i = 0; i < x.n; ++i)
        {
            if (!x.g[i][k])
                continue;
            for (int j = 0; j < y.m; ++j)
                t.g[i][j] = (t.g[i][j] + x.g[i][k] * 1ll * y.g[k][j] % MOD) % MOD;
        }
    }
    return t;
}
Mat qpow(Mat x, int b)
{
    Mat t(x.n, x.n);
    for (int i = 0; i < x.n; ++i)
        t.g[i][i] = 1;
    for (; b; b >>= 1, x = x * x)
        if (b & 1)
            t = t * x;
    return t;
}
int cnt = 0;
int head[N], to[N], nxt[N];
void ins(int u, int v)
{
    nxt[cnt] = head[u];
    head[u] = cnt;
    to[cnt++] = v;
}
int main()
{
    int n, m, t, a, b;
    read(n), read(m), read(t), read(a), read(b);
    if (t == 0)
    {
        printf("%d\n", a == b);
        return 0;
    }
    for (int i = 0; i < n; ++i)
        head[i] = -1;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        read(u), read(v);
        ins(u, v), ins(v, u);
    }
    Mat zero(m << 1, m << 1);
    for (int i = 0; i < cnt; ++i)
        for (int j = head[to[i]]; ~j; j = nxt[j])
            if ((i ^ j) != 1)
                zero.g[i][j] = 1;
    Mat one(1, m << 1);
    for (int i = head[a]; ~i; i = nxt[i])
        one.g[0][i] = 1;
    one = one * qpow(zero, t - 1);
    int ans = 0;
    for (int i = 0; i < cnt; ++i)
        if (to[i] == b)
            ans = (ans + one.g[0][i]) % MOD;
    if (ans < 0)
        ans += MOD;
    printf("%d", ans);
    return 0;
}