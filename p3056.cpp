#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
int a[105][105];
int tot;
int g[10000];
int vis[10000];
int num[105][105];
struct node
{
    int x, y, num, val;
}temp;
vector <node> t[105];
queue <int> q;
int len[105];
int main()
{
    int ans;
    ios::sync_with_stdio(false);
    int x, y, c, x1, y1, x2, y2;
    int m, n;
    cin >> m >> n;
    memset(a, -1, sizeof(a));
    memset(num, -1, sizeof(num));
    memset(g, -1, sizeof(g));
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> c;
        a[x][y] = c;
    }
    if (a[m][m] == -1 && a[m-1][m] == -1 && a[m][m-1] == -1)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == -2)
                continue;
            if (a[i][j] == -1)
            {
                ans = 0;
                for (int k = 0; k < 4; ++k)
                {
                    if (a[x+mx[k]][y+my[k]] <= -1)
                        ++ans;
                }
                if (ans >= 3)
                    a[i][j] = -2;
            }
            else
            {
                num[i][j] = ++tot;
            }
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] <= -1)
            {
                for (int k = 0; k < 4; ++k)
                {
                    x1 = x + mx[k],
                    y1 = y + my[k];
                    if (a[x1][y1] >= 0)
                    {
                        temp.x = x1;
                        temp.y = y1;
                        temp.num = num[x1][y1];
                        temp.val = (int)(a[i][j] == a[x1][y1]);
                        ++len[tot];
                        t[tot].push_back(temp);
                    }
                    else
                    {
                        for (int k2 = 0; k2 < 4; ++k2)
                        {
                            x2 = x1 + mx[k2],
                            y2 = y1 + my[k2];
                            if (x2 == i && y2 == j)
                                continue;
                            if (a[x2][y2] >= 0)
                            {
                                temp.x = x2;
                                temp.y = y2;
                                temp.val = (int)(a[i][j] == a[x2][y2]) + 2;
                                ++len[tot];
                                t[tot].push_back(temp);
                            }
                        }
                    }
                }
            }
        }
    q.push(1);
    vis[1] = 0;
    int to;
    while (!q.empty())
    {
        int ttt = q.front();
        q.pop();
        for (int i = 0; i < len[ttt]; ++i)
        {
            temp = t[ttt][i];
            to = temp.num;
            if (g[to] == -1 || g[to] > g[i] + temp.val)
            {
                g[to] = g[i] + temp.val;
                if (!vis[to])
                {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
        vis[ttt] = 0;
    }
    if (g[num[m][m]] == -1)
    {
        if (g[num[m-1][m]] != -1)
        {
            cout << g[num[m-1][m]] + 2;
        }
        else
        {
            if (g[num[m][m-1]] != -1)
            {
                cout << g[num[m][m-1]] + 2;
            }
            else
                cout << -1;
        }
    }
    else
    {
        cout << g[num[m][m]];
    }
    return 0;
}
