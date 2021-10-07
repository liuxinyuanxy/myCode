#include <iostream>
#include <cstdio>
#define MAX 1005
using namespace std;
int head[MAX], nxt[MAX], to[MAX], len[MAX];
int fa[MAX];
int tot = 0;
int ans;
inline void add(int u, int v)
{
    ++tot;
    nxt[tot] = head[u];
    to[tot] = v;
    head[u] = tot;
}
void dfs(int i, int f, int gf, bool* vis)
{
    bool p = 0;
    if (!f && !gf)
        p = 1,
        ++ans;
    for (int x = head[i]; x; x = nxt[x])
    {
        if (!vis[to[x]])
        {
            vis[to[x]] = 1;
            dfs(to[x], p, f, vis);
        }
    }
}
int main()
{
    int n, ml = 0, id;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &fa[i]);
        len[i] = len[fa[i]] + 1;
        if (len[i] > ml)
        	ml = len[i],
        	id = i;
        add(i, fa[i]);
        add(fa[i], i);
    }
    bool vis[MAX] = {0};
    if (!fa[fa[id]])
    {
    	printf("1\n");
    	return 0;
	}
    dfs(fa[fa[id]], 0, 0, vis);
    printf("%d", ans);
    return 0;
}

