#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	n = unique(a + 1, a + 1 + n) - (a + 1);
	if (k > n)
		cout << "NO RESULT";
	else
		cout << a[k];
	return 0;
}