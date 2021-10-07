#include <cctype>
#include <cstdio>
#include <iostream>
#define re register
#define il inline
#define LL long long
#define gc getchar
#ifdef DEBUG
#define D() cerr << __LINE__ << endl;
#else
#define D()
#endif
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
}
const int MAXN = 150;
struct Mat
{
    int n, m;
    long long g[MAXN][MAXN];
    Mat(int _n = 0, int _m = 0) : n(_n), m(_m)
    {
        for (int i = 1; i <= _n; ++i)
            for (int j = 1; j <= _m; ++j)
                g[i][j] = 0;
    }
};
Mat operator*(const Mat &x, const Mat &y)
{
    Mat t(x.n, y.m);
    for (int k = 1; k <= x.m; ++k)
        for (int i = 1; i <= x.n; ++i)
        {
            if (x.g[i][k] == 0)
                continue;
            for (int j = 1; j <= y.m; ++j)
                t.g[i][j] += x.g[i][k] * y.g[k][j];
        }
    return t;
}
void init(Mat &x)
{
    for (int i = 1; i <= x.n; ++i)
        x.g[i][i] = 1;
}
Mat qpow(Mat a, int b)
{
    Mat ans(a.n, a.m);
    init(ans);
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ans = ans * a;
    return ans;
}
signed main()
{
    int n, m, k;
    while (read(n), read(m), read(k), n + m + k)
    {
        Mat ans(1, n + 1);
        ans.g[1][n + 1] = 1;
        Mat s(n + 1, n + 1);
        init(s);
        for (int i = 1; i <= k; ++i)
        {
            // D();
            char ch;
            int a, b;
            while (ch = gc(), !isalpha(ch))
                ;
            read(a);
            if (ch == 's')
            {
                read(b);
                for (int j = 1; j <= n + 1; ++j)
                    swap(s.g[j][a], s.g[j][b]);
            }
            else if (ch == 'g')
                ++s.g[n + 1][a];
            else
                for (int j = 1; j <= n + 1; ++j)
                    s.g[j][a] = 0;
        }
        ans = ans * qpow(s, m);
        for (int i = 1; i <= n; ++i)
            printf("%lld ", ans.g[1][i]);
        printf("\n");
    }
    return 0;
}