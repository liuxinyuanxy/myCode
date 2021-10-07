#include <cctype>
#include <cstdio>
#include <iostream>
#define gc getchar
#define il inline
#define re register
#define LL long long
using namespace std;
template <typename T>
void rd(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s = s * (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
    rd(s);
    rd(args...);
}
const int MAXN = 1000000;
int tot, top, fre[MAXN];
int rt;
int son[MAXN][2], fa[MAXN], val[MAXN], cnt[MAXN], sze[MAXN];
int new_node()
{
    return top ? fre[top--] : ++tot;
}
void update(int o)
{
    sze[o] = sze[son[o][0]] + sze[son[o][1]] + cnt[o];
}
void rotate(int x, int &k)
{
    int y = fa[x], z = fa[y];
    int l = son[y][1] == x, r = l ^ 1;
    if (y == k)
        k = x;
    else
        son[z][son[z][1] == y] = x;
    fa[x] = z;
    fa[y] = x;
    fa[son[x][r]] = y;
    son[y][l] = son[x][r];
    son[x][r] = y;
    update(y);
    update(x);
}
void splay(int x, int &k)
{
    int y, z;
    while (x != k)
    {
        y = fa[x], z = fa[y];
        if (y != k)
            rotate((son[y][1] == x ^ son[z][1] == y ? x : y), k);
        rotate(x, k);
    }
}
void insert(int &o, int x, int f)
{
    if (!o)
    {
        o = new_node();
        fa[o] = f;
        son[o][0] = son[o][1] = 0;
        sze[o] = cnt[o] = 1;
        val[o] = x;
        splay(o, rt);
        return;
    }
    if (x == val[o])
    {
        ++cnt[o];
        splay(o, rt);
    }
    else
        insert(son[o][x > val[o]], x, o);
}
void find(int x)
{
    int o = rt;
    while (val[o] != x)
        o = son[o][x > val[o]];
    splay(o, rt);
}
void merge(int l, int r)
{
    if (!l || !r)
    {
        rt = l ^ r;
        return;
    }
    int o = l;
    while (son[o][1])
        o = son[o][1];
    splay(o, l);
    fa[r] = l;
    son[l][1] = r;
    rt = l;
    update(rt);
}
void del(int x)
{
    find(x);
    if (cnt[rt] > 1)
    {
        --cnt[rt];
        --sze[rt];
        return;
    }
    fre[++top] = rt;
    fa[son[rt][0]] = fa[son[rt][1]] = 0;
    merge(son[rt][0], son[rt][1]);
}
int my_rank(int x)
{
    insert(rt, x, 0);
    int ans = sze[son[rt][0]] + 1;
    del(x);
    return ans;
}
int find_rank(int k)
{
    int o = rt;
    while (!(sze[son[o][0]] < k && sze[son[o][0]] + cnt[o] >= k))
    {
        if (sze[son[o][0]] + cnt[o] < k)
            k -= sze[son[o][0]] + cnt[o],
                o = son[o][1];
        else
            o = son[o][0];
    }
    splay(o, rt);
    return val[o];
}
int pre(int x)
{
    int o = rt, p;
    while (o)
        if (val[o] < x)
            p = o,
            o = son[o][1];
        else
            o = son[o][0];
    splay(p, rt);
    return val[rt];
}
int nxt(int x)
{
    int o = rt, p;
    while (o)
        if (val[o] > x)
            p = o,
            o = son[o][0];
        else
            o = son[o][1];
    splay(p, rt);
    return val[rt];
}
int main()
{
    int n, opt, x;
    rd(n);
    while (n--)
    {
        rd(opt, x);
        if (opt == 1)
            insert(rt, x, 0);
        else if (opt == 2)
            del(x);
        else if (opt == 3)
            printf("%d\n", my_rank(x));
        else if (opt == 4)
            printf("%d\n", find_rank(x));
        else if (opt == 5)
            printf("%d\n", pre(x));
        else
            printf("%d\n", nxt(x));
    }
    return 0;
}