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
    for (int i = 1, l; (l = (1 << i)) <= len; ++i)
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
int a[MAXN], s[MAXN];
int main()
{
    int n, x;
    LL sum = 0, lst = 0;
    read(n), read(x);
    for (int i = 0; i < n; ++i)
    {
        read(a[i]);
        a[i] = (a[i] < x);
        if (!a[i])
            ++lst;
        else
            sum += lst * (lst + 1) / 2, lst = 0;
        s[i] = s[i - 1] + a[i];
        ++A[s[i]].x;
        ++B[n - s[i - 1]].x;
    }
    sum += lst * (lst + 1) / 2;
    int len = 1;
    while (len <= (n << 1))
        len <<= 1;
    init(len);
    FFT(len, A, eps);
    FFT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        A[i] = A[i] * B[i];
    FFT(len, A, ieps);
    printf("%lld", sum);
    for (int i = 1; i <= n; ++i)
        printf(" %lld", (LL)(A[i + n].x / len + 0.5));
}
