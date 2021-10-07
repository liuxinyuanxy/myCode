#include <iostream>
#include <cstdio>
#include <cstring>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 3000000
using namespace std;
char ch1[_], ch2[_];
int nxt[_], len1, len2;
int main()
{
	rt p = 0;
	cin >> (ch1 + 1) >> (ch2 + 1);
	len1 = strlen(ch1 + 1);
	len2 = strlen(ch2 + 1);
	for (rt i = 2; i <= len2; ++i)
	{
		p = nxt[i - 1];
		while (ch2[p + 1] != ch2[i] && p)
			p = nxt[p];
		if (ch2[p + 1] == ch2[i])
			nxt[i] = p + 1;
		else
			nxt[i] = 0;
	}
	int j = 0;
	for (rt i = 1; i <= len1; ++i)
	{
		while (ch1[i] != ch2[j + 1] && j)
			j = nxt[j];
		if (ch1[i] == ch2[j + 1])
			++j;
		if (j == len2)
		{
			printf("%d\n", i - len2 + 1);
			j = nxt[j];
		}
	}
	for (rt i = 1; i <= len2; ++i)
		printf("%d ", nxt[i]);
	return 0;
}


