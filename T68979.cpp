#include <iostream>
#include <cstdio>
#define gc getchar
#define re register
#define MAXN 300000
template <typename T> void rd(T& s)
{
	s = 0;
	re bool p = 0;
	re char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
int a[MAXN];
inline void modify(re int k, re int w)
{
	a[k] = w;
}
int query(re int l, re int r, re int x, re int y)
{
	re int ans = 0, p = 0, np = 0, la = -1;
	for (re int i = l; i <= r; ++i)
	{
		if (a[i] < x || a[i] > y)
		{
			np = 0;
			la = -1;
			continue;
		}
		if (a[i] == la)
			++np;
		else
			np = 1,
			la = a[i];
		if (np == p)
			++ans;
		if (np > p)
			ans = 1,
			p = np;
	}
	return ans;
}
int main()
{
	re int n, m, opt, l, r, x, y;
	rd(n, m);
	for (re int i = 1; i <= n; ++i)
		rd(a[i]);
	for (re int i = 1; i <= m; ++i)
	{
		rd(opt, l, r);
		if (opt == 1)
		{
			modify(l, r);
		}
		else
		{
			rd(x, y);
			printf("%d\n", query(l, r, x, y));
		}
	}
}