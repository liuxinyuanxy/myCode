#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define il inline
#define gc getchar
#define LL long long
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
int n, m, l, r;
const int N = 500000;
int c[N];
int head[N], nxt[N], to[N], val[N];
int dis[N];
int vis[N], sze[N], f[N], rt;
int cnt;
int S;
void ins(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
void find_rt(int u, int f)
{
    sze[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v] && v != f)
        {
            find_rt(v, u);
            sze[u] += sze[v];
            if (sze[v] > f[u])
                f[u] = sze[v];
        }
    f[u] = max(f[u], S - sze[u]);
    if (f[u] < f[rt])
        rt = u;
}
void calc(int u)
{
}
void solve(int u)
{
}
int main()
{
    read(n, m, l, r);
    for (int i = 1; i <= m; ++i)
        read(c[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        read(u, v, w);
        ins(u, v, w);
        ins(v, u, w);
    }
    solve(1);
    return 0;
}