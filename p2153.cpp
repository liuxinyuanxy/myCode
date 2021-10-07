#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 500000
using namespace std;
int n, m;
int ans1, ans2;
int tot = 1;
bool vis[MAX];
int g[MAX], dis[MAX];
int from[MAX], head[MAX], nxt[MAX], to[MAX], len[MAX], cost[MAX];
void add(int u, int v, int w, int f)
{
    ++tot;
    nxt[tot] = head[u];
    head[u] = tot;
    from[tot] = u;
    to[tot] = v;
    len[tot] = w;
    cost[tot] = f;
}
bool spfa()
{
    int now, next;
    bool p = 0;
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(g, 0x7f, sizeof(g));
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    g[1] = 0;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = head[now]; i; i = nxt[i])
        {
            next = to[i];
            if (g[next] > g[now] + cost[i] && len[i] != 0)
            {
                dis[next] = i;
                if (next == n)
                    p = 1;
                g[next] = g[now] + cost[i];
                if (!vis[next])
                {
                    q.push(next);
                    vis[next] = 1;
                }
            }
        }
        vis[now] = 0;
    }
    return p;
}
void ek()
{
    while (spfa())
    {
        for (int i = n; i != 1; i = from[dis[i]])
        {
            --len[dis[i]];
            ++len[dis[i]^1];
        }
        cout << endl;
        ++ans1;
        ans2 += g[n];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int u, v, w;
    cin >> n >> m;
    for (int i = 2; i < n; ++i)
    {
        add(i, i + n, 1, 0);
        add(i + n, i, 0, 0);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        if (u == 1)
            u = 1 - n;
        add(u + n, v, 1, w);
        add(v, u + n, 0, -w);
    }
    ek();
    cout << ans1 << " " << ans2;
    return 0;
}
