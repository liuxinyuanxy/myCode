#include <iostream>
#include <cstdio>
#include <cmath>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define R 0.57721566490153286060651209
using namespace std;
int main()
{
	int n;
	scanf ("%d", &n);
	double ans = 0;
	if (n >= 2)
	{
		if (n > 10000)
		{
			ans = (double)log(n) + R + 1;
		}
		else
		{
			ans = 2;
			for (int i = 2; i < n; ++i)
				ans += 1.0 / i;
		}
	}
	printf("%.5lf", ans);
	return 0;
}


