#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define ll long long
#define int ll
#define il inline
#define re register
using namespace std;
typedef pair<ll, ll> P;
int tag[200005][35];
ll mod = 1000000007;
il P solve(re int l, re int r, re int p)
{
    if (l == r)
        return P(!tag[l][p], 1);
    re int mid = ((l + r) >> 1);
    P L = solve(l, mid, p), R = solve(mid + 1, r, p);
    re ll l1 = L.first, r1 = R.first;
    re ll l0 = ((L.second - l1) % mod + mod) % mod, r0 = ((R.second - r1) % mod + mod);
    return P((l1 + r1 + l0 * r1 % mod + l1 * r0 % mod) % mod, (L.second + R.second + L.second * R.second % mod) % mod);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n + 1; ++i)
        {
            for (int j = 0; j <= 30; ++j)
                tag[i][j] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            for (re int j = 0; j <= 30; j++)
            {
                if ((x & (1ll << j)) == 0ll)
                {
                    tag[l][j] += 1;
                    tag[r + 1][j] -= 1;
                }
            }
        }
        for (re int j = 0; j <= 30; j++)
        {
            for (re int i = 1; i <= n; ++i)
                tag[i][j] += tag[i - 1][j];
        }
        ll ans = 0;
        for (re int j = 0; j <= 30; j++)
        {
            ans = (ans + (1ll << j) % mod * (solve(1, n, j).first % mod) % mod) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}