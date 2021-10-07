#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
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
using namespace std;
int n, m;
int ans = 0x7fffffff;
bool done[13];
int dis[13][13];
struct node{
    int id, dep, w, rd;
}now;
int p = 0;
bool operator < (const node& x, const node& y)
{
    return x.dep * x.w + x.rd > y.dep * y.w + y.rd;
}
priority_queue<node> pq;
void prim(rt u)
{
    for (rt i = 1; i <= n; ++i)
        done[i] = 0;
    rt id, aans = 0;
    pq.push({u, 0, 0, u == p ? rand() : 0});
    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        id = now.id;
        if (done[id])
            continue;
        done[id] = 1;
        aans += now.w * now.dep;
        for (rt i = 1; i <= n; ++i)
            if (!done[i] && dis[i][id])
                pq.push({i, now.dep + 1, dis[i][id], i == p ? rand() : 0});
    }
    ans = min(ans, aans);
}
il int rd()
{
    rc ch; rt s = 0;
    while (ch = gc(), ch < '0' || ch > '9');
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
    return s;
}
il void RAND()
{
    srand(time(NULL));
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
    srand(rand());
}
il void READ()
{
    rt u, v, w;
    n = rd(), m = rd();
    for (rt i = 1; i <= m; ++i)
    {
        u = rd(), v = rd(), w = rd();
        dis[u][v] = dis[v][u] = (!dis[u][v]) ? w : min(dis[u][v], w);
    }
}
il void run()
{
    for (rt i = 1; i <= n; ++i)
        prim(i);
}
il void SOLVE()
{
    while ((double)clock() / CLOCKS_PER_SEC < 0.9977)
    {
        run();
        p = rand() % n + 1;
    }
}
il void PRINT()
{
    printf("%d", ans);
}
int main()
{
    RAND();
    READ();
    SOLVE();
    PRINT();
    return 0;
}


