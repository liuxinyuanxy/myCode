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
int Gcd(int x, int y) { return !y ? x : Gcd(y, x % y); };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int ans = 0, gcd = 1;
    int n;
    cin >> n;
    cin >> gcd;
    ans = gcd;
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        gcd = Gcd(gcd, x);
        ans += gcd;
    }
    cout << ans << endl;
    return 0;
}