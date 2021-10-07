#include <iostream>
#include <cstdio>
using namespace std;
char ch[4002][4002];
int ans1[4002][4002], ans2[4002][4002];
int len, t;
int md, id;
int main()
{
	int l, p, i, j, x, y;
	scanf("%d%d", &l, &p);
	len = l * 2 + 1;
	for (i = 2; i <= len; i += 2)
	{
		t = getchar();
		while (!isalpha(t))
			t = getchar();
		ch[i][0] = '&';
		for (j = 1; j < len; j += 2)
		{
			ch[i][j] = '#';
			ch[i][j+1] = t;
			t = getchar();
		}
		ch[i][len] = '#';
		md = id = 0;
		for (j = 1; j <= len; ++j)
		{
			ch[i-1][j] = '#';
			if (md > j)
				ans1[i][j] = min(ans1[i][id * 2 - j], md - j);
			else
				ans1[i][j] = 1;
			while (ch[i][j - ans1[i][j]] == ch[i][j + ans1[i][j]]) ++ans1[i][j];
			if (ans1[i][j] + j > md)
				md = ans1[i][j] + j,
				id = j;
		}
	}
	for (i = 1; i <= len; ++i)
		ch[0][i] = '&',
		ch[len][i] = '#';
	
	for (j = 2; j <= len; j += 2)
	{
		md = id = 0;
		for (i = 1; i <= len; ++i)
		{
			if (md > i)
				ans2[i][j] = min(ans2[id * 2 - i][j], md - i);
			else
				ans2[i][j] = 1;
			while (ch[i - ans2[i][j]][j] == ch[i + ans2[i][j]][j]) ++ans2[i][j];	
			if (ans2[i][j] + i > md)
				md = ans2[i][j] + i,
				id = i;
		}
	}
	for (i = 1; i <= p; ++i)	
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", max(ans1[x * 2][y * 2], ans2[x * 2][y * 2]) - 1);
	}
	return 0;
}
