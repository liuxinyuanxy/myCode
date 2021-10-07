#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime> 
#define sqr(x) ((x) * (x))
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
using namespace std;
struct node{
	int x, y, w;
}point[1005];
double ansx, ansy, ans;
double delta = 0.98;
il int rd()
{
	rt s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
int n;
il double dis(double x, double y)
{
	double tmp = 0;
	for (rt i = 1; i <= n; ++i)
		tmp += sqrt(sqr(point[i].x - x) + sqr(point[i].y - y)) * point[i].w;
	return tmp; 
}
il void SA()
{
	double T = 1926, tx, ty, Delta;
	double x = ansx, y = ansy;
	while (T > 1e-15)
	{
		tx = x + (rand() * 2 - RAND_MAX) * T;
		ty = y + (rand() * 2 - RAND_MAX) * T;
		Delta = ans - dis(tx, ty);
		if (Delta > 0)
			ansx = x = tx,
			ansy = y = ty,
			ans -= Delta;
		else
			if (exp(Delta/T) * RAND_MAX > rand())
				x = tx, y = ty;
		T *= delta;
	}
}
int main()
{
	srand(time(NULL));
	n = rd();
	for (rt i = 1; i <= n; ++i)
		point[i].x = rd(),
		point[i].y = rd(),
		point[i].w = rd(),
		ansx += point[i].x,
		ansy += point[i].y;
	ansx /= n;
	ansy /= n;
	ans = dis(ansx, ansy);
	while ((double)clock() / CLOCKS_PER_SEC < 0.8)
		SA();
	printf("%.3lf %.3lf", ansx, ansy);
	return 0;
}
