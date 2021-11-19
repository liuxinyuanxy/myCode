#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define il inline
#define re register
using namespace std;
int n;
int x[10005], y[10005];
ll l[10005], r[10005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int X = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        X += x[i];
    }
    ll tot = 0, toty = 0x7fffffffffffffff;
    int cnt = 0;
    int avgx = X / n;
    for (int i = 1; i <= n; ++i)
        cnt += abs(avgx - x[i]);
    tot = cnt;
    cnt = 0;
    ++avgx;
    for (int i = 1; i <= n; ++i)
        cnt += abs(avgx - x[i]);
    if (cnt < tot)
        tot = cnt;
    sort(y + 1, y + 1 + n);
    for (int i = 2; i <= n; ++i)
    {
        l[i] = l[i - 1] + (y[i] - y[i - 1] - 1) * 1ll * (i - 1);
    }
    for (int i = n - 1; i >= 1; --i)
    {
        r[i] = r[i + 1] + (y[i + 1] - y[i] - 1) * 1ll * (n - i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << l[i] << " " << r[i] << endl;
        toty = min(toty, l[i] + r[i]);
    }
    cout << tot + toty;
    return 0;
}