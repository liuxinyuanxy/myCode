#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 100005;
int n;
int g[MAX];
int nxt[MAX];
int tot = 0;
int t[MAX];
int travel(int x)
{
	return g[x] ? g[x] : g[x] = travel(nxt[x]) + 1;
}
int search(int x)
{
	int vis[MAX] = {0}, cnt = 1, i;
	for (i = x; !g[i]; i = nxt[i], ++cnt)
	{
		if (vis[i])
			g[i] = cnt - vis[i];
		else
			vis[i] = cnt;	
	}
	return travel(x);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &nxt[i]);
	}
	for (int i = 1; i <= n; ++i)
		printf("%d\n", search(i));
}
