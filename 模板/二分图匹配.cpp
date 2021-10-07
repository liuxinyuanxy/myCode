//¶þ·ÖÍ¼Æ¥Åä 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1000000
using namespace std;
int head[MAX], nxt[MAX], ret[MAX], to[MAX];
int dis[MAX], r[MAX];
int s = 1, t = 200000;
int tot = 1;
inline void add(int u, int v, int w)
{
    ++tot;
    nxt[tot] = head[u];
    head[u] = tot;
    ret[tot] = w;
    to[tot] = v;
}
bool bfs()
{
    int now;
    queue<int> q;
    memset(dis, 0, sizeof(dis));
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = head[now]; i; i = nxt[i])
        {
            int next = to[i];
            if (!dis[next] && ret[i] && to[i] != s)
            {
                dis[next] = dis[now] + 1;
                if (next == t)
                    return 1;
                q.push(next);
            }
        }
    }
    return 0;
}
int dfs(int from, int maxflow)
{
    if (from == t)
        return maxflow;
    int ans = 0;
    for (int i = head[from]; i && ans < maxflow; i = nxt[i])
    {
        int next = to[i];
        if (dis[next] == dis[from] + 1 && ret[i] && to[i] != s)
        {
            int temp = dfs(next, min(maxflow - ans, ret[i]));

            ret[i] -= temp;
            ret[i ^ 1] += temp;
            ans += temp;
        }
    }
    return ans;
}
int dinic()
{
    int ans = 0;
    while (bfs())
        ans += dfs(s, 0x7fffffff);
    return ans;
}
int main()
{
    int n, m, u, v;
    int e;
    scanf("%d%d", &n, &m);
    scanf("%d", &e);
    for (int i = 1; i <= n; ++i)
        add(1, i + 1, 1),
        add(i + 1, 1, 0);
    for (int i = 1; i <= m; ++i)
        add(i + 1 + n, t, 1),
        add(t, i + 1 + n, 0);
    for (int i = 1; i <= e; ++i)
    {
        scanf("%d%d", &u , &v);
        if (v > m)
            continue;
        add(u + 1, v + n + 1, 1);
        add(v + n + 1, u + 1, 0);
    }
    printf("%d\n", dinic());
    return 0;
}
