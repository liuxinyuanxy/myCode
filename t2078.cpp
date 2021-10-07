#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
using namespace std;
int a[100005][34];
int ans[100005];
il int rd()
{
	rt s = 0; rc ch;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s;
}
int n = rd(), kkk = rd();
int main()
{
	rt p = 0, temp;
	rt k;
	for (rt i = 1; i <= n; ++i)
		a[i][0] = rd();
	for (rt j = 1; j <= 32; ++j)
		for (rt i = 1; i <= n; ++i)
			a[i][j] = a[a[i][j - 1]][j - 1];
	for (rt i = 1; i <= n; ++i)
	{
		p = 0, temp = i, k = kkk;
		for (; k; k >>= 1, ++p)
			if (k & 1)
				temp = a[temp][p];
		ans[temp] = i;
	}
	for (rt i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}


