#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define LL long long
#define gc() getchar()
// #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
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
#define ls son[x][0]
#define rs son[x][1]
const int N = 600005;
int fa[N], son[N][2];
il bool nrt(int x)
{
    return son[fa[x]][0] == x || son[fa[x]][1] == x;
}
il void rotate(int x)
{
    int y = fa[x], z = fa[y];
    int l = son[y][1] == x, &r = son[x][l ^ 1];
    if (nrt(y))
        son[z][son[z][1] == y] = x;
    fa[x] = z;
    fa[r] = y;
    son[y][l] = r;
    r = y;
    fa[y] = x;
}
il void splay(int x)
{
    int y, z;
    while (nrt(x))
    {
        y = fa[x], z = fa[y];
        if (nrt(y))
            rotate(son[y][1] == x ^ son[z][1] == y ? x : y);
        rotate(x);
    }
}
il void access(int x)
{
    for (int y = 0; x; x = fa[y = x])
        splay(x), rs = y;
}
il int findrt(int x)
{
    access(x), splay(x);
    while (ls)
        x = ls;
    splay(x);
    return x;
}
il void link(int x, int y)
{
    access(x), splay(x), fa[x] = y;
}
il void cut(int x, int y)
{
    access(x), splay(x), ls = fa[y] = 0;
}
int cnt;
int head[N], nxt[N], to[N], f[N];
il void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
il void dfs(int u)
{
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != f[u])
            f[v] = u, dfs(v);
}
int val[N];
int main()
{
    int n, m;
    read(n, m);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u, v);
        ins(u, v), ins(v, u);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i)
        link(i, f[i]);
    cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        char ch;
        while (!isalpha(ch = gc()))
            ;
        int u, v, x;
        if (ch == 'Q')
            read(u, v), printf(findrt(u) == findrt(v) ? "Yes\n" : "No\n");
        else if (ch == 'C')
            read(u, v), (f[u] != v ? swap(u, v) : void()), cut(u, v), val[++cnt] = u;
        else
            read(x), u = val[x], link(u, f[u]);
    }
    return 0;
}