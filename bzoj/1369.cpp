#include <cctype>
#include <cstdio>
#include <iostream>
#define LL long long
#define il inline
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
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
    read(s), read(args...);
}
const int MAXN = 15000;
int cnt;
int head[MAXN], nxt[MAXN], to[MAXN];
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
int main()
{
    int n;
    read(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u, v);
        ins(u, v);
    }
    return 0;
}