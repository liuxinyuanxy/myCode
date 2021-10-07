#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <random>
#include <set>
#include <vector>
#define il inline
#define re register
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
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int N = 405;
const int MOD = 1000000007;
int g[N][N];
int inv[N][N];
int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * 1ll * a % MOD)
        if (b & 1)
            ans = ans * 1ll * a % MOD;
    return ans;
}
#define inv(x) (qpow(x, MOD - 2))
set<int> S;
int main()
{
    int n;
    read(n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            read(g[i][j]);
    for (int i = 1; i <= n; ++i)
        inv[i][i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int idx = i;
        for (int j = i; j <= n; ++j)
            if (g[j][i])
            {
                idx = j;
                break;
            }
        if (idx != i)
            swap(g[i], g[idx]), swap(inv[i], inv[idx]);
        if (!g[i][i])
        {
            puts("No Solution");
            return 0;
        }
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            int temp = g[j][i] * 1ll * inv(g[i][i]) % MOD;
            for (int k = 1; k <= n; ++k)
                g[j][k] = (g[j][k] - temp * 1ll * g[i][k] % MOD) % MOD, inv[j][k] = (inv[j][k] - temp * 1ll * inv[i][k] % MOD) % MOD;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int temp = inv(g[i][i]);
        g[i][i] = g[i][i] * 1ll * temp % MOD;
        for (int j = 1; j <= n; ++j)
            inv[i][j] = inv[i][j] * 1ll * temp % MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (inv[i][j] < 0)
                inv[i][j] += MOD;
            printf("%d ", inv[i][j]);
        }
        printf("\n");
    }
    return 0;
}