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
#define MOD 100000007
#define _ 200005
using namespace std;
ll v[_], a[_], b[_];
il ll rd()
{
	rll s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
int n = rd();
il void change(rll x, rll y, rll z, ll* arr)
{
	for (rt i = x; i <= y; ++i)
		arr[i] = (arr[i] + z + MOD) % MOD;
}
il void query(rll x, rll y)
{
	rll ans = 0;
	for (rt i = x; i <= y; ++i)
		ans = (ans + v[i] + MOD) % MOD;
	printf("%lld\n", ans);
}
int main()
{
	rt m = rd(), opt, tl = 0, tn, t, x, y, z;
	for (rt i = 1; i <= n; ++i)
		v[i] = rd(), a[i] = rd(), b[i] = rd();
	for (rt i = 1; i <= m; ++i)
	{
		opt = rd();
		tn = rd();
		t = tn - tl;
		tl = tn;
		for (rt j = 1; j <= n; ++j)
			v[j] = (v[j] + t * (a[j] * b[j] % MOD) % MOD) % MOD;
		
		x = rd(), y = rd();
		if (opt == 1)
			query(x, y);
		else
		{
			z = rd();
			if (opt == 2)
				change(x, y, z, a);
			else
				if (opt == 3)
					change(x, y, z, b);
				else
					change(x, y, z, v);
		}
//		for (rt j = 1; j <= n; ++j)
//			cout << v[j] << "\t";
//		cout << endl;
//		for (rt j = 1; j <= n; ++j)
//			cout << a[j] << "\t";
//		cout << endl;
//		for (rt j = 1; j <= n; ++j)
//			cout << b[j] << "\t";
//		cout << endl;
	}
	return 0;
}


