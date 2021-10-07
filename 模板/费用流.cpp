//·ÑÓÃÁ÷ 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 300000
using namespace std;
int s, t;
int tot = 2, n, ans1, ans2;
int lst[MAX], dis[MAX];
int cst[MAX], frm[MAX], nxt[MAX], head[MAX], ret[MAX], to[MAX];
void add(int u, int v, int w, int f)
{
    nxt[tot] = head[u];
    head[u] = tot;
    ret[tot] = w;
    to[tot] = v;
    cst[tot] = f;
    frm[tot] = u;
    ++tot;
}
bool spfa()
{
    memset(lst, 0, sizeof(int) * (n + 1));
    memset(dis, 0x7f, sizeof(int) * (n + 1));
    bool vis[MAX] = {0}, p = 0;
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = head[temp]; i; i = nxt[i])
        {
            int tt = to[i];
            if (ret[i] != 0 && tt != s)
            {
                if (dis[tt] > dis[temp] + cst[i])
                {
                    dis[tt] = dis[temp] + cst[i];
                    lst[tt] = i;
                    if (tt == t)
                    {
                        p = 1;
                    }
                    if (!vis[tt])
                    {
                        vis[tt] = 1;
                        q.push(tt);
                    }
                }
            }
        }
        vis[temp] = 0;
    }
    return p;
}
void sk()
{
    ans1 = ans2 = 0;
    while (spfa())
    {
        int minn = 0x7fffffff;
        for (int i = t; i != s; i = frm[lst[i]])
        {
            minn = min(minn, ret[lst[i]]);
        }
        ans1 += minn;
        ans2 += minn * dis[t];
        for (int i = t; i != s; i = frm[lst[i]])
        {
            ret[lst[i]] -= minn;
            ret[lst[i]^1] += minn;
        }
    }
}
int main()
{
   // ios::sync_with_stdio(false);
    int m;
    int u, v, w, f;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w >> f;
        add(u, v, w, f);
        add(v, u, 0, -f);
    }
    sk();
    cout << ans1 << " " << ans2;
}
