#include <iostream>
#include <cstdio>
#include <algorithm>
#define il inline
#define rt register int
#define MAX 1000005
using namespace std;
struct node{
	int x, y, num;
}que[MAX];
int tree[MAX];
int ans[MAX];
int n;
int pos[MAX];
int a[MAX], lst[MAX];
il int lowbit(int x)
{
	return x & -x;
}
il void add(int p, int w)
{
	while (p <= n)
		tree[p] += w,
		p += lowbit(p);
}
il int query(int p)
{
	rt ans = 0;
	while (p)
		ans += tree[p],
		p -= lowbit(p);
	return ans;
}
void write(int x)
{
	rt i = 0;
	while (x)
		pos[++i] = x % 10,
		x /= 10;
	for (; i; --i)
	{
		putchar(pos[i] + '0');
	}
	putchar('\n');
}
il int read()
{
	rt s = 0;
	register char ch;
	ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		s = (s << 1) + (s << 3) + ch - '0',
		ch = getchar();
	return s;
}
bool cmp(const node& i, const node& j)
{
	return i.y == j.y ? i.x < j.x : i.y < j.y;
}
int main()
{
	rt m;
	n = read();
	for (rt i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
	m = read();
	for (rt i = 1; i <= m; ++i)
		que[i].x = read(),
		que[i].y = read(),
		que[i].num = i;
	sort(que + 1, que + 1 + m, cmp);
	int p = 1;
	for (rt i = 1; i <= n; ++i)
	{
		if (lst[a[i]])
		{
			add(lst[a[i]], -1);
		}
		add(i, 1);
		lst[a[i]] = i;
		while (que[p].y == i)
		{
			ans[que[p].num] = query(que[p].y) - query(que[p].x - 1);
			++p;
		}
	}
	for (rt i = 1; i <= m; ++i)
	{
		write(ans[i]);
	}
	return 0;
}

