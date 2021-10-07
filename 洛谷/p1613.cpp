#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 60;
const int MAXM = 3000000;
int gra[32][MAXN][MAXN];
int dis[MAXN], vis[MAXN];
int cnt;
int head[MAXN], nxt[MAXN * MAXN], to[MAXN * MAXN];
void ins(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        gra[0][u][v] = 1;
    }
    for (int w = 1; w < 32; ++w)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (!gra[w - 1][i][j])
                    continue;
                for (int k = 1; k <= n; ++k)
                    if (gra[w - 1][j][k])
                        gra[w][i][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 0; k < 32; ++k)
                if (gra[k][i][j])
                {
                    ins(i, j);
                    break;
                }
    dis[1] = 1;
    dis[0] = 0x3fffffff;
    for (int c = 1; c <= n; ++c)
    {
        int id = 0;
        for (int i = 1; i <= n; ++i)
            if (dis[i] && !vis[i] && dis[i] < dis[id])
                id = i;
        vis[id] = 1;
        for (int i = head[id], v = to[i]; i; i = nxt[i], v = to[i])
            if (!dis[v] || dis[v] > dis[id] + 1)
                dis[v] = dis[id] + 1;
    }
    cout << dis[n] - 1 << endl;
    return 0;
}