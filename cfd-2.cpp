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
        cin >> n;
        if (n & 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (b + c != 0)
                cout << b + c << " " << -a << " " << -a << " ";
            else if (a + c != 0)
                cout << -b << " " << a + c << " " << -b << " ";
            else
                cout << -c << " " << -c << " " << a + b << " ";
            n -= 3;
        }
        for (int i = 1; i <= n; i += 2)
        {
            int a, b;
            cin >> a >> b;
            cout << -b << " " << a << " ";
        }
        cout << "\n";
    }
    return 0;
}