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
const int N = 200005;
int son[N][2], fa[N], sze[N];
il void update(int x)
{
    sze[x] = sze[ls] + sze[rs] + 1;
}
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
    if (r)
        fa[r] = y;
    son[y][l] = r;
    r = y;
    fa[y] = x;
    update(y), update(x);
}
il void splay(int x)
{
    int y, z;
    while (nrt(x))
    {
        y = fa[x], z = fa[y];
        if (nrt(y))
            rotate(son[z][1] == y ^ son[y][1] == x ? x : y);
        rotate(x);
    }
}
il void access(int x)
{
    for (int y = 0; x; x = fa[y = x])
        splay(x), rs = y, update(x);
}
int n;
int val[N];
il void link(int u, int v)
{
    if (v > n)
        fa[u] = 0;
    else
        fa[u] = v;
}
il void cut(int u, int v)
{
    if (v > n)
        return;
    access(u), splay(v), son[v][1] = fa[u] = 0, update(v);
}
int main()
{
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        int u;
        read(u);
        link(i, val[i] = i + u);
        sze[i] = 1;
    }
    int m;
    read(m);
    for (int i = 1; i <= m; ++i)
    {
        int op, u, k;
        read(op, u);
        ++u;
        if (op == 1)
            access(u), splay(u), printf("%d\n", sze[u]);
        else
            read(k), cut(u, val[u]), link(u, val[u] = u + k);
    }
    return 0;
}