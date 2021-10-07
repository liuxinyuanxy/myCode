#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a[8], S = 0;
	for (int i = 1; i <= 7; ++i)
	{
		cin >> a[i];
		S += a[i];
	}
	double ans = (S - 7 + 1);
	for (int i = 1; i <= 7; ++i)
		ans *= i * (double)a[i] / (S - i + 1);
	printf("%.3lf", ans);
	return 0;
}