#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    int x, y;
}p[10];
int n;
double pi = acos(-1);
double ans = -1;
void check(double s)
{
    if (ans == -1 || s < ans)
        ans = s;
}
void dfs(int k, double s)
{
    if (k == n + 1)
    {
        check(s);
        return;
    }
    dfs()
}
int main()
{
    double s;
    int xl, yl, xr, yr;
    scanf("%d", &n);
    scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
    if (xl > xr)
        swap(xl, xr);
    if (yl > yr)
        swap(yl, yr);
    s = (xr - xl) * (yr - yl);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    dfs(1, s);
    return 0;
}
