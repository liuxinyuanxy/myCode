#include <cstdio>
#include <iostream>
using namespace std;
int a[100000];
int n;
bool check()
{
    for (int i = 1; i < n; ++i)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
void change(int i)
{
    if (a[i] > a[i + 1])
        swap(a[i], a[i + 1]);
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
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int cnt = 0;
        while (!check())
        {
            ++cnt;
            int i = ((cnt & 1) ? 1 : 2);
            for (; i < n; i += 2)
                change(i);
        }
        cout << cnt << endl;
    }
}