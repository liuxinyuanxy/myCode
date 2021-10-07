#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 200005
#define re register
#define INF 0x7fffffff
using namespace std;
int n, m, s, dis[100005];
int tot;
int head[MAX], nxt[MAX], to[MAX], len[MAX];
struct node
{
    int num, d;
    node(int a, int b)
    {
        num = a, d = b;
    }
    bool operator < (const node & x) const
    {
        if (d == x.d)
            return num < x.num;
        else
            return d > x.d;
    }
};
inline void add(int u, int v, int w)
{
    ++tot;
    nxt[tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    len[tot] = w;
}
int main()
{
    ios::sync_with_stdio(false);
    int u, v, w;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (re int i = 1; i <= n; ++i)
        dis[i] = INF;
    dis[s] = 0;
    priority_queue<node> pq;
    pq.push(node(s, 0));
    while (!pq.empty())
    {
        node temp = pq.top();
        pq.pop();
        re int now = temp.num;
        if (temp.d != dis[now])
            continue;
        for (re int i = head[now]; i; i = nxt[i])
        {
            if (dis[now] + len[i] < dis[to[i]])
            {
                dis[to[i]] = dis[now] + len[i];
                pq.push(node(to[i], dis[to[i]]));
            }
        }
    }
    for (re int i = 1; i <= n; ++i)
        cout << dis[i] << " ";
    return 0;
}
