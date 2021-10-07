#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int MOD = 100007;
const int MAXN = 60000;
P a[MAXN];
int tree1[11][2][MAXN];
#define lowbit(x) ((x) & -(x))
int n;
void add(int *tree, int pos, int x)
{
    while (pos <= n)
        tree[pos] = (x + tree[pos]) % MOD, pos += lowbit(pos);
}
int query(int *tree, int pos)
{
    int ans = 0;
    while (pos)
        ans = (tree[pos] + ans) % MOD, pos -= lowbit(pos);
    return ans;
}
vector<int> hs;
int dp[12][2];
int main()
{
    ios::sync_with_stdio(0), cin.tie(), cout.tie(0);
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        hs.push_back(a[i].second);
    }
    sort(hs.begin(), hs.end());
    for (int i = 1; i <= n; ++i)
        a[i].second = lower_bound(hs.begin(), hs.end(), a[i].second) - hs.begin() + 1;
    sort(a + 1, a + 1 + n);
    int ans = 0;
    add(tree1[0][0], a[1].second, 1), add(tree1[0][1], a[1].second, 1);
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            dp[j][0] = query(tree1[j][0], a[i].second - 1) + query(tree1[j - 1][1], a[i].second - 1);
            dp[j][0] %= MOD;
            dp[j][1] = query(tree1[j][1], n) - query(tree1[j][1], a[i].second) + query(tree1[j - 1][0], n) - query(tree1[j - 1][0], a[i].second);
            dp[j][1] %= MOD;
            add(tree1[j][0], a[i].second, dp[j][0]);
            add(tree1[j][1], a[i].second, dp[j][1]);
        }
        ans += dp[k][0] + dp[k][1];
        ans %= MOD;
        add(tree1[0][0], a[i].second, 1), add(tree1[0][1], a[i].second, 1);
    }
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;
    return 0;
}