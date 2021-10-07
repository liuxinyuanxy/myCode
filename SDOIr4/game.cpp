#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#define il inilne
#define re register
#define gc getchar
#define file "game"
#ifdef DEBUG
#define F()
#else
#define F()                          \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
#endif
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
int main()
{
    int t;
    read(t);
    while (t--)
    {
        int n, m;
        read(n), read(m);
        }
}