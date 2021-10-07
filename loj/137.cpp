#include <algorithm>
#include <cctype>
#include <cstdio>
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
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        s *= p ? -1 : 1;
}
const int MAXN = 200000;
const int MOD = 1000000007;
int n, m;
int nd;
int ls[MAXN], rs[MAXN], fa[MAXN], val[MAXN], be[MAXN];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int ST[31][MAXN], cnt;
int pos[MAXN];
void dfs(int u)
{
    if (ls[u])
        dfs(ls[u]);
    ST[0][++cnt] = val[u];
    if (u <= n)
        pos[u] = cnt;
    if (rs[u])
        dfs(rs[u]);
}
int lg[MAXN];
void init()
{
    lg[1] = 0;
    for (int i = 2; i <= cnt; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= 31; ++i)
        for (int j = 1; j <= cnt - (1 << i) + 1; ++j)
            ST[i][j] = max(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
}
int A, B, C, P;
il int rnd()
{
    return A = (A * B + C) % P;
}
struct edge
{
    int u, v, w;
} E[MAXN];
bool cmp(const edge &x, const edge &y)
{
    return x.w < y.w;
}
int main()
{
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
        fa[i] = be[i] = i;
    for (int i = 1; i <= m; ++i)
        read(E[i].u), read(E[i].v), read(E[i].w);
    sort(E + 1, E + 1 + m, cmp);
    nd = n;
    for (int i = 1; i <= m; ++i)
    {
        int u = find(E[i].u), v = find(E[i].v);
        if (u != v)
        {
            ++nd;
            ls[nd] = be[u];
            rs[nd] = be[v];
            fa[u] = v;
            be[v] = nd;
            val[nd] = E[i].w;
        }
    }
    dfs(nd);
    init();
    int q, u, v;
    read(q);
    read(A), read(B), read(C), read(P);
    LL ans = 0;
    for (int i = 1; i <= q; ++i)
    {
        u = pos[rnd() % n + 1], v = pos[rnd() % n + 1];
        if (u > v)
            swap(u, v);
        int len = lg[v - u + 1];
        ans += max(ST[len][u], ST[len][v - (1 << len) + 1]);
    }
    ans %= MOD;
    printf("%lld", ans);
    return 0;
}