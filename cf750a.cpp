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
char ch[200000];
int check(char c)
{
    int cnt = 0;
    int l = 1, r = n;
    while (l < r)
    {
        if (ch[l] == ch[r])
            ++l, --r;
        else
        {
            if (ch[l] == c)
                ++l, ++cnt;
            else if (ch[r] == c)
                --r, ++cnt;
            else
                return n + 1;
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> (ch + 1);
        int x = n + 1;
        for (char c = 'a'; c <= 'z'; ++c)
            x = min(x, check(c));
        if (x == n + 1)
            cout << -1 << "\n";
        else
            cout << x << "\n";
    }
    return 0;
}