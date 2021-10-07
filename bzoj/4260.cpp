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
int son[_][2], tot;
int a[_];
int part[34];
int two[34];
int root = 1;
il void add(rt s)
{
	rt o = root;
	for (rt i = 30; i >= 0; --i)
		if (son[i][(s >> i) & 1])
			o = son[i][(s >> i) & 1];
		else
			o = son[i][(s >> i) & 1] = ++tot;
}
int main()
{
	int n, s = 0, temp, o;
	scanf ("%d", &n);
	two[0] = 1;
	for (rt i = 1; i <= 30; ++i)
		two[i] = two[i - 1] << 1;
	for (rt i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (rt i = 1; i <= n; ++i)
	{
		o = root;
		s ^= a[i];
		temp = 0;
		for (rt j = 30; j >= 0; --j)
		{
			if (son[o][((s >> j) & 1) ^ 1])
				temp ^= (s & (1 << j)) ^ (1 << j),
				o = son[o][((s >> j) & 1) ^ 1];
			else
				temp ^= (s & (1 << j)),
				o = son[o][(s >> 1) & 1];
		}
		add(s);
	}
	return 0;
}
