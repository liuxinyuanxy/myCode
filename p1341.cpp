#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool vis[100000];
struct node
{
	int num, to;	
}temp;
vector <node> p[130];
int tot;
int ans[100000];
int n;
int s = 0x3ffff;
int du[130];
int front = 0x3ffff , back = 0;
inline void add(int a, int b)
{
	++tot;
	front = min(min(a, b), front);
	back = max(max(a, b), back);
	++du[a];
	++du[b];
	temp.num = tot;
	temp.to = b;
	p[a].push_back(temp);
	temp.to = a;
	p[b].push_back(temp);
}
inline bool check()
{
	int tot = 0;
	for (int i = front; i <= back; ++i)
	{
		if (du[i] & 1)
		{
			++tot;
			s = min(s, i);
			if (tot > 2)
				return false;
		}
	}
	return true;
}
inline void print()
{
	for (int i = 1; i <= n + 1; ++i)
		printf("%c", ans[i]);
	exit(0);
}
void dfs(int x, int c)
{
	ans[c] = x;
	if (c == n + 1)
	{
		print();
	}
	int len = p[x].size();
	node t;
	for (int i = 0; i < len; ++i)
	{
		t = p[x][i];
		if (!vis[t.num])
		{
			vis[t.num] = 1;
			dfs(t.to, c + 1);
			vis[t.num] = 0;
		}
	}
}
int main()
{
	char c1, c2;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		c1 = getchar();
		while (!isalpha(c1))
			c1 = getchar();
		c2 = getchar();
		while (!isalpha(c2))
			c2 = getchar();
		add(c1, c2);
	}
	if (!check())
	{
		printf("No Solution\n");
		return 0;
	}
	if (s != 0x3ffff)
		dfs(s, 1);
	else
		dfs(front, 1);
	return 0;
}
