#include <cstdio>
#include <iostream>
#define rt register int
using namespace std;
int map[100][100];
int a[100][100][100][100];
inline int read()
{
	rt s = 0;
	register char ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0',
		ch = getchar();
	return s;
}
int main()
{
	rt n, m;
	m = read(),
	n = read();
	for (rt i = 1; i <= m; ++i)
		for (rt j = 1; j <= n; ++j)
			map[i][j] = read();
	for (rt i = 1; i <= m; ++i)
		for (rt j = 1; j <= n; ++j)
			for (rt k = 1; k <= m; ++k)
				for (rt l = 1; l <= n; ++l)
					a[i][j][k][l] = max(max(a[i - 1][j][k - 1][l], a[i - 1][j][k][l - 1]), max(a[i][j - 1][k - 1][l], a[i][j - 1][k][l - 1])) + map[i][j] + ((i == k) && (j == l) ? 0 : map[k][l]);
	printf("%d", a[m][n][m][n]);
	return 0;
}
