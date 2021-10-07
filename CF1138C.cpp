#include <iostream>
#include <cstdio>
#include <algorithm>
#define gc getchar
#define re register
#define il inline
using namespace std;
int a[1005][1005];
int num1[1005][1005];
int num2[1005][1005];
int mx[1005], my[1005];
struct node
{
	int x, y, num;
}b[1005][1005];
bool cmp(node x, node y)
{
	return x.num < y.num;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			b[i][j].num = a[i][j];
			b[i][j].x = i;
			b[i][j].y = j;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(&b[i][1], &b[i][1 + m], cmp);
		int p = 0;
		for (int j = 1; j <= m; ++j)
		{
			int x = b[i][j].x, y = b[i][j].y;
			if (j != 1)
				num1[x][y] = b[i][j].num == b[i][j - 1].num ? num1[b[i][j - 1].x][b[i][j - 1].y] : ++p;
			else
				num1[x][y] = ++p;
			if (j == m)
				mx[i] = num1[x][y];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			b[j][i].num = a[i][j];
			b[j][i].x = i;
			b[j][i].y = j;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		int p = 0;
		sort(&b[i][1], &b[i][1 + n], cmp);
		for (int j = 1; j <= n; ++j)
		{
			int x = b[i][j].x, y = b[i][j].y;
			if (j != 1)
				num2[x][y] = b[i][j].num == b[i][j - 1].num ? num2[b[i][j - 1].x][b[i][j - 1].y] : ++p;
			else
				num2[x][y] = ++p;
			if (j == n)
				my[i] = num2[x][y];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			printf("%d ", max(num1[i][j], num2[i][j]) + max(mx[i] - num1[i][j], my[j] - num2[i][j]));
		}
		printf("\n");
	}
	return 0;
}