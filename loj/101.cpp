#include <cstdio>
#include <iostream>
#define gc getchar
#define il inline
#define re register
#define LL long long
using namespace std;
const int MAXN = 100005;
template <typename T>
void rd(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
        ;
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
        ;
    s = s * (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
    rd(s);
    rd(args...);
}
int n;
int dis[MAXN];
int cur[MAXN], head[MAXN], nxt[MAXN], to[MAXN], flow[MAXN], cap[MAXN];
int cnt = 1;
void insert(int u, int v, int c)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    flow[cnt] = 0;
    cap[cnt] = c;
}
int qu[MAXN], l, r;
bool bfs(int s, int t)
{
    l = r = 0;
    for (int i = 1; i <= n; ++i)
        cur[i] = head[i], dis[i] = 0;
    dis[s] = 1;
    qu[r++] = s;
    while (l != r)
    {
        int u = qu[l++];
        if (l > MAXN - 10)
            l = 0;
        for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (!dis[v] && flow[i] < cap[i])
            {
                dis[v] = dis[u] + 1;
                if (v == t)
                    return true;
                qu[r++] = v;
                if (r > MAXN - 10)
                    r = 0;
            }
    }
    return false;
}
int dfs(int u, int maxflow, int t)
{
    if (u == t)
        return maxflow;
    int ans = 0, temp;
    for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
    {
        if (dis[v] == dis[u] + 1 && flow[i] < cap[i])
        {
            temp = dfs(v, min(maxflow - ans, cap[i] - flow[i]), t);
            ans += temp;
            flow[i] += temp;
            flow[i ^ 1] -= temp;
            if (ans == maxflow)
                break;
        }
    }
    if (!ans)
        dis[u] = -2;
    return ans;
}
int main()
{
    int m;
    rd(n, m);
    int s, t;
    rd(s, t);
    int u, v, c;
    for (int i = 1; i <= m; ++i)
    {
        rd(u, v, c);
        insert(u, v, c);
        insert(v, u, 0);
    }
    LL ans = 0;
    while (bfs(s, t))
        ans += dfs(s, 0x7fffffff, t);
    printf("%lld", ans);
    return 0;
}
