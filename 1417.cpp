#include <algorithm>
#include <cstdio>
#include <iostream>
#define rt register int
using namespace std;
int ans[100005][100];
int aaa;
struct node
{
	int a, b, c;
} a[100];
bool cmp(const node &a, const node &b)
{
	return a.a - a.c * a.b > b.a - b.c * b.b;
}
inline int read()
{
	rt s = 0, p = 1;
	register char ch;
	ch = getchar();
	while (ch != '-' && ch < '0' && ch > '9')
		ch = getchar();
	if (ch == '-')
		p = -1;
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s * p;
}
int main()
{
	rt n, T;
	T = read(), n = read();
	for (rt i = 1; i <= n; ++i)
		a[i].a = read();
	for (rt i = 1; i <= n; ++i)
		a[i].b = read();
	for (rt i = 1; i <= n; ++i)
		a[i].c = read();
	sort(a + 1, a + n + 1, cmp);
	for (rt i = 1; i <= n; ++i)
	{
		for (rt j = a[i].c; j <= T; ++j)
		{
			ans[j][i] = max(ans[j][i - 1], ans[j - a[i].c][i - 1] + a[i].a - j * a[i].b);
			aaa = max(aaa, ans[j][i]);
		}
	}
	printf("%d", aaa);
	return 0;
}
