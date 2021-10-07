#include <iostream>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;
int ans = 0;
map<int, int> g;
int three(ll x)
{
	if (x == 1)
		return 1;
	return g[x] ? g[x] : g[x] =  1 + (x & 1 ? three(x * 3 + 1) : three(x >> 1));
}
int main()
{
	int i, j;
	bool p = 1;
	while (scanf("%d%d", &i, &j))
	{
		ans = 0;
		if (i > j)
			swap(i, j),
			p = 0;
		for (int k = i; k <= j; ++k)
			ans = max(ans, three(k));
		if (!p)
			swap(i, j);
		printf("%d %d %d\n", i, j, ans);
	} 
	return 0;
}
