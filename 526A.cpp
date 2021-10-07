#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n, a[200];
int main()
{
	ll ans = 0x7fffffffffffffff, anst;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
	{
		anst = 0;
		for (int j = 2; j <= n; ++j)
		{
			anst += a[j] * (((j - i < 0 ? i - j : j - i) + (i - 1)) * 4);
		}
		ans = min(ans, anst);
	}
	cout << ans;
	return 0;
}