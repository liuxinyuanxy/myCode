#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		LL a0, a1, b0, b1;
		cin >> a0 >> a1 >> b0 >> b1;
		if (a0 % a1 || b1 % b0 || b1 % a1)
			cout << "0\n";
		else
		{
				}
	}
	return 0;
}