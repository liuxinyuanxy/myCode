#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define il inline
#define gc getchar
#define LL long long
using namespace std;
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
const int MAXN = 1000000;
const int MOD = 998244353;
int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * 1ll * a % MOD)
        if (b & 1)
            ans = ans * 1ll * a % MOD;
    return ans;
}
#define inv(x) (qpow(x, MOD - 2))
int A[MAXN], B[MAXN], eps[MAXN], ieps[MAXN];
void init(int len)
{
    for (int i = 0, l; (l = 1 << i) <= len; ++i)
        eps[i] = qpow(3, (MOD - 1) / l), ieps[i] = inv(eps[i]);
}
void NTT(int len, int *x, int *p)
{
    for (int i = 0, j = 0; i < len; ++i)
    {
        if (i > j)
            swap(x[i], x[j]);
        for (int l = len >> 1; (j ^= l) < l; l >>= 1)
            ;
    }
    for (int i = 1, l; (l = 1 << i) <= len; ++i)
    {
        int mid = l >> 1;
        for (int j = 0; j < len; j += l)
        {
            int w0 = 1;
            for (int k = j; k < j + mid; ++k)
            {
                int t = w0 * 1ll * x[k + mid] % MOD;
                x[k + mid] = (x[k] - t) % MOD;
                x[k] = (x[k] + t) % MOD;
                w0 = w0 * 1ll * p[i] % MOD;
            }
        }
    }
}
int F[MAXN], G[MAXN];
int f[MAXN], g[MAXN];
il void mul(int len, int *x, int *y)
{
    init(len);
    int I = inv(len);
    NTT(len, x, eps);
    NTT(len, y, eps);
    for (int i = 0; i < len; ++i)
        x[i] = x[i] * 1ll * y[i] % MOD;
    NTT(len, x, ieps);
    for (int i = 0; i < len; ++i)
        x[i] = x[i] * 1ll * I % MOD;
}
int main()
{
    int n;
    read(n);
    for (int i = 0; i < n; ++i)
        read(F[i]);
    G[0] = inv(F[0]);
    for (int l = 1; l < n;)
    {
        l <<= 1;
        int len = l << 1;
        fill(f, f + len + 1, 0);
        fill(g, g + len + 1, 0);
        for (int i = 0; i < l; ++i)
            f[i] = F[i],
            g[i] = G[i];
        mul(len, f, g);
        for (int i = 0; i < l; ++i)
            f[i] = -f[i];
        f[0] += 2;
        fill(f + l, f + len + 1, 0);
        fill(g, g + len + 1, 0);
        for (int i = 0; i < l; ++i)
            g[i] = G[i];
        mul(len, g, f);
        for (int i = 0; i < l; ++i)
            G[i] = g[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (G[i] < 0)
            G[i] += MOD;
        printf("%d ", G[i]);
    }
    return 0;
}