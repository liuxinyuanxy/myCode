//manacher
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
char ch[33000000] = {'&'};
int ans[33000000];
int id, md;
int len = 1;
int main()
{
	char t;
	ch[len] = '#';
	t = getchar();
	while (isalpha(t))
	{
		ch[++len] = t;
		ch[++len] = '#';
		t = getchar();
	}
	for (int i = 1; i <= len; ++i)
	{
		if (md > i)
			ans[i] = min(ans[2 * id - i], md - i);
		else
			ans[i] = 1;
		for (; ch[i - ans[i]] == ch[i + ans[i]]; ++ans[i]);
		if (ans[i] + i > md)
			md = ans[i] + i,
			id = i;
	}
	int a = 0;
	for (int i = 1; i <= len; ++i)
	{
		a = max(a, ans[i]);
	}
	printf("%d", a - 1);
	return 0;
}
