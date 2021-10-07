#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int to, nxt;
}mem[10000];
int tot;
int head[10000];
bool vis[10000];
int p[10000];
int sz;
void add(int u, int v)
{
    mem[++tot].nxt = head[u];
    head[u] = tot;
    mem[tot].to = v;
}
void dfs(int k)
{
    int u;
    for (int j = head[k];j;j = mem[j].nxt)
    {
        if (vis[j])
            continue;
        u = mem[j].to;
        vis[j] = 1;
        dfs(u);
        p[++sz] = j;
    }
}
int main()
{
    int n, m;
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        add(u, v);
    }
    dfs(1);
    for (int i = 1; i <= sz; ++i)
        cout << p[i] << endl;
    return 0;
}
