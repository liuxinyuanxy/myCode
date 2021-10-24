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
int dp[2][200000];
int a[200000];
ll sum[200000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + a[i], dp[1][i] = 1;
        int k;
        for (k = 2; k <= n; ++k)
        {
            int MAX = -1;
            int p = 0;
            for (int i = n; i >= 1; --i)
            {
                if (i + k - 1 <= n && sum[i + k - 1] - sum[i - 1] < MAX)
                    dp[(k & 1)][i] = p = 1;
                if (i + k + k - 2 <= n && dp[(k & 1) ^ 1][i + k])
                    MAX = max(MAX, sum[i + 2 * k - 2] - sum[i + k - 1]);
            }
            if (!p)
                break;
        }
        cout << k - 1 << endl;
    }
    return 0;
}