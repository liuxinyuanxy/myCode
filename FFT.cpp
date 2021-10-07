#include <complex>
#include <cstdio>
#include <iostream>
#define gc getchar
#define il inline
using namespace std;
const int MAXN = 3000000;
double pi = acos(-1);
template <typename T>
void rd(T &s)
{
	s = 0;
	char ch;
	while (ch = gc(), ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
		;
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
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
	return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
il void init(int len)
{
	for (int i = 1, j = 0; i <= len; ++j, i <<= 1)
	{
		eps[j] = comp(cos(2 * pi / i), sin(2 * pi / i));
	}
	for (int i = 1, j = 0; i <= len; ++j, i <<= 1)
	{
		ieps[j] = comp(cos(2 * pi / i), -sin(2 * pi / i));
	}
}
// void FFT(int len, comp *x, comp *p)
// {
// 	if (len == 1)
// 		return;
// 	comp x1[(len >> 1)], x2[(len >> 1)];
// 	for (int i = 0; i < len; i += 2)
// 	{
// 		x1[i >> 1] = x[i],
// 		x2[i >> 1] = x[i + 1];
// 	}
// 	FFT(len >> 1, x1, p);
// 	FFT(len >> 1, x2, p);
// 	comp w0 = p[len], w = comp(1);
// 	for (int i = 0; i < (len >> 1); ++i, w = w * w0)
// 	{
// 		x[i] = x1[i] + w * x2[i],
// 		x[i + (len >> 1)] = x1[i] - w * x2[i];
// 	}
// }
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
int main()
{
	int n, m;
	rd(n, m);
	for (int i = 0; i <= n; ++i)
		rd(A[i].x);
	for (int i = 0; i <= m; ++i)
		rd(B[i].x);
	int len = 1;
	while (len <= n + m)
		len <<= 1;
	init(len);
	FFT(len, A, eps);
	FFT(len, B, eps);
	for (int i = 0; i <= len; ++i)
		A[i] = A[i] * B[i];
	FFT(len, A, ieps);
	for (int i = 0; i <= n + m; ++i)
	{
		printf("%d ", int(A[i].x / len + 0.5));
	}
	return 0;
}