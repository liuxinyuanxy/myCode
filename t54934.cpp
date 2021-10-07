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
#define max(a, b) ((a) < (b) ? (a) : (b))
#define _ 1000000
using namespace std;
ll a[_], ans[_], cnt[_], n, l, r;
il ll rd()
{
	rll s = 0, p = 1;rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;	
}
void search(rll i, rll k, rll p)
{
	rll sum = 0;
	for (rt j = i + 1; j <= n; ++j)
	{
		if (ans[j] == p && (i == 0 || (a[j] > a[i] + l && a[j] < a[i] + r)))
		{
			sum += cnt[j];
			if (sum >= k)
			{
				printf("%d ", j);
				search(j, k - sum + cnt[j], p - 1); 
				return;
			}
		}
	}
} 
//
int main()
{
	n = rd();
	rll k = rd(), aans = 1;
	l = rd(), r = rd();
	for (rt i = 1; i <= n; ++i)
		a[i] = rd(),
		ans[i] = cnt[i] = 1;
	for (rt i = n - 1; i >= aans; --i)
	{
		for (rt j = i + 1; j <= n - aans + 1; ++j)
		{
			if (a[j] > a[i] + l && a[j] < a[i] + r && ans[j] + 1 >= ans[i])
			{
				if (ans[j] + 1 == ans[i])
					cnt[i] += cnt[j];
				else
					ans[i] = ans[j] + 1,
					cnt[i] = cnt[j];
			}
			aans = max(aans, ans[i]);
		}
	}
	printf("%lld\n", aans);
	search(0, k, aans);
	return 0;
}


