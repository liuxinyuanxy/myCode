#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define gc getchar
#define re register
#define LL long long
#define file ""
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#define F()
#else
#define D()
#define F()                          \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
#endif
using namespace std;
const int MOD = 1000003;
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
const int MAXN = 150;
int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * 1ll * a % MOD)
        if (b & 1)
            ans = ans * 1ll * a % MOD;
    return ans;
}
struct Mat
{
    int n, m;
    int g[MAXN][MAXN];
    Mat(int _n = 0, int _m = 0) : n(_n), m(_m)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                g[i][j] = 0;
    }
    int gauss()
    {
        int ans = 1;
        for (int i = 2; i <= n; ++i)
        {
            int idx = i;
            for (int j = i + 1; j <= n; ++j)
                if (g[j][i])
                {
                    idx = j;
                    break;
                }
            if (idx != i)
            {
                ans *= -1;
                for (int j = 2; j <= n; ++j)
                    swap(g[i][j], g[idx][j]);
            }
            for (int j = 2; j <= n; ++j)
            {
                if (i == j)
                    continue;
                int temp = qpow(g[i][i], MOD - 2) * 1ll * g[j][i] % MOD;
                for (int k = i; k <= n; ++k)
                {
                    g[j][k] -= g[i][k] * 1ll * temp % MOD;
                    if (g[j][k] < 0)
                        g[j][k] += MOD;
                }
            }
            ans = ans * 1ll * g[i][i] % MOD;
        }
        if (ans < 0)
            ans += MOD;
        return ans;
    }
} M;
int fra[200005];
int deg[MAXN];
int n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fra[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        fra[i] = fra[i - 1] * 1ll * i % MOD;
    while (read(n), n)
    {
        M.n = M.m = n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                M.g[i][j] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int s;
            read(s);
            deg[i] = s;
            for (int j = 1; j <= s; ++j)
            {
                int x;
                read(x);
                ++M.g[i][i], --M.g[i][x];
            }
        }
        if (n == 1)
        {
            cout << fra[deg[1]] << endl;
            continue;
        }
        int ans = M.gauss();
        for (int i = 1; i <= n; ++i)
            ans = ans * 1ll * fra[deg[i] - 1] % MOD;
        ans = ans * 1ll * deg[1] % MOD;
        cout << ans << endl;
    }
    return 0;
}