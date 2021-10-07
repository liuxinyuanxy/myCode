#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define MAXN 10000
using namespace std;
int n, m, a, b, w;
int t;
int qu[MAXN], l, r;
int head[MAXN], nxt[MAXN], val[MAXN], to[MAXN], g[MAXN];
int tot;
bool SPFA(int u)
{
    int t;
    qu[u] = true;
    for (int i = head[u]; i; i = nxt[i])
    {
        t = to[i];
        if (g[t] > g[u] + val[i])
        {
            g[t] = g[u] + val[i];
            if (qu[t])
            {
            	return true;
            }
            if (SPFA(t))
            	return true;
        }
    }
    qu[u] = false;
    return false;
}
void add(int a, int b, int w)
{
    ++tot;
    nxt[tot] = head[a];
    head[a] = tot;
    val[tot] = w;
    to[tot] = b;
}
int main()
{
    bool p = 0;
    srand(time(NULL));
    scanf("%d", &t);
    while (t--)
    {
        l = r = 0;
        p = 0;
        tot = 0;
        scanf("%d%d", &n, &m);
        memset(head, 0, (sizeof(int) * (n + 1)));
        memset(qu, 0, (sizeof(int) * (n + 1)));
        memset(g, 0x3f, (sizeof(int) * (n + 1)));
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &a, &b, &w);
            if (a == b)
            {
                if (w < 0)
                {
                    p = 1;
                }
                continue;
            }
            if (w < 0)
                add(a, b, w);
            else
                add(a, b, w),
                add(b, a, w);
        }
        g[1] = 0;
        if (p || SPFA(1))
            printf("YE5\n");
        else
            printf("N0\n");
    }
    return 0;
}
