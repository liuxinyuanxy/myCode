#include <cstdio>
#include <iostream>
#define gc getchar
#define re register
#define il inline
using namespace std;
const int MAX = 100000;
int cnt, rt;
int ansp, ansn;
struct node
{
    int son[2];
    int sze, cnt;
    int val, fa;
}st[MAX];
il void push_up(int x)
{
    st[x].sze = st[st[x].son[0]].sze + st[st[x].son[1]].sze + st[x].cnt;
}
void rotate(int x, int& k)
{
    int y, z;
    y = st[x].fa;
    z = st[y].fa;
    int l, r;
    l = st[y].son[1] == x;
    r = l ^ 1;
    if (k == y)
        k = x;
    else
        st[z].son[int(st[z].son[1] == y)] = x;
    st[x].fa = z;
    st[y].fa = x;
    st[st[x].son[r]].fa = y;
    st[y].son[l] = st[x].son[r];
    st[x].son[r] = y;
    push_up(y);
    push_up(x);
}
void splay(int x, int& k)
{
    int y, z;
    while (x != k)
    {
        y = st[x].fa;
        z = st[y].fa;
        if (y != k)
        {
            if ((st[z].son[0] == y) ^ (st[y].son[0] == x))
                rotate(x, k);
            else
                rotate(y, k);
        }
        rotate(x, k);
    }
}
void insert(int& o, int k, int f)
{
    if (!o)
        o = ++cnt,
        st[o].cnt = 1,
        st[o].sze = 1,
        st[o].val = k,
        st[o].fa = f,
        splay(o, rt);
    else
        if (k == st[o].val)
            ++st[o].cnt,
            splay(o, rt);
        else
            if (k < st[o].val)
                insert(st[o].son[0], k, o);
            else
                insert(st[o].son[1], k, o);
    push_up(o);
}
void find(int x)
{
    int o = rt;
    while (st[o].val != x)
        o = st[o].son[st[o].val < x];
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
    while (st[o].son[1])
        o = st[o].son[1];
    splay(o, l);
    rt = l;
    st[rt].son[1] = r;
    st[r].fa = l;
    push_up(rt);
}
void del(int x)
{
    find(x);
    if (st[rt].cnt > 1)
    {
        --st[rt].cnt;
        --st[rt].sze;
        return;
    }
    st[st[rt].son[0]].fa = st[st[rt].son[1]].fa = 0;
    merge(st[rt].son[0], st[rt].son[1]);
}
int my_rank(int k)
{
    insert(rt, k, 0);
    int ans = st[st[rt].son[0]].sze + 1;
    del(k);
    return ans;
}
int find_rank(int k)
{
    int o = rt;
    int ans = 0;
    while (true)
    {
        if (ans + st[st[o].son[0]].sze >= k)
            o = st[o].son[0];
        else
        {
            ans += st[st[o].son[0]].sze + st[o].cnt;
            if (ans >= k)
                return st[o].val;
            o = st[o].son[1];
        }
    }
}
int pre(int x)
{
    int o = rt, ans = 0;
    while (o)
        if (st[o].val < x)
            ans = o,
            o = st[o].son[1];
        else
            o = st[o].son[0];
    return st[ans].val;
}
int nxt(int x)
{
    int o = rt, ans = 0;
    while (o)
        if (st[o].val > x)
            ans = o,
            o = st[o].son[0];
        else
            o = st[o].son[1];
    return st[ans].val;
}
template <typename T> void rd(T& s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
        ;
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
        ;
    s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
    rd(s);
    rd(args...);
}
int main()
{
    int opt, x;
    int n;
    rd(n);
    for (int i = 1; i <= n; ++i)
    {
        rd(opt, x);
        if (opt == 1)
            insert(rt, x, 0);
        if (opt == 2)
            del(x);
        if (opt == 3)
            printf("%d\n", my_rank(x));
        if (opt == 4)
            printf("%d\n", find_rank(x));
        if (opt == 5)
            printf("%d\n", pre(x));
        if (opt == 6)
            printf("%d\n", nxt(x));
    }
    return 0;
}