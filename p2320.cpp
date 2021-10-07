#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tot;
int a[100000000];
void s(int m)
{
	if (m == 1)
	{
		a[++tot] = 1;
		return;
	}
	s(m / 2);
	a[++tot] = m - m / 2;
}
int main()
{
	int m;
	scanf ("%d", &m);
	s(m);
	printf("%d\n", tot);
	for (int i = 1; i <= tot; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
