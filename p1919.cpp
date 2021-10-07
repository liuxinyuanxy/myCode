#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define gc getchar
using namespace std;
const int MAXN = 600000;
struct comp
{
	double x, y;
	comp(double _x = 0, double _y = 0) : x(_x), y(_y) {}
}A[MAXN], B[MAXN], eps[100], ieps[100];
int ans[MAXN];
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
il int rd(int k, int& n)
{
	char ch;
	while (ch = gc(), !isdigit(ch))
		;
	while (k == 1 && ch == '0')
		--n,
		ch = gc();
	return ch - '0';
}
const double pi = acos(-1);
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
il void FFT(int len, comp *x, comp *p)
{
	int n = 1 << len;
	for (int i = 0, j = 0; i < n; ++i)
	{
		if (i > j)
			swap(x[i], x[j]);
		for (int l = n >> 1; (j ^= l) < l; l >>= 1)
			;
	}
	for (int i = 1; i <= len; ++i)
	{
		int l = 1 << i, mid = l >> 1;
		for (int j = 0; j < n; j += l)
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
	scanf("%d", &n);
	--n;
	m = n;
	for (int i = 0; i <= n; ++i)
		A[i].x = (rd(i, n));
	for (int i = 0; i <= m; ++i)
		B[i].x = (rd(i, m));
	int len = 1, l = 0;
	while (len <= n + m)
		len <<= 1, ++l;
	init(len);
	FFT(l, A, eps);
	FFT(l, B, eps);
	for (int i = 0; i <= len; ++i)
		A[i] = A[i] * B[i];
	FFT(l, A, ieps);
	for (int i = 0; i <= n + m; ++i)
		ans[i] += int(A[n + m - i].x / len + 0.5),
			ans[i + 1] = ans[i] / 10,
				ans[i] %= 10;
	int kkk = n + m;
	if (ans[kkk + 1])
		++kkk;
	for (int i = kkk; i >= 0; --i)
		printf("%d", ans[i]);
}