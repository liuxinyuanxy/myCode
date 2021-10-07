#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define LL long long
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
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
    read(s), read(args...);
}
int main()
{
    for (int i = 1; i <= 30; ++i)
    {
        LL ans = 0;
        for (int j = 1; j <= i; ++j)
        {
            LL p = 1;
            for (int k = 1; k <= i; ++k)
                p *= j;
            ans += p;
        }
        cout << ans << ",";
    }
    return 0;
}