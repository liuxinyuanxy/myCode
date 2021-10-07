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
const int MAXN = 1200000;
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
il void clear(int *x, int len)
{
    for (int i = 0; i <= len; ++i)
        x[i] = 0;
}
int a[MAXN], b[MAXN];
int ans[MAXN];
vector<int> v;
int main()
{
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
    {
        char ch;
        while (iscntrl(ch = gc()))
            ;
        if (ch == '*')
            b[i] = 0;
        else
            b[i] = ch - 'a' + 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        char ch;
        while (iscntrl(ch = gc()))
            ;
        if (ch == '*')
            a[i] = 0;
        else
            a[i] = ch - 'a' + 1;
    }
    int len = 1;
    while (len <= n + m)
        len <<= 1;
    init(len);
    for (int i = 1; i <= m; ++i)
        A[i] = a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i] = b[i] * b[i] * b[i];
    NTT(len, A, eps);
    NTT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        ans[i] = (ans[i] + A[i] * 1ll * B[i] % MOD) % MOD;
    clear(A, len);
    clear(B, len);
    for (int i = 1; i <= m; ++i)
        A[i] = a[i] * a[i] * a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i] = b[i];
    NTT(len, A, eps);
    NTT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        ans[i] = (ans[i] + A[i] * 1ll * B[i] % MOD) % MOD;
    clear(A, len);
    clear(B, len);
    for (int i = 1; i <= m; ++i)
        A[i] = a[i] * a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i] = b[i] * b[i];
    NTT(len, A, eps);
    NTT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        ans[i] = (ans[i] - A[i] * 2ll * B[i] % MOD) % MOD;
    NTT(len, ans, ieps);

    for (int i = 0; i <= m - n; ++i)
        if (ans[i + n] == 0)
            v.push_back(i + 1);
    printf("%lu\n", v.size());
    for (auto x : v)
        printf("%d ", x);
    return 0;
}