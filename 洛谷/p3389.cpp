#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
    read(s), read(args...);
}
#define eps 1e-6
const int N = 150;
double g[N][N];
int n;
void print()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
            printf("%.2lf ", g[i][j]);
        printf("\n");
    }
    printf("\n");
}
bool gause()
{
    for (int i = 1; i <= n; ++i)
    {
        int idx = i;
        for (int j = i; j <= n; ++j)
            if (fabs(g[j][i]) > eps)
            {
                idx = j;
                break;
            }
        if (fabs(g[idx][i]) <= eps)
            return false;
        swap(g[i], g[idx]);
        for (int j = 1; j <= n; ++j)
            if (j != i)
            {
                double t = g[j][i] / g[i][i];
                for (int k = i; k <= n + 1; ++k)
                    g[j][k] -= g[i][k] * t;
            }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n + 1; ++j)
            cin >> g[i][j];
    if (gause())
    {
        for (int i = 1; i <= n; ++i)
            printf("%.2lf\n", g[i][n + 1] / g[i][i]);
    }
    else
        printf("No Solution");
    return 0;
}