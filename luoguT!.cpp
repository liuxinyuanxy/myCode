#include <iostream>
#include <cstdio>
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
ll fib[800000];
int main()
{
	int m, i;
	scanf("%d", &m);
	fib[0] = 0;
	fib[1] = 1;
	for(i = 2;;++i)
	{
		fib[i] = (fib[i - 1] + fib[i - 2]) % m;
		if (!fib[i] && fib[i - 1] == 1)
			break;
	}
	printf("%d", i);
	return 0;
}
