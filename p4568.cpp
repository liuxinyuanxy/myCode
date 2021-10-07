#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define pii pair<int, int>
#define _ 3000500
using namespace std;
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool done[_];
int n, k;
int dis[_];
int head[_], nxt[_], to[_], val[_];
int tot;
il void add(rt u, rt v, rt w)
{
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
il int rd()
{
    rt s = 0, p = 0; rc ch;
    while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
    return p ? -s : s;
}
void dij(rt s, rt t)
{
    pii now;
    rt id, v;
    pq.push(mp(0, s));
    fill(dis + 1, dis + (k + 1) * n + 2, 0x7fffffff);
    dis[s] = 0;
    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        id = now.second;
        if ((id - 1) % n + 1 == t)
        {
            printf("%d", now.first);
            return;
        }
        if (done[id])
            continue;
        for (rt i = head[id]; i; i = nxt[i])
        {
            v = to[i];
            if (dis[v] > dis[id] + val[i])
            {
                dis[v] = dis[id] + val[i];
                pq.push(mp(dis[v], v));
            }
        }
    }
    return;
} 
int main()
{
    rt m, s, t, u, v, w;
    n = rd(), m = rd(), k = rd();
    s = rd(), t = rd();
    ++s, ++t;
    for (rt i = 1; i <= m; ++i)
    {
        u = rd(), v = rd(), w = rd();
        ++u, ++v;
        for (rt j = 0; j < k; ++j)
        {
            add(u + j * n, v + j * n, w),
            add(v + j * n, u + j * n, w),
            add(u + j * n, v + (j + 1) * n, 0),
            add(v + j * n, u + (j + 1) * n, 0);
        }
        add(u + n * k, v + n * k, w),
        add(v + n * k, u + n * k, w);
    }
    dij(s, t);
    return 0;
}
