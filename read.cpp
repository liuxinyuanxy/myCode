#include <iostream>
#include <cstdio>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <typename T> void rd(T& s)
{
	bool p = 0;
	char ch;
	s = 0;
	while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
int main()
{
	int a, b;
	rd(a, b);
	printf("%d", a + b);
	return 0;
}