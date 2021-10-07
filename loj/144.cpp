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
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 2000000;
int n;
class Bit
{
public:
#define lowbit(x) ((x) & -(x))
    LL tree[MAXN];
    void add(int p, int x)
    {
        for (; p <= n; p += lowbit(p))
            tree[p] += x;
    }
    LL que(int p)
    {
        LL ans = 0;
        for (; p; p -= lowbit(p))
            ans += tree[p];
        return ans;
    }
} B;
int rt;
int sze[MAXN];
int pos[MAXN], head[MAXN], nxt[MAXN], to[MAXN], val[MAXN], fa[MAXN];
int cnt, tot;
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
void insert(int u, int v)
{
    ins(u, v), ins(v, u);
}
void dfs(int u)
{
    pos[u] = ++tot;
    B.add(tot, val[u]);
    sze[u] = 1;
    for (int i = head[u], v; v = to[i], i; i = nxt[i])
        if (fa[u] != v)
        {
            fa[v] = u;
            dfs(v);
            sze[u] += sze[v];
        }
}
int main()
{
    int m;
    read(n), read(m), read(rt);
    for (int i = 1; i <= n; ++i)
        read(val[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        read(u), read(v);
        insert(u, v);
    }
    dfs(rt);
    int op, a, x;
    for (int i = 1; i <= m; ++i)
    {
        read(op), read(a);
        if (op == 1)
            read(x), B.add(pos[a], x);
        else
            printf("%lld\n", B.que(pos[a] + sze[a] - 1) - B.que(pos[a] - 1));
    }
    return 0;
}