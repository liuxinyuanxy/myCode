#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[20];
double ans;
inline double g(double x)
{
    double s = 0;
    for (int i = n; i >= 0; --i)
    {
        s = s * x + a[i];
    }
    return s;
}
void ttt(double l, double r)
{
    double m1, m2;
    while (r - l > 1e-7)
    {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        if (g(m1) > g(m2))
            r = m2;
        else
            l = m1;
    }
    ans = l;
}
int main()
{
    double l, r;
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    for (int i = n; i >= 0; --i)
    {
        cin >> a[i];
    }
    ttt(l, r);
    printf("%.5lf", ans);
    return 0;
}
