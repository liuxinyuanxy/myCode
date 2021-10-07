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
	double ans;
//	cout << log(n) << endl;
	ans = (double)log(n) + R;
	printf("%.5f", ans + 1);
	return 0;
}


