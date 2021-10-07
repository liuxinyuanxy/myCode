#include <iostream>
#include <cstdio>
#define ll long long
#define rt register int
#define re register
using namespace std;
int a[1000000];
int b[1000000];
ll ans;
int read()
{
	rt s = 0, p = 1;
	re char ch;
	ch = getchar();
	while ((ch < '0' && ch > '9') && ch != '-')
		ch == '-' ? p = -1 : ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s * p;
}
void merge(int l, int r)
{
	if  (l >= r)
		return;
	rt mid = (l + r) >> 1;
	merge(l, mid);
	merge(mid + 1, r); 
	rt i = l, s1 = l, e1 = mid, s2 = mid + 1, e2 = r;
	while (s1 <= e1 && s2 <= e2)
	{
		if (a[s1] <= a[s2])
		{
			b[i++] = a[s1++];
		}
		else
		{
			ans += (e1 - s1 + 1);
			b[i++] = a[s2++];
		}
	}
	while (s1 <= e1)
		b[i++] = a[s1++];
	while (s2 <= e2)
		b[i++] = a[s2++];
	for (rt j = l; j <= r; ++j)
		a[j] = b[j];
}
int main()
{
	int n;
	n = read();
	for (int i = 1; i <= n; ++i) 
		a[i] = read();
	merge(1, n);
	printf("%lld", ans);
	return 0;
}

