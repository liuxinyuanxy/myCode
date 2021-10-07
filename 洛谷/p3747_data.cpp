#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
// #include <windows.h>
using namespace std;
int main()
{
	freopen("p3747.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 10 + 1, m = rand() % 1000 + 1, p = rand() % 10 + 1, c = rand() % 10 + 1;
	cout << n << " " << m << " " << p << " " << c << endl;
	for (int i = 1; i <= n; ++i)
	{
		cout << rand() % p << " ";
	}
	cout << endl;
	for (int i = 1; i <= m; ++i)
	{
		cout << rand() % 2 << " ";
		int l = rand() % (n - 1) + 1;
		cout << l << " ";
		cout << rand() % (n - l + 1) + l << endl;
	}
	return 0;
}