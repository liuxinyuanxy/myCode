#include <iostream>
#include <cstdio>
#define ll long long
#define MAX 4000000
using namespace std;
int h[MAX], v[MAX];
ll ans[MAX];
int qu[MAX], l, r, id[MAX];
int main()
{
	ll aans = 0;
	int n;
	scanf ("%d", &n);
	l = r = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf ("%d%d", &h[i], &v[i]);
		while (r != l && qu[r - 1] < h[i])
			--r;
		if (r != l)
		{
			ans[id[r - 1]] += v[i];
		}
		qu[r++] = h[i];
		id[r - 1] = i;
	}
	l = r = 0;
	for (int i = n; i >= 1; --i)
	{
		while (r != l && qu[r - 1] < h[i])
			--r;
		if (r != l)
		{
			ans[id[r - 1]] += v[i];
		}
		qu[r++] = h[i];
		id[r - 1] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		aans = max(aans, ans[i]);
	}
	printf("%lld", aans);
	return 0;
}

