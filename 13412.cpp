#include <iostream>
#include <cstdio>
#define MAXN 10000
using namespace std;
int vis[MAXN][MAXN], a[MAXN][MAXN];
int front = 0x7fffffff, back = 0;
int ans[MAXN];
int du[MAXN];
int n, s;
bool check()
{
	int tot = 0;
	s = front;
	for (int i = back; i >= front; --i)
	{
		if (du[i] & 1)
		{
			++tot;
			s = i;
			if (tot > 2)
				return false;
		}
	}
	return true;
}
void print()
{
	for (int i = 1; i <= n + 1; ++i)
		printf("%c", ans[i]);
	printf("\n");
	exit(0);
}
void dfs(int x, int c)
{
	ans[c] = x;
	if (c == n + 1)
		print();
	for (int i = front; i <= back; ++i)
	{
		if (a[x][i] && !vis[x][i])
		{
			vis[x][i] = vis[i][x] = 1;
			dfs(i, c + 1);
			vis[x][i] = vis[i][x] = 0;
		}
	}
}
int main()
{
	char c1, c2;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		c1 = getchar();
		while (!isalpha(c1))
			c1 = getchar();
		c2 = getchar();
		while (!isalpha(c2))
			c2 = getchar();
		++du[c1];
		++du[c2];
		front = min((int)min(c1, c2), front);
		back = max((int)max(c1, c2), back);
		a[c1][c2] = a[c2][c1] = 1;
	}
	if (!check())
	{
		printf("No Solution\n");
		return 0;
	}
	dfs(s, 1);
	return 0;
}
