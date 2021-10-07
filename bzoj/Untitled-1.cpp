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
namespace splay
{
const int N = 4000005;
int tot;
int son[N][2], fa[N], val[N], sum[N], key[N];
class Splay
{
#define ls son[o][0]
#define rs son[o][1]
private:
    int rt;
    il void update(int o)
    {
        sum[o] = sum[ls] + sum[rs] + val[o];
    }
    il void rotate(int x, int &k)
    {
        int y = fa[x], z = fa[y];
        int l = son[y][1] == x, r = l ^ 1;
        if (y == k)
            k = x;
        else
            son[z][son[z][1] == y] = x;
        fa[x] = z;
        fa[son[x][r]] = y;
        son[y][l] = son[x][r];
        son[x][r] = y;
        fa[y] = x;
        update(y), update(x);
    }
    il void splay(int x, int &k)
    {
        int y, z;
        while (x != k)
        {
            y = fa[x], z = fa[y];
            if (y != k)
                rotate(son[z][1] == y ^ son[y][1] == x ? x : y, k);
            rotate(x, k);
        }
    }
    void findl(int x)
    {
        int o = rt;
        int ans = rt;
        while (o)
            key[o] <= x ? (ans = o, o = rs) : (o = ls);
        splay(ans, rt);
    }
    void insert(int x, int v, int &o, int f)
    {
        if (!o)
        {
            o = ++tot;
            key[o] = x, val[o] = sum[o] = v;
            fa[o] = f;
            ls = rs = 0;
            splay(o, rt);
            return;
        }
        insert(x, v, x < key[o] ? ls : rs, o);
    }
    il bool find(int x)
    {
        findl(x);
        return key[rt] == x;
    }

public:
    il int query(int x)
    {
        findl(x);
        return sum[son[rt][0]] + val[rt];
    }
    il void modify(int p, int x)
    {
        if (find(p))
            val[rt] += x, update(rt);
        else
            insert(p, x, rt, 0);
    }
};
} // namespace splay

const int INF = 0x7fffffff;
const int N = 200005;
splay::Splay s[N], fs[N];
int cnt;
int rt;
int head[N], nxt[N], to[N], val[N];
int fa[N], dep[N], dis[20][N];
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
    while (l != r)
    {
        int cur = qu[l++];
        s[u].modify(dis[d][cur], val[cur]);
        if (d > 1)
            fs[u].modify(dis[d - 1][cur], val[cur]);
        for (int i = head[cur], v; v = to[i], i; i = nxt[i])
            if (!vis[v] && !dis[d][v])
                dis[d][v] = dis[d][cur] + 1, qu[r++] = v;
    }
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
    for (int i = 1; i <= n; ++i)
        s[i].modify(-INF, 0), fs[i].modify(-INF, 0);
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