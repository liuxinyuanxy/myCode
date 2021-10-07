#include <iostream>
#include <cstdio>
using namespace std;
void exgcd(int& a, int& b, int x, int y, int& gcd)
{
	if (!y)
	{
		a = 1;
		b = 0;
		gcd = x;
	}
	else
	{
		exgcd(b, a, y, x % y, gcd);
		b -= (x / y) * a;
	}
}
int main()
{
	int x1, y1, z1, x2, y2, z2;
	while (scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2))
	{
	int a1, b1, a2, b2, g1, g2;
	exgcd(a1, b1, -x1, -y1, g1);
	a1 = a1 * z1 / g1;
	b1 = b1 * z1 / g1;
	exgcd(a2, b2, -x2, -y2, g2);
	a2 = a2 * z2 / g2;
	b2 = b2 * z2 / g2;
	while (a1 < 0)
		a1 += y1;
	while (a2 < 0)
		a2 += y2;
	
	int p, q, g, c = a2 - a1;
	exgcd(p, q, y1, - y2, g);
	p = p * c / g;
	a1 += y1 * p;
	a2 = - (a1 * x1 + z1) / y1;
	printf("%d %d %d\n", a1, a2, 1);
	}
	return 0;
}
//a1 * x1 + b1 * y1 + z1 = 0
//a1 * x1 = z1 (mod y1)
//a2 * x2 + b2 * y2 + z2 = 0
//a2 * x2 = z2 (mod y2)
//a1 + b1 * x1 == a2 + b2 * x2
//a1 * x1 + y1 * p = z1 (mod y1)
//a2 * x2 + y2 * q = z2 (mod y2) 
//a1 + y1 * p  = a2 + y2 * q 
//y1 / x1 * p - y2 / x2 * q = a2 - a1
