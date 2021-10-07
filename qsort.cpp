#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define rt register int
using namespace std;
int a[500000];
int n;
void qsort(rt l, rt r)
{
	rt ll = l, rr = r, mid;
	if (l >= r)
		return;
	mid = rand() % (r - l + 1) + l;
	rt m = a[mid];
	a[mid] = a[l];
	while (l < r)
	{
		while (r > l && a[r] >= m)
			--r;
		a[l] = a[r];
		while (l < r && a[l] < m)
			++l;
		a[r] = a[l];
	}
	a[l] = m;
	qsort(ll, l - 1);
	qsort(r + 1, rr);
}
inline int read()
{
	rt s = 0, p = 1;
	register char ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch == '-' ? p = -1 : ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s * p;
}
int main()
{
	srand(time(NULL));
	srand(rand());
	srand(rand());
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
	qsort(1, n);
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

