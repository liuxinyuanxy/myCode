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
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
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
const int N = 200000;
int son[N][2], fa[N], tag[N], sum[N], val[N];
#define ls son[x][0]
#define rs son[x][1]
il void update(int x)
{
    sum[x] = sum[ls] ^ sum[rs] ^ val[x];
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
il bool nrt(int x)
{
    return son[fa[x]][0] == x || son[fa[x]][1] == x;
}
il void rotate(int x)
{
    int y = fa[x], z = fa[y];
    int l = son[y][1] == x, r = l ^ 1;
    if (nrt(y))
        son[z][son[z][1] == y] = x;
    fa[x] = z;
    if (son[x][r])
        fa[son[x][r]] = y;
    son[y][l] = son[x][r];
    son[x][r] = y;
    fa[y] = x;
    update(y), update(x);
}
// void pushall(int x)
// {
//     if (nrt(x))
//         pushall(fa[x]);
//     pushdown(x);
// }
int st[N];
il void splay(int x)
{
    // pushall(x);
    int y, z;
    st[z = 1] = y = x;
    while (nrt(y))
        st[++z] = y = fa[y];
    while (z)
        pushdown(st[z--]);
    while (nrt(x))
    {
        y = fa[x], z = fa[x];
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
il void split(int x, int y)
{
    makert(x), access(y), splay(y);
}
il bool link(int x, int y)
{
    makert(x);
    if (findrt(y) == x)
        return 0;
    fa[x] = y;
    return 1;
}
il bool cut(int x, int y)
{
    makert(x);
    if (findrt(y) != x || fa[y] != x || son[y][0])
        return 0;
    fa[y] = rs = 0;
    update(x);
    return 1;
}
int main()
{
    int n, m;
    read(n, m);
    for (int i = 1; i <= n; ++i)
        read(val[i]);
    for (int i = 1; i <= m; ++i)
    {
        int op, x, y;
        read(op, x, y);
        if (op == 0)
            split(x, y), printf("%d\n", sum[y]);
        else if (op == 1)
            link(x, y);
        else if (op == 2)
            cut(x, y);
        else
            splay(x), val[x] = y, update(x);
    }
    return 0;
}