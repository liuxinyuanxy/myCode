#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define LL long long
// #define gc() getchar()
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
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
#define add(x, y) ((x) + (y)) % MOD
#define mul(x, y) ((x)*1ll * (y)) % MOD
const int N = 100005;
const int MOD = 51061;
int son[N][2], fa[N], val[N], sum[N], tag1[N], tag2[N], tag[N], sze[N];
il void pushr(int x)
{
    tag[x] ^= 1;
    swap(ls, rs);
}
il void pusha(int x, int d)
{
    val[x] = add(val[x], d);
    tag1[x] = add(tag1[x], d);
    sum[x] = add(sum[x], mul(d, sze[x]));
}
il void pushm(int x, int d)
{
    val[x] = mul(val[x], d);
    tag1[x] = mul(tag1[x], d);
    tag2[x] = mul(tag2[x], d);
    sum[x] = mul(sum[x], d);
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
    if (tag2[x] != 1)
    {
        int c = tag2[x];
        tag2[x] = 1;
        if (ls)
            pushm(ls, c);
        if (rs)
            pushm(rs, c);
    }
    if (tag1[x])
    {
        int c = tag1[x];
        tag1[x] = 0;
        if (ls)
            pusha(ls, c);
        if (rs)
            pusha(rs, c);
    }
}
il void update(int x)
{
    sze[x] = sze[ls] + sze[rs] + 1;
    sum[x] = add(add(sum[ls], sum[rs]), val[x]);
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
void pushall(int x)
{
    if (nrt(x))
        pushall(fa[x]);
    pushdown(x);
}
il void splay(int x)
{
    pushall(x);
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
il void makert(int x)
{
    access(x), splay(x);
    pushr(x);
}
il void split(int x, int y)
{
    makert(x), access(y);
    splay(y);
}
il void link(int x, int y)
{
    makert(x);
    fa[x] = y;
}
il void cut(int x, int y)
{
    split(x, y);
    fa[x] = son[y][0] = 0;
    update(y);
}
int main()
{
    int n, q;
    read(n, q);
    for (int i = 1; i <= n; ++i)
        tag2[i] = val[i] = 1;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u, v);
        link(u, v);
    }
    for (int i = 1; i <= q; ++i)
    {
        char ch;
        int u, v, c, d;
        while (isspace(ch = gc()))
            ;
        read(u, v);
        if (ch == '+')
            read(c), split(u, v), pusha(v, c);
        else if (ch == '-')
            read(c, d), cut(u, v), link(c, d);
        else if (ch == '*')
            read(c), split(u, v), pushm(v, c);
        else
            split(u, v), printf("%d\n", sum[v]);
    }
    return 0;
}