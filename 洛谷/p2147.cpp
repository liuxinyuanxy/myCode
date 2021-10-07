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
#define swap(x, y) \
    int t = x;     \
    x = y;         \
    y = t
const int N = 600005;
int fa[N], son[N][2], tag[N];
il bool nrt(int x)
{
    return son[fa[x]][0] == x || son[fa[x]][1] == x;
}
il void pushr(int x)
{
    swap(ls, rs);
    tag[x] ^= 1;
}
il void pushdown(int x)
{
    if (tag[x])
    {
        tag[x] = 0;
        if (ls)
            pushr(ls);
        if (rs)
            pushr(rs);
    }
}
il void pusha(int x)
{
    if (nrt(x))
        pusha(fa[x]);
    pushdown(x);
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
    pusha(x);
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
il void makert(int x)
{
    access(x), splay(x), pushr(x);
}
il int findrt(int x)
{
    access(x), splay(x);
    while (ls)
        pushdown(x = ls);
    splay(x);
    return x;
}
il void link(int x, int y)
{
    makert(x), fa[x] = y;
}
il void cut(int x, int y)
{
    makert(x), access(y), splay(y);
    fa[x] = son[y][0] = 0;
}
il void getop(int &ans)
{
    char ch;
    while (!isalpha(ch = gc()))
        ;
    ans = (ch == 'C' ? 1 : ch == 'D' ? 2 : 3);
    while (isalpha(ch = gc()))
        ;
}
int main()
{
    int n, m;
    read(n, m);
    for (int i = 1; i <= m; ++i)
    {
        int op, u, v;
        getop(op), read(u, v);
        if (op == 1)
            link(u, v);
        else if (op == 2)
            cut(u, v);
        else
            printf(findrt(u) == findrt(v) ? "Yes\n" : "No\n");
    }
    return 0;
}