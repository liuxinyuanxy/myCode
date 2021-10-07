#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define gc getchar
#define LL long long
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
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 1200000;
const double e = 1e-3;
const double pi = 3.141592653589793;
struct comp
{
    double x, y;
    comp(double _x = 0, double _y = 0) : x(_x), y(_y){};
} A[MAXN], B[MAXN], eps[MAXN], ieps[MAXN], ans[MAXN];
comp operator+(const comp &x, const comp &y)
{
    return comp(x.x + y.x, x.y + y.y);
}
comp operator-(const comp &x, const comp &y)
{
    return comp(x.x - y.x, x.y - y.y);
}
comp operator*(const comp &x, const comp &y)
{
    return comp(x.x * y.x - x.y * y.y, x.x * y.y + x.y * y.x);
}
void init(int len)
{
    for (int i = 0, j; (j = 1 << i) <= len; ++i)
        eps[i] = comp(cos(2 * pi / j), sin(2 * pi / j)), ieps[i] = comp(cos(2 * pi / j), -sin(2 * pi / j));
}
void FFT(int len, comp *x, comp *p)
{
    for (int i = 0, j = 0; i < len; ++i)
    {
        if (i > j)
            swap(x[i], x[j]);
        for (int l = len >> 1; (j ^= l) < l; l >>= 1)
            ;
    }
    for (int i = 1, l; (l = 1 << i) <= len; ++i)
    {
        int mid = l >> 1;
        for (int j = 0; j < len; j += l)
        {
            comp w0(1);
            for (int k = j; k < j + mid; ++k)
            {
                comp t = w0 * x[k + mid];
                x[k + mid] = x[k] - t;
                x[k] = x[k] + t;
                w0 = w0 * p[i];
            }
        }
    }
}
int a[MAXN], b[MAXN];
vector<int> v;
void clear(comp *x, int len)
{
    for (int i = 0; i <= len; ++i)
        x[i] = comp();
}
int main()
{
    // freopen("/home/liuxinyuan/10.in", "r", stdin);
    int m, n;
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
    {
        char ch;
        while (iscntrl(ch = gc()))
            ;
        if (ch == '*')
            b[i] = 0;
        else
            b[i] = ch - 'a' + 1;
    }

    for (int i = 1; i <= m; ++i)
    {
        char ch;
        while (iscntrl(ch = gc()))
            ;
        if (ch == '*')
            a[i] = 0;
        else
            a[i] = ch - 'a' + 1;
    }
    int len = 1;
    while (len <= n + m)
        len <<= 1;
    init(len);

    for (int i = 1; i <= m; ++i)
        A[i].x = a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i].x = b[i] * b[i] * b[i];
    FFT(len, A, eps);
    FFT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        ans[i] = ans[i] + A[i] * B[i];
    clear(A, len), clear(B, len);

    for (int i = 1; i <= m; ++i)
        A[i].x = a[i] * a[i] * a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i].x = b[i];
    FFT(len, A, eps);
    FFT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        ans[i] = ans[i] + A[i] * B[i];
    clear(A, len), clear(B, len);

    for (int i = 1; i <= m; ++i)
        A[i].x = a[i] * a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i].x = b[i] * b[i];
    FFT(len, A, eps);
    FFT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        ans[i] = ans[i] - A[i] * B[i] * comp(2);

    FFT(len, ans, ieps);
    for (int i = 0; i <= m - n; ++i)
        if (fabsl(ans[i + n].x / len) <= e)
            v.push_back(i + 1);
    printf("%lu\n", v.size());
    for (auto x : v)
        printf("%d ", x);
    return 0;
}