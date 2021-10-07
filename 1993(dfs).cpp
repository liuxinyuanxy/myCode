#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3fffffff
#define MAX 30000
using namespace std;
int tot;
int n, m;
int l, r;
bool qu[MAX];
int head[MAX], nxt[MAX], to[MAX], val[MAX];
int g[MAX];
inline void add(int u, int v, int w)
{
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
void SPFA(int u)
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
        	    printf("No");
				exit(0);
			}
			SPFA(t);
		}
	}
	qu[u] = false;
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
    	g[i] = INF;
    for (int i = 1; i <= n; ++i)
    {
		g[i] = 0;
        SPFA(i);
    }
    printf("Yes");
    return 0;
}

