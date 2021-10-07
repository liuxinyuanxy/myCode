#include <iostream>
#include <cstdio>
using namespace std;
inline int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
int main()
{
	int n, ans = 0, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		if (a < 0)
			a = -a;
		ans = gcd(a, ans);
	}
	printf("%d", ans);
	return 0;
}
