#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define ll long long
#define il inline
#define re register
using namespace std;
struct node
{
    int a, b;
    int get_A()
    {
        return a;
    }
    int get_B()
    {
        return b;
    }
};
node qwqwqwqwq;
int lst[600];
int temp[200000];
int a[600];
int vis[600];
int cnt;
set<int> S[600];
set<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        temp[i] = x;
        if (!vis[x])
            vis[x] = 1, lst[x] = i;
        else
        {
            temp[lst[x]] = -1;
            lst[x] = i;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (temp[i] >= 0)
            a[++cnt] = temp[i];
    n = cnt;
    for (int i = 1; i <= n; ++i)
    {
        S[i].insert(a[i]);
        int MAX = -1;
        for (int j = i - 1; j >= 1; --j)
        {
            if (a[i] < a[j])
                continue;
            if (a[j] < MAX)
                continue;
            MAX = max(MAX, a[j]);
            for (auto x : S[j])
                S[i].insert(x), S[i].insert(x ^ a[i]);
        }
    }
    ans.clear();
    ans.insert(0);
    int MAX = -1;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] < MAX)
            continue;
        MAX = max(MAX, a[i]);
        for (auto x : S[i])
            ans.insert(x);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    return 0;
}