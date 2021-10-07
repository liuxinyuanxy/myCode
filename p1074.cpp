#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int v[10][10] = {
	{6, 6, 6, 6, 6, 6, 6, 6, 6},
	{6, 7, 7, 7, 7, 7, 7, 7, 6},
	{6, 7, 8, 8, 8, 8, 8, 7, 6},
	{6, 7, 8, 9, 9, 9, 8, 7, 6},
	{6, 7, 8, 9, 10, 9, 8, 7, 6},
	{6, 7, 8, 9, 9, 9, 8, 7, 6},
	{6, 7, 8, 8, 8, 8, 8, 7, 6},
	{6, 7, 7, 7, 7, 7, 7, 7, 6},
	{6, 6, 6, 6, 6, 6, 6, 6, 6}
};
bool r[10][10], c[10][10], z[10][10][10];
struct nod
{
    int num, s;
}zero[12];
int a[10][10];
long long ans = -1;
void dfs(int i, int j, long long s, int js)
{
	if (js == 10)
	{
		ans = max(s, ans);
		return;
	}
	if (a[i][j])
	{
		s += a[i][j] * v[i-1][j-1];
		if (j + 1 == 10) dfs(zero[js + 1].num, 1, s, js + 1);else dfs(i, j+1, s, js);
		return;
	}
	for (register int k = 1; k <= 9; ++k)
	{
		if (!(r[i][k] || c[j][k] || z[(i-1)/3][(j-1)/3][k]))
		{
			r[i][k] = c[j][k] = z[(i-1)/3][(j-1)/3][k] = 1;
			s += k * v[i-1][j-1];
            if (j + 1 == 10) dfs(zero[js + 1].num, 1, s, js + 1);else dfs(i, j+1, s, js);
			s -= k * v[i-1][j-1];
			r[i][k] = c[j][k] = z[(i-1)/3][(j-1)/3][k] = 0;
		}
	}
}
bool cmp(nod a, nod b)
{
    return a.s < b.s;
}
int main()
{
	register int t;
	for (register int i = 1; i <= 9; ++i)
	{
	    zero[i].num = i;
		for (register int j = 1; j <= 9; ++j)
		{
			scanf("%d", &t);
			if (t == 0)
                ++zero[i].s;
			r[i][t] = c[j][t] = z[(i-1)/3][(j-1)/3][t] = 1;
			a[i][j] = t;
		}
	}
	sort(zero + 1, zero + 10, cmp);
	dfs(zero[1].num,1, 0, 1);
	printf("%lld", ans);
	return 0;
}
