#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
bitset<5000> B;
int s[] = {0, 1, 2, 3, 5, 10, 20};
int main()
{
	int t;
	B = 1;
	for (int i = 1; i <= 6; ++i)
	{
		cin >> t;
		while (t--)
			B |= B << s[i];
	}
	cout << "Total=" << B.count() - 1;
	return 0;
}
