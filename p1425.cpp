#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d;
	f = c * 60 + d - a * 60 - b;
	e = f / 60;
	f %= 60;
	cout << e << " " << f;
	return 0;
}

