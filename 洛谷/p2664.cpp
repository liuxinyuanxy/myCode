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
#define rep(a, l, r) for (int a = (l); a <= (r); ++a)
#define tra(a, u, v) for (int a = head[u], v; v = e[a].to, a; a = e[a].nxt)
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
const int N = 200005;
const int INF = 0x7fffffff;
struct edge
{
    int to, nxt;
} e[N];
int cnt;
int head[N];
int sum[N], c[N];
int rt;
int sze[N], f[N], vis[N], col[N], S;
void ins(int u, int v)
{
    e[++cnt].nxt = head[u];
    head[u] = cnt;
    e[cnt].to = v;
}
void find_rt(int u, int fa)
{
    sze[u] = 1, f[u] = 0;
    tra(i, u, v) if (!vis[v] && v != fa)
    {
        find_rt(v, u);
        sze[u] += sze[v];
        if (sze[v] > f[u])
            f[u] = sze[v];
    }
    f[u] = max(f[u], S - sze[u]);
    if (f[u] < f[rt])
        rt = u;
}
int dis[N];
int qu[N], r;
void dfs(int u, int fa)
{
    sze[u] = 1;
    if (!col[c[u]])
        qu[r++] = u, col[c[u]] = 1;
    tra(i, u, v) if (!vis[v] && v != fa)
        dis[v] = dis[u] + 1,
        dfs(v, u),
        sze[u] += sze[v];
}
void give_tag(int u, int fa, int T, int T2)
{
    if (col[c[u]])
        col[c[u]] = 0, T += T2;
    sum[u] += T;
    tra(i, u, v) if (!vis[v] && v != fa)
        give_tag(v, u, T, T2);
}
void solve(int u)
{
    int Tag = sze[u];
    col[c[u]] = 1;
    vis[u] = 1;
    tra(i, u, v) if (!vis[v])
    {
        r = 0;
        dfs(v, u);
        int tag = -sze[v];
        rep(j, 0, r - 1)
            Tag += sze[qu[j]],
            tag -= sze[qu[j]];
        give_tag(v, u, tag, sze[u] - sze[v]);
    }
    give_tag(u, -1, Tag, 0);
    col[c[u]] = 0;
    tra(i, u, v) if (!vis[v])
        S = sze[v],
        f[rt = 0] = INF, find_rt(v, u), solve(rt);
}
int main()
{
    int n;
    read(n);
    rep(i, 1, n)
        read(c[i]);
    S = n;
    rep(i, 2, n)
    {
        int u, v;
        read(u, v);
        ins(u, v), ins(v, u);
    }
    f[rt = 0] = INF, find_rt(1, -1), solve(rt);
    rep(i, 1, n)
        printf("%d\n", sum[i]);
    return 0;
}