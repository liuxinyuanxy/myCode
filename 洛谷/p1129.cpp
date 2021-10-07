#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define LL long long
#define gc getchar
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#else
#define D()
#endif
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
const int MAXN = 500, MAXM = 1000000;
int cnt = 1;
int head[MAXN], nxt[MAXM], to[MAXM], ret[MAXM];
int dis[MAXN], qu[MAXM + 2], l, r;
int S, T, N;
void ins(int u, int v, int w)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    ret[cnt] = w;
}
void insert(int u, int v, int w)
{
    ins(u, v, w);
    ins(v, u, 0);
}
bool bfs()
{
    D();
    l = r = 0;
    fill(dis + 1, dis + 1 + N, 0);
    qu[r++] = S;
    dis[S] = 1;
    while (l != r)
    {
        int u = qu[l++];
        for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (ret[i] && !dis[v])
            {
                dis[v] = dis[u] + 1;
                qu[r++] = v;
                if (v == T)
                    return 1;
            }
    }
    return 0;
}
int dfs(int u, int maxflow)
{
    D();
    if (u == T)
        return maxflow;
    int ans = 0;
    for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (ret[i] && dis[v] == dis[u] + 1)
        {
            int temp = dfs(v, min(maxflow - ans, ret[i]));
            ans += temp;
            ret[i] -= temp;
            ret[i ^ 1] += temp;
            if (ans == maxflow)
                return ans;
        }
    if (!ans)
        dis[u] = -2;
    return ans;
}
int main()
{
    int TT;
    read(TT);
    while (TT--)
    {
        cnt = 1;
        int n;
        read(n);
        S = (n << 1) + 1;
        T = S + 1;
        N = T;
        for (int i = 1; i <= n; ++i)
            insert(S, i, 1), insert(i + n, T, 1);
        D();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                int x;
                read(x);
                if (x)
                    insert(i, j + n, 1);
            }
        int ans = 0;
        while (bfs())
            ans += dfs(S, 0x3fffffff);
        printf(ans == n ? "Yes\n" : "No\n");
        for (int i = 1; i <= N; ++i)
            head[i] = 0;
    }
    return 0;
}