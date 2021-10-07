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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
const int N = 2000;
const int M = 800005;
struct edge
{
    int u, v;
} E[M];
struct que
{
    int op, u, v;
} Q[M];
int cut[N][N];
int val[N][N];
il bool cmp(const edge &x, const edge &y)
{
    return val[x.u][x.v] < val[y.u][y.v];
}
class lct
{
private:
    static const int N = 200000;
    int son[N][2], fa[N], tag[N];
    int sum[N], val[N];
    il bool nrt(int x)
    {
        return son[fa[x]][0] == x || son[fa[x]][1] == x;
    }
    il void update(int x)
    {
        sum[x] = max(val[x], max(sum[ls], sum[rs]));
    }
    il void pushr(int x)
    {
        tag[x] ^= 1;
        swap(ls, rs);
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
        update(y), update(x);
    }
    il void splay(int x)
    {
        pusha(x);
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
    il int findrt(int x)
    {
        access(x), splay(x);
        while (ls)
            pushdown(x = ls);
        splay(x);
        return x;
    }
    il void makert(int x)
    {
        access(x), splay(x), pushr(x);
    }

public:
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
    il void cut(int x, int y)
    {
        split(x, y);
        fa[x] = son[y][0] = 0;
        update(y);
    }
} LCT;
int main()
{
    int n, m, q;
    read(n, m, q);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        read(u, v, w);
        val[u][v] = val[v][u] = w;
        E[i] = edge{u, v};
    }
    for (int i = 1; i <= q; ++i)
    {
        int op, u, v;
        read(op, u, v);
        Q[i] = que{op, u, v};
        if (op == 2)
            cut[u][v] = cut[v][u] = 1;
    }
    sort(E + 1, E + 1 + m, cmp);
    for (int i = 1; i <= m; ++i)
    {
        int u = E[i].u, v = E[i].v;
        if (!cut[u][v])
            link(u, v);
    }
    return 0;
}