#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#define il inline
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
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 3000000;
const double pi = acos(-1);
struct comp
{
    double x, y;
    comp(double _x = 0, double _y = 0) : x(_x), y(_y){};
} A[MAXN], B[MAXN], eps[MAXN], ieps[MAXN];
comp operator+(comp a, comp b)
{
    return comp(a.x + b.x, a.y + b.y);
}
comp operator-(comp a, comp b)
{
    return comp(a.x - b.x, a.y - b.y);
}
comp operator*(comp a, comp b)
{
    return comp(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y);
}
void init(int len)
{
    for (int i = 0, j; (j = 1 << i) <= len; ++i)
        eps[i].x = cos(2 * pi / j), eps[i].y = sin(2 * pi / j), ieps[i].x = cos(2 * pi / j), ieps[i].y = -sin(2 * pi / j);
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
int n;
LL a0, a1;
il LL get_c(LL x)
{
    return n * x * x + 2 * x * a0;
}
il LL get_minc()
{
    LL x0 = floor(-(double)a0 / n), x1 = ceil(-(double)a0 / n);
    return min(get_c(x0), get_c(x1));
}
int main()
{
    int m;
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
        a0 += a[i];
        a1 += a[i] * a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        read(b[i]);
        a0 -= b[i];
        a1 += b[i] * b[i];
    }
    for (int i = 1; i <= n; ++i)
        A[i].x = A[i + n].x = a[i];
    for (int i = 1; i <= n; ++i)
        B[n - i].x = b[i];
    int len = 1;
    while (len <= (n * 3))
        len <<= 1;
    init(len);
    FFT(len, A, eps);
    FFT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        A[i] = A[i] * B[i];
    FFT(len, A, ieps);
    LL ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, (LL)(A[i + n].x / len + 0.5));
    printf("%lld", get_minc() + a1 - 2 * ans);
}
