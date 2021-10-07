#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
const LL MOD = 999911659;
LL qpow(LL a, LL b, LL mod)
{
    LL ans = 1;
    for (; b; b >>= 1, a = (a * a) % mod)
        if (b & 1)
            ans = (ans * a) % mod;
    return ans;
}
const int MAXN = 40000;
const int p[] = {2, 3, 4679, 35617};
LL a[4];
LL fac[4][MAXN], invfac[4][MAXN];
void init_lucas()
{
    for (int k = 0; k < 4; ++k)
    {
        fac[k][0] = 1;
        for (int i = 1; i < p[k]; ++i)
            fac[k][i] = fac[k][i - 1] * i % p[k];
        invfac[k][p[k] - 1] = qpow(fac[k][p[k] - 1], p[k] - 2, p[k]);
        for (int i = p[k] - 2; i >= 0; --i)
            invfac[k][i] = invfac[k][i + 1] * (i + 1) % p[k];
    }
}
LL lucas(int n, int m, int k)
{
    if (m > n)
        return 0;
    // cout << n << "\t" << m << endl;
    if (n < p[k])
        return fac[k][n] * invfac[k][m] % p[k] * invfac[k][n - m] % p[k];
    return lucas(n % p[k], m % p[k], k) * lucas(n / p[k], m / p[k], k) % p[k];
}
LL C(LL n, LL m)
{
    LL s = 1;
    for (int i = 0; i < 4; ++i)
    {
        a[i] = lucas(n, m, i);
        s *= p[i];
    }
    LL ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        ans += s / p[i] * a[i] * qpow(s / p[i], p[i] - 2, p[i]), ans %= s;
    }
    return ans;
}
int main()
{
    LL n, g;
    cin >> n >> g;
    init_lucas();
    LL ans = 0;
    for (LL i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans += C(n, i);
            if (i * i != n)
                ans += C(n, n / i);
        }
    }
    printf("%lld", qpow(g, ans, MOD));
    return 0;
}