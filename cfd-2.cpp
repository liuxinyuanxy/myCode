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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll k, x;
        cin >> k >> x;
        if ((1 + k) * 1ll * k / 2 <= x)
        {
            ll p = (sqrt(1 + 8 * x) - 1) / 2;
            p += 2;
            while (p * 1ll * (p + 1) / 2 > x)
                --p;
            cout << p << endl;
        }
        else
        {
            x -= (1 + k) * 1ll * k / 2;
            
        }
    }
    return 0;
}