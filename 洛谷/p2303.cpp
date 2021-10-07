#include <cctype>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define LL long long
#define gc getchar
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
int phi(LL x)
{
    LL ans = x;
    for (LL i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            ans -= ans / i;
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        ans -= ans / x;
    return ans;
}
int main()
{
    LL n;
    rd(n);
    LL ans = 0;
    for (LL i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans += i * phi(n / i);
            if (n / i != i)
                ans += (n / i) * phi(i);
        }
    }
    cout << ans;
    return 0;
}