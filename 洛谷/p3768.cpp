#include <cstdio>
#include <iostream>
#define gc getchar
#define LL long long
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
LL p;
const LL N = 10000000000ll;
const int MAXN = 10000000;
LL inv2, inv4, inv6;
LL s[MAXN];
LL si[MAXN + 5];
int pri[MAXN], cnt, vis[MAXN + 5];
LL qpow(LL a, LL b)
{
    LL ans = 1;
    for (; b; b >>= 1, a = (a * a) % p)
        if (b & 1)
            ans = (ans * a) % p;
    return ans;
}
void init()
{
    si[1] = 1;
    for (int i = 2; i <= MAXN; ++i)
    {
        if (!vis[i])
            pri[++cnt] = i, si[i] = i - 1;
        for (int j = 1; j <= cnt && i * pri[j] <= MAXN; ++j)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j])
                si[i * pri[j]] = si[i] * si[pri[j]] % p;
            else
            {
                si[i * pri[j]] = si[i] * pri[j] % p;
                break;
            }
        }
    }
    for (LL i = 1; i <= MAXN; ++i)
        si[i] = (si[i - 1] + i % p * si[i] % p * i % p),
        si[i] %= p;
}
LL sqr(LL x)
{
    return ((x) % p * ((x) % p + 1) % p * (2 * (x) % p + 1) % p * inv6 % p) % p;
}
LL S(LL n)
{
    if (n <= MAXN)
        return si[n];
    LL &x = s[N / n];
    if (!x)
    {
        x = (n % p * n % p * ((n + 1) % p * (n + 1) % p) % p) * inv4 % p;
        for (LL l = 2, r; l <= n; l = r + 1)
        {
            r = n / (n / l);
            x = (x - S(n / l) * ((sqr(r) % p - sqr(l - 1) % p) % p) % p) % p;
            if (x < 0)
                x += p;
        }
    }
    return x % p;
}
LL sum(LL x)
{
    return ((1 + (x) % p) % p * (x) % p * inv2 % p) % p;
}
void print(LL a)
{
    if (a)
    {
        print(a / 10);
        putchar('0' + a % 10);
    }
}
int main()
{
    LL n;
    rd(p, n);
    inv2 = qpow(2, p - 2);
    inv4 = qpow(4, p - 2);
    inv6 = qpow(6, p - 2);
    init();
    LL ans = 0;

    for (LL l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        LL t = sum(n / l);
        ans += (S(r) % p - S(l - 1) % p) % p * t % p * t % p;
        ans %= p;
        if (ans < 0)
            ans += p;
    }
    print(ans);
}