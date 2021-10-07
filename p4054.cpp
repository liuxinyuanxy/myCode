#include <iostream>
#include <cstdio>
#define gc getchar
#define lowbit(x) ((x) & -(x))
using namespace std;
const int MAXN = 305;
int n, m;
int a[MAXN][MAXN];
int tree[105][MAXN][MAXN];
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
void modify(int z, int x, int y, int k)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= m; j += lowbit(j))
			tree[z][i][j] += k;
}
int query(int z, int x, int y)
{
	int ans = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			ans += tree[z][i][j];
	return ans;
}
int main()
{
	int q, opt, x, y, c, xx, yy;
	rd(n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			rd(a[i][j]);
			modify(a[i][j], i, j, 1);
		}
	rd(q);
	for (int i = 1; i <= q; ++i)
	{
		rd(opt, x, y);
		if (opt == 1)
		{
			rd(c);
			modify(a[x][y], x, y, -1);
			modify(a[x][y] = c, x, y, 1);
		}
		else
		{
			rd(xx, yy, c);
			swap(y, xx);
			printf("%d\n", query(c, xx, yy) - query(c, xx, y - 1) - query(c, x - 1, yy) + query(c, x - 1, y - 1));
		}
	}
	return 0;
}