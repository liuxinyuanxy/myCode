#include <algorithm>
#include <cstdio>
#include <iostream>
#define il inline
#define gc getchar
#define LL long long
#define re register
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 230000;
int n;
class Bit
{
public:
#define lowbit(x) ((x) & -(x))
    LL del1[MAXN], del2[MAXN];
    LL sum[MAXN];
    il void add(int p, LL x, LL *tree)
    {
        for (; p <= n; p += lowbit(p))
            tree[p] += x;
    }
    il LL que(int p, LL *tree)
    {
        LL ans = 0;
        for (; p; p -= lowbit(p))
            ans += tree[p];
        return ans;
    }
    il void modify(int l, int r, int v)
    {
        add(l, v, del1), add(r + 1, -v, del1);
        add(l, v * 1ll * l, del2), add(r + 1, -v * 1ll * (r + 1), del2);
    }
    il LL query_(int r)
    {
        return sum[r] + (r + 1) * 1ll * que(r, del1) - que(r, del2);
    }
    il LL query(int l, int r)
    {
        return query_(r) - query_(l - 1);
    }
} B;
int cnt, rt = 1;
int val[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], fa[MAXN], top[MAXN], dis[MAXN], sze[MAXN], son[MAXN];
int pos[MAXN], tot;
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void dfs(int u)
{
    sze[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u])
        {
            fa[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
            if (sze[v] > sze[son[u]])
                son[u] = v;
            sze[u] += sze[v];
        }
}
void dfs2(int u, int t)
{
    pos[u] = ++tot;
    B.sum[tot] = B.sum[tot - 1] + val[u];
    top[u] = t;
    if (son[u])
        dfs2(son[u], t);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}
int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dis[top[u]] < dis[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dis[u] < dis[v] ? u : v;
}
int get(int u)
{
    int v = rt;
    while (top[v] != top[u])
    {
        if (fa[top[v]] == u)
            return top[v];
        v = fa[top[v]];
    }
    return son[u];
}
void modify(int u, int v, int w)
{
    while (top[u] != top[v])
    {
        if (dis[top[u]] < dis[top[v]])
            swap(u, v);
        B.modify(pos[top[u]], pos[u], w);
        u = fa[top[u]];
    }
    if (pos[u] > pos[v])
        swap(u, v);
    B.modify(pos[u], pos[v], w);
}
LL query(int u, int v)
{
    LL ans = 0;
    while (top[u] != top[v])
    {
        if (dis[top[u]] < dis[top[v]])
            swap(u, v);
        ans += B.query(pos[top[u]], pos[u]);
        u = fa[top[u]];
    }
    if (pos[u] > pos[v])
        swap(u, v);
    ans += B.query(pos[u], pos[v]);
    return ans;
}
int main()
{
    read(n);
    for (int i = 1; i <= n; ++i)
        read(val[i]);
    for (int i = 1; i < n; ++i)
    {
        int u;
        read(u);
        ins(u, i + 1);
    }
    dfs(1), dfs2(1, 1);
    int m;
    int opt, u, v, k;
    read(m);
    for (int i = 1; i <= m; ++i)
    {
        read(opt), read(u);
        if (opt == 1)
            rt = u;
        else if (opt == 2)
            read(v), read(k), modify(u, v, k);
        else if (opt == 4)
            read(v), printf("%lld\n", query(u, v));
        else if (opt == 3)
        {
            read(k);
            if (u == rt)
                B.modify(1, n, k);
            else if (lca(u, rt) != u)
                B.modify(pos[u], pos[u] + sze[u] - 1, k);
            else
                v = get(u), B.modify(1, pos[v] - 1, k), B.modify(pos[v] + sze[v], n, k);
        }
        else
        {
            LL ans = 0;
            if (u == rt)
                ans = B.query(1, n);
            else if (lca(u, rt) != u)
                ans = B.query(pos[u], pos[u] + sze[u] - 1);
            else
                v = get(u), ans = B.query(1, pos[v] - 1) + B.query(pos[v] + sze[v], n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}