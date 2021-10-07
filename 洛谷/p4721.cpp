#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define il inline
#define gc getchar
#define LL long long
#define re register
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
const int MOD = 998244353;
const int MAXN = 1000000;
int eps[MAXN], ieps[MAXN];
il int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * 1ll * a)
        if (b & 1)
            ans = ans * 1ll * a % MOD;
    return ans;
}
#define inv(x) (qpow(x, MOD - 2))
il void init(int len)
{
    for (int i = 0, l; (l = 1 << i) <= len; ++i)
        eps[i] = qpow(3, (MOD - 1) / l), ieps[i] = inv(eps[i]);
}
il void NTT(int len, int *x, int *p)
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
                t = t * 1ll * p[i] % MOD;
            }
        }
    }
}
il void mul(int len, int *a, int *b)
{
    init(len);
    NTT(len, a, eps);
    NTT(len, b, eps);
    for (int i = 0; i < len; ++i)
        a[i] = a[i] * 1ll * b[i] % MOD;
    NTT(len, a, ieps);
    int I = inv(len);
    for (int i = 0; i < len; ++i)
        a[i] = a[i] * 1ll * I % MOD;
}
int g[MAXN], ans[MAXN];
int F[MAXN], G[MAXN];
void solve(int len, int *f)
{
    int mid = len >> 1;
    solve(mid, f);
    for (int i = 0; i < mid; ++i)
        F[i] = f[i];
}
int main()
{
    int n;
    read(n);
    for (int i = 1; i < n; ++i)
        read(g[i]);
    ans[0] = 1;
    solve(n, ans);
    return 0;
}