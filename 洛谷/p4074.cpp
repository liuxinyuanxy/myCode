#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define il inline
#define gc getchar
#define LL long long
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
const int N = 300000;
int cnt, tot;
int head[N], nxt[N], to[N], seq[N], pos[N];
int fa[N], top[N], dep[N], sze[N], son[N];
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void dfs(int u)
{
    dep[u] = dep[fa[u]] + (sze[u] = 1);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u])
        {
            fa[v] = u, dfs(v), sze[u] += sze[v];
            if (sze[v] > sze[son[u]])
                son[u] = v;
        }
}
void dfs(int u, int t)
{
    seq[pos[u] = ++tot] = u;
    top[u] = t;
    if (son[u])
        dfs(son[u], t);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u] && v != son[u])
            dfs(v, v);
    seq[++tot] = u;
}
int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
int v[N], w[N], c[N], cc[N];
int vis[N], S[N];
LL ans[N], sum;
struct que
{
    int l, r, t, x, y, id;
} Q[N];
struct mo
{
    int u, f, t;
} M[N];
int be[N];
bool cmp(const que &x, const que &y)
{
    return be[x.l] ^ be[y.l] ? be[x.l] < be[y.l] : be[x.r] ^ be[y.r] ? be[x.r] < be[y.r] : x.t < y.t;
}
void add(int u, int x)
{
    vis[u] ? (sum -= v[x] * 1ll * w[S[x]], --S[x]) : (++S[x], sum += v[x] * 1ll * w[S[x]]);
    vis[u] ^= 1;
}
void modify(int u, int f, int t)
{
    c[u] = t;
    if (vis[u])
    {
        sum -= v[f] * 1ll * w[S[f]];
        --S[f];
        ++S[t];
        sum += v[t] * 1ll * w[S[t]];
    }
}
int main()
{
    int n, m, q, s1 = 0, s2 = 0;
    read(n, m, q);
    for (int i = 1; i <= m; ++i)
        read(v[i]);
    for (int i = 1; i <= n; ++i)
        read(w[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u, v);
        ins(u, v), ins(v, u);
    }
    dfs(1), dfs(1, 1);
    int block = pow(tot, 2.0 / 3);
    for (int i = 1; i <= tot; ++i)
        be[i] = (i - 1) / block + 1;
    for (int i = 1; i <= n; ++i)
        read(c[i]), cc[i] = c[i];
    for (int i = 1; i <= q; ++i)
    {
        int type, x, y;
        read(type, x, y);
        if (type == 0)
            ++s2, M[s2].u = x, M[s2].f = cc[x], M[s2].t = y, cc[x] = y;
        else
        {
            ++s1;
            if (pos[x] > pos[y])
                swap(x, y);
            Q[s1] = que{pos[x], pos[y], s2, x, y, s1};
        }
    }
    sort(Q + 1, Q + 1 + s1, cmp);
    for (int i = 1; i <= Q[1].t; ++i)
        c[M[i].u] = M[i].t;
    for (int i = Q[1].l; i <= Q[1].r; ++i)
        add(seq[i], c[seq[i]]);
    int L = Q[1].l, R = Q[1].r, T = Q[1].t;
    for (int i = 1; i <= s1; ++i)
    {
        while (L > Q[i].l)
            --L, add(seq[L], c[seq[L]]);
        while (L < Q[i].l)
            add(seq[L], c[seq[L]]), ++L;
        while (R < Q[i].r)
            ++R, add(seq[R], c[seq[R]]);
        while (R > Q[i].r)
            add(seq[R], c[seq[R]]), --R;
        while (T < Q[i].t)
            ++T, modify(M[T].u, M[T].f, M[T].t);
        while (T > Q[i].t)
            modify(M[T].u, M[T].t, M[T].f), --T;
        int L = lca(Q[i].x, Q[i].y);
        add(Q[i].x, c[Q[i].x]);
        add(L, c[L]);
        ans[Q[i].id] = sum;
        add(L, c[L]);
        add(Q[i].x, c[Q[i].x]);
    }
    for (int i = 1; i <= s1; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}