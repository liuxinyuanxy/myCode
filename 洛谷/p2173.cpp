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
void read(T &s, Args &...args)
{
    read(s), read(args...);
}
#define ls son[x][0]
#define rs son[x][1]
#define swap(x, y) \
    int t = x;     \
    x = y;         \
    y = t
struct LCT
{
    static const int N = 200005;
    int son[N][2], fa[N], val[N], sum[N], tag[N], sze[N];
    il void update(int x)
    {
        sum[x] = max(max(sum[ls], sum[rs]), val[x]);
    }
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
        if (x <= 0)
        {
            cout << "?????!!!";
            cout << x << endl;
        }
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
        ++sze[x], ++sze[y];
        return 1;
    }
    il bool cut(int x, int y)
    {
        makert(x);
        if (findrt(y) != x || fa[y] != x || son[y][0])
            return 0;
        rs = fa[y] = 0;
        update(x);
        --sze[x], --sze[y];
        return 1;
    }
} lct[10];
int main()
{
    int n, m, c, k;
    read(n, m, c, k);
    for (int i = 1; i <= n; ++i)
    {
        int w;
        read(w);
        for (int j = 0; j < c; ++j)
            lct[j].val[i] = lct[j].sum[i] = w;
    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        read(u, v, w);
        lct[w].link(u, v);
    }
    for (int i = 1; i <= k; ++i)
    {
        int op, u, v, w;
        read(op, u, v);
        if (op == 0)
            for (int j = 0; j < c; ++j)
                lct[j].splay(u), lct[j].val[u] = v, lct[j].update(u);
        else if (op == 1)
        {
            read(w);
            int t = -1;
            for (int j = 0; j < c; ++j)
                if (lct[j].cut(u, v))
                {
                    t = j;
                    break;
                }
            if (!~t)
            {
                printf("No such edge.\n");
                continue;
            }
            if (lct[w].sze[u] == 2 || lct[w].sze[v] == 2)
            {
                printf("Error 1.\n");
                lct[t].link(u, v);
                continue;
            }
            if (!lct[w].link(u, v))
            {
                printf("Error 2.\n");
                lct[t].link(u, v);
                continue;
            }
            printf("Success.\n");
        }
        else
        {
            read(w);
            swap(u, w);
            if (lct[w].findrt(u) != lct[w].findrt(v))
                printf("-1\n");
            else
                lct[w].split(u, v), printf("%d\n", lct[w].sum[v]);
        }
    }
    return 0;
}