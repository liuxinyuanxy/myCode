#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 300005
using namespace std;
int cur[MAX], head[MAX], nxt[MAX], rev[MAX], ret[MAX], to[MAX];
int dis[MAX];
int n, m;
int r[MAX];
int endd = 500;
int tot;
bool bfs()
{
    int temp;
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = head[temp]; i; i = nxt[i])
        {
            if (!dis[to[i]] && ret[i] > 0 && to[i] != 0)
            {
                dis[to[i]] = dis[temp] + 1;
                if (to[i] == endd)
                    return true;
                q.push(to[i]);
            }
        }
    }
    return false;
}
int dfs(int f, int maxflow)
{
    if (f == endd)
        return maxflow;
    int ans = 0;
    for (int i = head[f]; i && ans < maxflow; i = nxt[i])
    {
        if (to[i] == 0 || ret[i] == 0 || dis[f] + 1 != dis[to[i]])
            continue;
        int temp = dfs(to[i], min(maxflow - ans, ret[i]));
        if (f <= m && f >= 1 && temp != 0)
            r[f] = to[i];
        ret[i] -= temp;
        ret[rev[i]] += temp;
        ans += temp;
    }
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
    ios::sync_with_stdio(false);
    int u, v;
    cin >> m >> n;
    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        add(u, v, 1);
        cin >> u >> v;
    }
    for (int i = 1; i <= m; ++i)
        add(0, i, 1);
    for (int i = m + 1; i <= n; ++i)
        add(i, endd, 1);
    int ans = 0;
    while (bfs())
    {
        ans += dfs(0, 0x7fffffff);
    }
    if (ans)
    {
        cout << ans << endl;
        for (int i = 1; i <= m; ++i)
        {
            if (r[i])
                cout << i << " " << r[i] << endl;
        }
    }
    else
        cout << "No Solution!";
    return 0;
}
