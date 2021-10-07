#include <iostream>
#include <cstdio>
#define gc getchar
#define re register
#define il inline
using namespace std;
// int a[3000000];
int x;
int main()
{
	int n, a1 = 0, a2 = 0, l = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		if (x == 1)
		{
			if (l && l != x)
				a1 = 0;
			ans = max(ans, min(a1 + 1, a2));
			++a1;
		}
		else
		{
			if (l && l != x)
				a2 = 0;
			ans = max(ans, min(a1, a2 + 1));
			++a2;
		}
		l = x;
		// cout << a1 << " " << a2 << " " << l << " " << ans << endl;
	}
	printf("%d", ans * 2);
	return 0;
}