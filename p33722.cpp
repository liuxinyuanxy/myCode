#include <iostream>
#include <cstdio>
#define _ 300000
#define lowbit(x) ((x) & -(x)) 
using namespace std;
long long sum[_], del1[_], del2[_];
long long rd()
{
	long long s = 0, p = 1; char ch;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = getchar();
	while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9');
	return s * p;
}
int n = rd(), m = rd();
void add(int x, long long w, long long* tree)
{
	while (x <= n)
		tree[x] += w,
		x += lowbit(x);
}
long long ask(int x, long long* tree)
{
	long long ans = 0;
	while (x)
		ans += tree[x],
		x -= lowbit(x);
	return ans;
}
void change(int x, int y, long long w)
{
	add(y + 1, -w, del1);
	add(x, w, del1);
	add(y + 1, -w * (y + 1), del2);
	add(x, w * x, del2);
}
void query(int x, int y)
{
	printf("%lld\n", (sum[y] + (y + 1) * ask(y, del1) - ask(y, del2)) - (sum[x - 1] + x * ask(x - 1, del1) - ask(x - 1, del2)));
}
int main()
{
	int opt, x, y;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + rd();
	for (int i = 1; i <= m; ++i)
	{
		opt = rd(), x = rd(), y = rd();
		if (opt == 1)
			change(x, y, rd());
		else
			query(x, y);
	}
	return 0;
}


