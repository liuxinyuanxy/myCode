//ek
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 300000
using namespace std;
int s, t;
int tot = 2, n, ans;
int lst[MAX];
int frm[MAX], nxt[MAX], head[MAX], ret[MAX], to[MAX];
void add(int u, int v, int w)
{
    nxt[tot] = head[u];
    head[u] = tot;
    ret[tot] = w;
    to[tot] = v;
    frm[tot] = u;
    ++tot;
}
bool bfs()
{
    memset(lst, 0, sizeof(int) * (n + 1));
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = head[temp]; i; i = nxt[i])
        {
            if (ret[i] != 0 && !lst[to[i]] && to[i] != s)
            {
                lst[to[i]] = i;
                if (to[i] == t)
                {
                    return true;
                }
                q.push(to[i]);
            }
        }
    }
    return false;
}
int sk()
{
    ans = 0;
    while (bfs())
    {
        int minn = 0x7fffffff;
        for (int i = t; i != s; i = frm[lst[i]])
        {
            minn = min(minn, ret[lst[i]]);
        }
        ans += minn;
        for (int i = t; i != s; i = frm[lst[i]])
        {
            ret[lst[i]] -= minn;
            ret[lst[i]^1] += minn;
        }
    }
    return ans;
}
int main()
{
   // ios::sync_with_stdio(false);
    int m;
    int u, v, w;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << sk();
}
