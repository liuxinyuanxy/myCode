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
il void exgcd(rt a, rt b, rt& x, rt& y, rt& gcd)
{
	if (!b)
		gcd = a, x = 1, y = 0;
	else
		exgcd(b, a % b, y, x, gcd),
		y -= (a / b) * x;
}
//ax = 1 (mod m)
// ax - 1 = my
// ax + my = 1
il int cal(rt a, rt b, rt c)
{
	rt x, y, GCD;
	exgcd(a, b, x, y, GCD);
	if (c % GCD)
		return -1;
	x = x * c / GCD;
	b = b / GCD;
	x %= b;
	if (x <= 0)
		x += b;
	return x;
}
int main()
{
	rt T, a, m, ans;
	scanf ("%d", &T);
	while (T--)
	{
		scanf ("%d%d", &a, &m);
		ans = cal(a, m, 1);
		if (ans == -1)
			printf("Not Exist\n");
		else
			printf("%d\n", ans); 
	}
	return 0;
}


