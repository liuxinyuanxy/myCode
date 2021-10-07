#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("in.txt","w", stdout);
	ios::sync_with_stdio(false);
	cout << 1000000 << " ";
	cout << rand() % 1000000 << endl;
	for (rt i = 1; i <= 1000000; ++i)
		cout << rand() % 100000000 + 1 << " ";
	return 0;
}


