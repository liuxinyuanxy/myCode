#include <cstdio>
#include <iostream>
using namespace std;
int k[200005];
void solve0(int a, int b)
{
    cout << a + 1 << endl;
    int m = (a + b) >> 1;
    int f = m - a;
    for (int i = 0; i <= a; ++i)
        cout << f + i * 2 << " ";
    cout << endl;
}
void solve1(int a, int b)
{
    for (int i = 0; i <= a + b; ++i)
        k[i] = 0;
    int m = (a + b) >> 1;
    int f = m - a;
    for (int i = 0; i <= a; ++i)
        k[f + i * 2] = 1;
    ++m;
    f = m - a;
    for (int i = 0; i <= a; ++i)
        k[f + i * 2] = 1;
    int cnt = 0;
    for (int i = 0; i <= a + b; ++i)
        cnt += k[i];
    cout << cnt << endl;
    for (int i = 0; i <= a + b; ++i)
        if (k[i])
            cout << i << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if ((a + b) & 1)
            solve1(a, b);
        else
            solve0(a, b);
    }
}