#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string s1, s2, s3;
int change[10000];
int main()
{
	int l1, l2;
	cin >> s1 >> s2;
	l1 = s1.length();
	l2 = s2.length();
	for (int i = 0; i < l1; ++i)
		if (s1[i] >= 'a')
			change[i] = s1[i] - 'a';
		else
			change[i] = s1[i] - 'A';
	for (int i = 0; i < l2; ++i)
	{
		if (s2[i] >= 'a')
			s2[i] = (s2[i] - 'a'  - change[i % l1] + 26) % 26 + 'a';
		else
			s2[i] = (s2[i] - 'A'  - change[i % l1] + 26) % 26 + 'A';
		putchar(s2[i]);
	}
	return 0;
}
