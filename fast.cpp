#pragma GCC optimize ("Ofast")
#include <iostream>
#include <cstdio>
#include <queue>
#define MAX 200005
#define re register
#define rt register int
using namespace std;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > pq;
int g[MAX];
int b[MAX];
int head[MAX], nxt[MAX], to[MAX], val[MAX];
int s, tot;
int n;
bool done[MAX];
inline int read()
{
    re char ch;
    rt s = 0;
    ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + ch - '0',
        ch = getchar(); 
    return s; 
}
inline void add(rt u, rt v, rt w)
{
    nxt[++tot] = head[u];
    to[tot] = v;
    val[tot] = w;
    head[u] = tot;
}
inline void dij()
{
    P now;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        if (done[now.second])
            continue;
        done[now.second] = 1;
        for (rt i = head[now.second]; i; i = nxt[i])
        {
            if (g[to[i]] > g[now.second] + val[i])
            {
                g[to[i]] = g[now.second] + val[i];
                pq.push(P(g[to[i]], to[i]));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); 
    rt m, u, v, w;
    cin >> n >> m >> s;
    for (rt i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (rt i = 1; i <= n; ++i)
        g[i] = 0x7fffffff;
    g[s] = 0;
    dij();
    for (rt i = 1; i <= n; ++i)
    {
        cout << g[i] << " ";
    }
    return 0;
}

