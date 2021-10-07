#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
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
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 200000;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN];
int cnt;
void ins(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}
void insert(int u, int v, int w)
{
    ins(u, v, w);
    ins(v, u, w);
}
struct node
{
    int u, v, w;
};
bool cmp(node &x, node &y)
{
    return x.w < y.w;
}
vector<node> e;
vector<int> t;
int fa[MAXN];
int mx[1005][1005];
int vis[MAXN];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void dfs(int u)
{
    t.push_back(u);
    vis[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (!vis[v])
        {
            for (auto j : t)
                mx[v][j] = mx[j][v] = max(mx[u][j], val[i]);
            dfs(v);
        }
}
signed main()
{
    int n, m, k;
    read(n), read(m), read(k);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mx[i][j] = i == j ? 0 : -1;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        read(u), read(v), read(w);
        e.push_back(node{u, v, w});
    }
    sort(e.begin(), e.end(), cmp);
    for (auto ed : e)
    {
        int x = find(ed.u), y = find(ed.v);
        if (x == y)
            continue;
        fa[x] = y;
        insert(ed.u, ed.v, ed.w);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            t.clear(), dfs(i);
    for (int i = 1; i <= k; ++i)
    {
        int u, v;
        read(u), read(v);
        printf("%d\n", mx[u][v]);
    }
    return 0;
}