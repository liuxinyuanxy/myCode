#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long double ans = 0, t = 0;
	while (scanf("%Lf", &t) != EOF)
	{
		ans += t * 100000;
	}
	printf("%.5LF", ans / 100000);
}