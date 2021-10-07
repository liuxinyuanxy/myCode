#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define gc getchar
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
struct Bit
{
    LL bit[61];
    Bit()
    {
        for (int i = 0; i <= 60; ++i)
            bit[i] = 0;
    }
    void insert(LL x)
    {
        for (int i = 60; ~i; --i)
            if (x & (1ll << i))
            {
                if (bit[i])
                    x ^= bit[i];
                else
                {
                    bit[i] = x;
                    return;
                }
            }
    }
    LL query()
    {
        LL ans = 0;
        for (int i = 60; ~i; --i)
            if ((ans ^ bit[i]) > ans)
                ans ^= bit[i];
        return ans;
    }
    void modify(const Bit &y)
    {
        for (int i = 60; ~i; --i)
            if (y.bit[i])
                insert(y.bit[i]);
    }
};
const int MAXN = 40005;
int cnt;
int head[MAXN], nxt[MAXN], to[MAXN], fa[16][MAXN], dis[MAXN];
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void dfs(int u)
{
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[0][u])
            fa[0][v] = u, dis[v] = dis[u] + 1, dfs(v);
}
Bit st[16][20005];
Bit ans;
int n;
void init()
{
    for (int i = 1; i <= 15; ++i)
        for (int j = 1; j <= n; ++j)
            fa[i][j] = fa[i - 1][fa[i - 1][j]],
            st[i][j].modify(st[i - 1][j]), st[i][j].modify(st[i - 1][fa[i - 1][j]]);
}
LL query(int u, int v)
{
    for (int i = 0; i <= 60; ++i)
        ans.bit[i] = 0;
    if (dis[u] < dis[v])
        swap(u, v);
    int k = dis[u] - dis[v];
    for (int t = 0; k; k >>= 1, ++t)
        if (k & 1)
            ans.modify(st[t][u]), u = fa[t][u];
    if (u == v)
    {
        ans.modify(st[0][u]);
        return ans.query();
    }
    for (int i = 15; ~i; --i)
        if (fa[i][u] != fa[i][v])
            ans.modify(st[i][u]), ans.modify(st[i][v]), u = fa[i][u], v = fa[i][v];
    ans.modify(st[1][u]), ans.modify(st[0][v]);
    return ans.query();
}
int main()
{
    int q;
    read(n), read(q);
    for (int i = 1; i <= n; ++i)
    {
        LL x;
        read(x);
        st[0][i].insert(x);
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u), read(v);
        ins(u, v), ins(v, u);
    }
    dis[1] = 1;
    dfs(1);
    init();
    for (int i = 1; i <= q; ++i)
    {
        int u, v;
        read(u), read(v);
        // ++tot;
        // cout << endl;
        // cout << u << " " << v << endl;
        // cout << endl;
        // query(u, v);
        printf("%lld\n", query(u, v));
    }
    return 0;
}