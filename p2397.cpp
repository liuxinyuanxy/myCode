#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, ans, p = 0, t;
	scanf("%d%d", &n, &ans);
	p = 1;
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &t);
		if (t != ans)
			--p;
		else
			++p;
		if (p == 0)
			ans = t,
			p = 1;
	}
	printf("%d", ans);
	return 0;
}