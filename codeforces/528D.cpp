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
const int MAXN = 800000;
const double pi = 3.141592653589793;
struct comp
{
    double x, y;
    comp(double _x = 0, double _y = 0) : x(_x), y(_y){};
} A[MAXN], B[MAXN], eps[MAXN], ieps[MAXN];
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
void clear(comp *x, int len)
{
    for (int i = 0; i <= len; ++i)
        x[i] = comp();
}
int s[MAXN], t[MAXN], S[MAXN];
il int turn(char ch)
{
    if (ch == 'A')
        return 1;
    else if (ch == 'G')
        return 2;
    else if (ch == 'C')
        return 3;
    else
        return 4;
}
int len;
int n, m, d;
int ans[MAXN];
void solve(int id)
{
    clear(A, len), clear(B, len);
    for (int i = 1; i <= n; ++i)
        if (s[i] == id)
            A[n - i].x = 1;
    S[0] = 0;
    for (int i = 1; i <= m; ++i)
        S[i] = S[i - 1] + int(t[i] == id);
    for (int i = 1; i <= m; ++i)
        if (S[min(i + d, m)] - S[max(i - d - 1, 0)] > 0)
            B[i].x = 1;
    FFT(len, A, eps);
    FFT(len, B, eps);
    for (int i = 0; i <= len; ++i)
        A[i] = A[i] * B[i];
    FFT(len, A, ieps);
    for (int i = 0; i <= m - n; ++i)
        ans[i] += int(A[i + n].x / len + 0.5);
}
int main()
{
    char ch;
    read(m), read(n), read(d);
    for (int i = 1; i <= m; ++i)
    {
        while (!isalpha(ch = gc()))
            ;
        t[i] = turn(ch);
    }
    for (int i = 1; i <= n; ++i)
    {
        while (!isalpha(ch = gc()))
            ;
        s[i] = turn(ch);
    }
    len = 1;
    while (len <= n + m)
        len <<= 1;
    init(len);
    for (int i = 1; i <= 4; ++i)
        solve(i);
    int cnt = 0;
    for (int i = 0; i <= m - n; ++i)
        if (ans[i] == n)
            ++cnt;
    printf("%d\n", cnt);
    return 0;
}