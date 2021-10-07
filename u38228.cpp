#include <iostream>
#include <cstdio>
#define rt register long long
#define ll long long
using namespace std;
ll read()
{
	rt a = 0;
	register char ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		a = a * 10 + ch - '0',
		ch = getchar();	
	return a;
} 
void write(const ll& i)
{
	if (i / 10)
		write(i / 10);
	putchar(i % 10 + '0');
}
int main()
{
	rt s = 1;
	rt k, m;
	k = read(),
	m = read();
	for (rt m = 2; m <= 1000; ++m)
	for (rt k = 0; k < m; ++k)
	{
	s = 1;
	for (rt i = 1; ; ++i, s = 1 + s * 10, s %= m)
	{
		if (i > m * 1000)
			break;
		if (s % m == k)
		{
			cout << "\t";
			write(k);
			cout << "\t";
			write(m);
			cout << "\t";
			write(i);
			cout << endl;
			break;
		}
	}
		
	 } 
	return 0;
}
