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
const int INF = 0x3fffffff;
struct heap
{
    priority_queue<int> pq, del;
    il void insert(int x)
    {
        pq.push(x);
    }
    il void remove(int x)
    {
        del.push(x);
    }
    il int get_fst()
    {
        while (!del.empty() && pq.top() == del.top())
            pq.pop(), del.pop();
        return pq.empty() ? -INF : pq.top();
    }
    il int get_sed()
    {
        int x1 = get_fst();
        if (x1 == -INF)
            return x1;
        pq.pop();
        int x2 = get_fst();
        insert(x1);
        return x2;
    }
};
const int N = 100005;
const int M = 200005;
int cnt;
int head[N], nxt[M], to[M], cst[M], val[N];
int sze[N], fa[N], vis[N], f[N], lt[N];
int dis[18][N], dep[N];
int rt, S;
int lstans[N];
heap s, son[N], ans[N];
void ins(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    cst[cnt] = w;
}
void find_rt(int u, int fa)
{
    f[u] = 0;
    sze[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa && !vis[v])
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
int qu[M], l, r;
void travel(int d, int u)
{
    l = r = 0;
    dis[d][u] = 0;
    qu[r++] = u;
    while (l != r)
    {
        int cur = qu[l++];
        if (d > 1)
            son[u].insert(dis[d - 1][cur]);
        for (int i = head[cur], v; v = to[i], i; i = nxt[i])
            if (!vis[v] && dis[d][v] == INF)
            {
                dis[d][v] = dis[d][cur] + cst[i];
                qu[r++] = v;
            }
    }
}
void calc(int d, int u)
{
    dep[u] = d;
    vis[u] = 1;
    ans[u].insert(0);
    travel(d, u);
    ans[fa[u]].insert(son[u].get_fst());
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u] && !vis[v])
            S = sze[v], f[rt = 0] = INF, find_rt(v, u), fa[rt] = u, calc(d + 1, rt);
    s.insert(lstans[u] = ans[u].get_fst() + ans[u].get_sed());
}
int main()
{
    int n;
    read(n);
    s.insert(0);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        read(u, v, w);
        ins(u, v, w), ins(v, u, w);
    }
    for (int i = 0; i <= 17; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = INF;
    S = n, f[rt = 0] = INF, find_rt(1, -1), calc(1, rt);
    int tot = n;
    int q;
    read(q);
    for (int i = 1; i <= q; ++i)
    {
        char ch;
        while (!isalpha(ch = gc()))
            ;
        if (ch == 'A')
        {
            if (tot == 0)
                printf("They have disappeared.\n");
            else if (tot == 1)
                printf("0\n");
            else
                printf("%d\n", s.get_fst());
        }
        else
        {
            int x;
            read(x);
            if (lt[x])
                ans[x].insert(0), ++tot;
            else
                ans[x].remove(0), --tot;
            int cur = x;
            while (cur)
            {
                if (dep[cur] > 1)
                {
                    int x1 = son[cur].get_fst();
                    if (lt[x])
                        son[cur].insert(dis[dep[cur] - 1][x]);
                    else
                        son[cur].remove(dis[dep[cur] - 1][x]);
                    int x2 = son[cur].get_fst();
                    if (x1 != x2)
                        ans[fa[cur]].remove(x1), ans[fa[cur]].insert(x2);
                }
                int l = ans[cur].get_fst() + ans[cur].get_sed();
                if (l != lstans[cur])
                    s.remove(lstans[cur]), s.insert(lstans[cur] = l);
                cur = fa[cur];
            }
            lt[x] ^= 1;
        }
    }
    return 0;
}
// ans : 点分治中心到所有子树的距离
// son : 点分治中心所在的连通块到点分治树父亲的距离
