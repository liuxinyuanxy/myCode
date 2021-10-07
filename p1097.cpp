#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
map<int, int> m;
set<int> s;
inline int read()
{
	int a = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0',
		ch = getchar();
	return a;
}
int main()
{
	int n, t;
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		t = read();
		s.insert(t);
		++m[t];
	}
	for (auto x : s)
	{
		printf("%d %d\n", x, m[x]);
	}
}
