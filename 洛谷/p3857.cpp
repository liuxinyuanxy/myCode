#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
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
LL Bit[60];
int sze;
void insert(LL x)
{
    for (int i = 50; i >= 0; --i)
        if (x & (1ll << i))
        {
            if (Bit[i])
                x ^= Bit[i];
            else
            {
                ++sze;
                Bit[i] = x;
                return;
            }
        }
}
int main()
{
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= m; ++i)
    {
        LL x = 0;
        char ch;
        for (int j = 1; j <= n; ++j)
        {
            while (!isalpha(ch = gc()))
                ;
            x = (x << 1) + (ch == 'O' ? 1 : 0);
        }
        insert(x);
    }
    cout << (1ll << sze) % 2008;
    return 0;
}