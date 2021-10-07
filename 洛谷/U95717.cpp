#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define gc getchar
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
        s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
    read(s), read(args...);
}
int main()
{
    int q;
    read(q);
    for (int i = 1; i <= q; ++i)
    {
        int a, b, c, d, n;
        read(n, a, b, c, d);
        printf("%.0lf\n", pow(1 + double(a) / (n + b), (double)c * n + d));
    }
    return 0;
}