#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;
P tt[100005];
bool cmp(P &a, P &b)
{
    if (a.first < b.first)
        return true;
    if (a.first > b.first)
        return false;
    return a.second > b.second;
}
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
        {
            int k;
            cin >> k;
            tt[i].second = k;
            tt[i].first = 0;
            for (int j = 1; j <= k; ++j)
            {
                int a;
                cin >> a;
                tt[i].first = max(tt[i].first, a - j + 1);
            }
        }
        sort(tt + 1, tt + 1 + n, cmp);
        int ned = tt[1].first + 1;
        int now = ned + tt[1].second;
        for (int i = 2; i <= n; ++i)
        {
            if (now > tt[i].first)
                now += tt[i].second;
            else
            {
                int temp = tt[i].first - now + 1;
                ned += temp;
                now += temp + tt[i].second;
            }
        }
        cout << ned << endl;
    }
}