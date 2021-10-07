#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define gc getchar
#define re register
#define il inline
using namespace std;
const int N = 5005;
int c[N], a[N];
int n;
vector<int> o1, o2, o3, o4;
void print(int i, int j)
{
	int s2 = o2.size(), s3 = o3.size();
	int s = i + s2 - j;
	for (int k = 0; k < i; ++k)
		printf("%d ", o1[k]);
	for (int k = 0; k < s2 - j; ++k)
		printf("%d ", o2[k]);
	int p = max(i, j) - min(i, j);
	int p1 = ((s3 - p) >> 1);
	for (int k = 0; k < p1; ++k)
		printf("%d ", o3[k]);
	s += p1;
	if (i < j)
	{
		for (int k = 0; k < ((j - i)); ++k)
			printf("%d ", o3[p1 + k]);
		s += ((j - i));
	}
	p = n / 2 - s;
	if (p > 0)
	{
		for (int k = 0; k < p; ++k)
			printf("%d ", o4[k]);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		char ch;
		while (ch = gc(), !isdigit(ch))
			;
		c[i] = ch - '0';
	}
	for (int i = 1; i <= n; ++i)
	{
		char ch;
		while (ch = gc(), !isdigit(ch))
			;
		a[i] = ch - '0';
	}
	for (int i = 1; i <= n; ++i)
	{
		if (c[i] && a[i])
			o3.push_back(i);
		if (c[i] && !a[i])
			o1.push_back(i);
		if (!c[i] && a[i])
			o2.push_back(i);
		if (!c[i] && !a[i])
			o4.push_back(i);
	}
	int s1 = o1.size(), s2 = o2.size(), s3 = o3.size(), s4 = o4.size();
	for (int i = 0; i <= s1; ++i)
	{
		for (int j = 0; j <= s2; ++j)
		{
			int p = max(i, j) - min(i, j);
			if (s3 >= p && ((s3 - p) & 1) == 0)
			{
				s1 = i + s2 - j;
				if (i < j)
					s1 += (j - i);
				s1 += ((s3 - p) >> 1);
				if (s1 <= n / 2 && s1 + s4 >= n / 2)
				{
					print(i, j);
					return 0;
				}
			}
		}
	}
	printf("-1");
	return 0;
}