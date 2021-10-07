#include <iostream>
#include <cstdio>
#include <algorithm>
#define gc getchar
#define il inline
#define re register
using namespace std;
int a[1000000];
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
int main()
{
	int n, ans = 0;
	rd(n);
	for (int i = 1; i <= n; ++i)
	{
		rd(a[i]);
		a[i] = -a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
	{
		a[i] = -a[i];
		if (a[i] >= ans)
			++ans;
	}
	printf("%d", ans);
	return 0;
}