#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n, m, l, r, d, o;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &l);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &o, &l, &r);
		if (o == 2)
			scanf("%d", &l);
		if (o == 3)
			printf("%d", rand());
	}
	return 0;
}
