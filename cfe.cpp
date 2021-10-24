#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define ll long long
#define il inline
#define re register
using namespace std;
int a[200000];
int vis[200000];
int two[12];
int p, Bit[12];
bool has;
set<int> S;
il void change(int x)
{
    for (int i = 10; i >= 0; --i)
    {
        if (x & two[i])
        {
            if (!Bit[i])
            {
                Bit[i] = x;
                ++p;
                return;
            }
            else
                x ^= Bit[i];
        }
    }
    has = 1;
}
il bool check(int x)
{
    for (int i = 10; i >= 0; --i)
    {
        if (x & two[i])
        {
            if (!Bit[i])
                return false;
            else
                x ^= Bit[i];
        }
    }
    return true;
}
int ans[1000000];
int anscnt;
void dfs(int r, int x)
{
    if (r < 0)
    {
        S.insert(x);
        return;
    }
    dfs(r - 1, x);
    if (Bit[r])
        dfs(r - 1, x ^ Bit[r]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    two[0] = 1;
    for (int i = 1; i <= 10; ++i)
        two[i] = 1 << i;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int tot = 0;
    while (tot < n)
    {
        int lst = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i] && a[i] > lst)
            {
                ++tot;
                vis[i] = 1;
                change(a[i]);
                lst = a[i];
            }
        }
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && check(a[i]))
                vis[i] = 1, ++tot;
        dfs(10, 0);
        for (int i = 0; i <= 10; ++i)
            Bit[i] = 0;
    }
    cout << S.size() << endl;
    for (auto x : S)
        cout << x << " ";
    return 0;
}