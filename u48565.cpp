#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define ull unsigned ll
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define MOD 123456789
using namespace std;
int a[100][100];
int k = 0;
int kkk()
{
	return ++k;
}
ull qpow(ull a, ull b)
{
	ull ans = 1;
	for (; b; b >>= 1, a = a * a % MOD)
		if (b & 1)
			ans = ans * a % MOD;
	return ans;
}
int main()
{
	a[kkk()][kkk()] = kkk();
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
			if (a[i][j])
				cout << i << "\t" << j << "\t" << a[i][j];
	ull k;
	cin >> k;
	cout << qpow(2, k - 1);
	return 0;
}


