#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define re register
#define gc getchar
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
const int N = 105;
struct Mat
{
    int n, m;
    int g[N][N];
    Mat(int _n = 0, int _m = 0) : n(_n), m(_m)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                g[i][j] = 0x3fffffff;
    }
};
Mat operator*(const Mat &x, const Mat &y)
{
    Mat ans(x.n, y.m);
    for (int k = 1; k <= x.m; ++k)
        for (int i = 1; i <= x.n; ++i)
            for (int j = 1; j <= y.m; ++j)
                ans.g[i][j] = min(ans.g[i][j], x.g[i][k] + y.g[k][j]);
    return ans;
}
Mat qpow(Mat a, int b)
{
    Mat ans = a;
    --b;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ans = ans * a;
    return ans;
}
int hs[10000];
int cnt;
int main()
{
    int n, t, s, e;
    read(n), read(t), read(s), read(e);
    Mat zero(t, t);
    int a, b, c;
    for (int i = 1; i <= t; ++i)
    {
        read(a), read(b), read(c);
        b = hs[b] ? hs[b] : hs[b] = ++cnt;
        c = hs[c] ? hs[c] : hs[c] = ++cnt;
        zero.g[b][c] = zero.g[c][b] = min(zero.g[b][c], a);
    }
    zero = qpow(zero, n);
    cout << zero.g[hs[s]][hs[e]];
    return 0;
}