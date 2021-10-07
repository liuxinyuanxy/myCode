#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 30000
using namespace std;
int tot;
int n, m;
int qu[MAX], l, r;
int head[MAX], nxt[MAX], to[MAX], val[MAX];
int cnt[MAX], g[MAX];
inline void add(int u, int v, int w)
{
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
bool SPFA(int u)
{
    memset(g, 0x7f, (sizeof(int) * (n + 1)));
    int o, t;
    bool vis[MAX] = {0};
    l = r = 0;
    g[u] = 0;
    vis[u] = 1;
    cnt[u] = 1;
    qu[r++] = u;
    while (l != r)
    {
        o = qu[l++];
        vis[o] = 0;
        if (l > n)
            l = 0;
        for (int x = head[o]; x; x = nxt[x])
        {
            t = to[x];
            if (g[t] > g[o] + val[x])
            {
                g[t] = g[o] + val[x];
                if (!vis[t])
                {
                    vis[t] = 1;
                    ++cnt[t];
                    if (cnt[t] > n)
                    {
                        return true;
                    }
                    if (g[t] < g[qu[l]])
                    {
                        qu[--l] = t;
                        if (l < 0)
                            l = n;
                    }
                    else
                    {		
                        qu[r++] = t;
                        if (r > n)
                            r = 0;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    int k, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &k, &a, &b);
        if (k == 3)
        {
            add(a, b, 0);
            add(b, a, 0);
        }
        else
        {
            scanf("%d", &c);
            if (k == 2)
                add(a, b, c);
            else
                add(b, a, -c);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!cnt[i] && SPFA(i))
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}

