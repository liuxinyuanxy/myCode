//dinic 
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 300005
using namespace std;
int head[MAX], nxt[MAX], rev[MAX], ret[MAX], to[MAX];
int dis[MAX];
int tot;
int s, t;
bool bfs()
{
    int temp;
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = head[temp]; i; i = nxt[i])
        {
            if (!dis[to[i]] && ret[i] > 0 && to[i] != s)
            {
                dis[to[i]] = dis[temp] + 1;
                if (to[i] == t)
                    return true;
                q.push(to[i]);
            }
        }
    }
    return false;
}
int dfs(int f, int maxflow)
{
    if (f == t)
        return maxflow;
    int ans = 0;
    for (int i = head[f]; i && ans < maxflow; i = nxt[i])
    {
        if (ret[i] == 0 || dis[f] + 1 != dis[to[i]])
            continue;
        int temp = dfs(to[i], min(maxflow - ans, ret[i]));
        ret[i] -= temp;
        ret[rev[i]] += temp;
        ans += temp;
    }
    if (!ans)
        dis[f] = -2;   //Õ¨µã
    return ans;
}
void add(int u, int v, int w)
{
    ++tot;
    nxt[tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    ret[tot] = w;
    rev[tot] = tot + 1;
    ++tot;
    nxt[tot] = head[v];
    head[v] = tot;
    to[tot] = u;
    ret[tot] = 0;
    rev[tot] = tot - 1;
    return;
}
int main()
{
    int n, m;
    int u, v, w;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    int ans = 0;
    while (bfs())
    {
        ans += dfs(s, 0x7fffffff);
    }
    printf("%d\n", ans);
    return 0;
}
