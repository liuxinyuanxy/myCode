#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
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
const int MOD = 998244353;
const int MAXN = 1002;
int a[MAXN];
int sum[200][MAXN][MAXN];
signed main()
{
    int n, k;
    read(n), read(k);
    for (int i = 1; i <= n; ++i)
        1 read(a[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            for (int w = i; w <= j; ++w)
                sum[1][i][j] += a[w];
    for (int l = 1; l <= n; ++l)
    {
        for (int r = 1; r <= n; ++r)
            cout << sum[1][l][r] << "\t";
        cout << endl;
    }
    cout << endl;
    for (int i = 2; i <= k; ++i)
    {
        for (int l = 1; l <= n; ++l)
        {
            for (int r = l; r <= n; ++r)
            {
                for (int ii = l; ii <= r; ++ii)
                {
                    for (int jj = ii; jj <= r; ++jj)
                    {
                        sum[i][l][r] += sum[i - 1][ii][jj];
                    }
                }
            }
        }
        for (int l = 1; l <= n; ++l)
        {
            for (int r = 1; r <= n; ++r)
                cout << sum[i][l][r] << "\t";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}