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
struct BIT
{
#define lowbit(x) ((x) & -(x))
    int n;
    vector<int> v;
    void modify(int p, int x)
    {
        ++p;
        for (int i = p; i <= n; i += lowbit(i))
            v[i] += x;
    }
    int query(int p)
    {
        ++p;
        if (p <= 0)
            return 0;
        if (p >= n)
            p = n;
        int ans = 0;
        for (int i = p; i; i -= lowbit(i))
            ans += v[i];
        return ans;
    }
};
const int INF = 0x7fffffff;
const int N = 200005;
BIT s[N], fs[N];
int cnt;
int rt;
int head[N], nxt[N], to[N], val[N];
int fa[N], dep[N], dis[20][N], maxdis[N];
int sze[N], f[N], S;
int vis[N];
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void find_rt(int u, int fa)
{
    f[u] = 0;
    sze[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
    {
        if (!vis[v] && v != fa)
        {
            find_rt(v, u), sze[u] += sze[v];
            if (sze[v] > f[u])
                f[u] = sze[v];
        }
    }
    f[u] = max(f[u], S - sze[u]);
    if (f[u] < f[rt])
        rt = u;
}
int qu[N], l, r;
void bfs(int d, int u)
{
    l = r = 0;
    qu[r++] = u;
    dis[d][u] = 0;
    fs[u].n = (maxdis[fa[u]] + 1);
    fs[u].v.resize(maxdis[fa[u]] + 2);
    while (l != r)
    {
        int cur = qu[l++];
        maxdis[u] = max(maxdis[u], dis[d][cur]);
        // s[u].modify(dis[d][cur], val[cur]);
        if (d > 1)
            fs[u].modify(dis[d - 1][cur], val[cur]);
        for (int i = head[cur], v; v = to[i], i; i = nxt[i])
            if (!vis[v] && !dis[d][v])
                dis[d][v] = dis[d][cur] + 1, qu[r++] = v;
    }
    s[u].n = (maxdis[u] + 1);
    s[u].v.resize(maxdis[u] + 2);
    for (int i = 0; i < l; ++i)
        s[u].modify(dis[d][qu[i]], val[qu[i]]);
}
void calc(int d, int u)
{
    vis[u] = 1;
    dep[u] = d;
    bfs(d, u);
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v])
            S = sze[v], f[rt = 0] = INF, find_rt(v, u), fa[rt] = u, calc(d + 1, rt);
}
int lst;
int query(int x, int k)
{
    int cur = x;
    int ans = 0;
    while (cur)
    {
        ans += s[cur].query(k - dis[dep[cur]][x]);
        if (dep[cur] > 1)
            ans -= fs[cur].query(k - dis[dep[cur] - 1][x]);
        cur = fa[cur];
    }
    return lst = ans;
}
void modify(int x, int y)
{
    int cur = x;
    while (cur)
    {
        s[cur].modify(dis[dep[cur]][x], y);
        if (dep[cur] > 1)
            fs[cur].modify(dis[dep[cur] - 1][x], y);
        cur = fa[cur];
    }
}
int main()
{
    int n, m;
    read(n, m);
    for (int i = 1; i <= n; ++i)
        read(val[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u, v);
        ins(u, v), ins(v, u);
    }
    S = n;
    f[rt = 0] = INF, find_rt(1, 0);
    calc(1, rt);
    for (int i = 1; i <= m; ++i)
    {
        int op, x, y;
        read(op, x, y);
        x ^= lst, y ^= lst;
        if (op == 0)
            printf("%d\n", query(x, y));
        else
            modify(x, y - val[x]), val[x] = y;
    }
    return 0;
}