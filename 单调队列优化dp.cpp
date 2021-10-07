#include <iostream>
#include <cstdio>
#include <queue>
#define Q 100000
#define INF 0x7fffffff
using namespace std;
const int mx[] = {0, -1, 1, 0, 0}, my[] = {0, 0, 0, -1, 1};
int f[205][205][205];
int que[Q], pos[Q], head, tail;
bool a[205][205];
int ans = 0;
int n, m;
void push(int val, int now)
{
    if (val == -INF)
        return;
    while (head <= tail && val - now >= que[tail])
        --tail;
    que[++tail] = val - now;
    pos[tail] = now;
}
void dp(int k, int x, int y, int d, int l)
{
    if (l < 1)
        return;
    head = 1;
    tail = 0;
    int now = 1;
    while (x > 0 && x <= n && y > 0 && y <= m)
    {
        if (!a[x][y])
            head = 1,
            tail = 0;
        else
            push(f[k-1][x][y], now);
        while (head <= tail && now - pos[head] > l)
            ++head;
        if (head <= tail)
            f[k][x][y] = que[head] + now;
        else
            f[k][x][y] = -INF;
        ans = max(ans, f[k][x][y]);
        x += mx[d];
        y += my[d];
        ++now;
    }

}
int main()
{
    int x, y, k, s, t, d;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            f[0][i][j] = -INF;
    f[0][x][y] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> ch;
            if (ch == '.')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    for (int i = 1; i <= k; ++i)
    {
        cin >> s >> t >> d;
        if (d == 1)
            for (int j = 1; j <= m; ++j)
                dp(i, n, j, d, t - s + 1);

        if (d == 2)
            for (int j = 1; j <= m; ++j)
                dp(i, 1, j, d, t - s + 1);

        if (d == 3)
            for (int j = 1; j <= n; ++j)
                dp(i, j, m, d, t - s + 1);

        if (d == 4)
            for (int j = 1; j <= n; ++j)
                dp(i, j, 1, d, t - s + 1);

    }
    cout << ans;
    return 0;
}
