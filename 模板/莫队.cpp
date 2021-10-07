//Äª¶Ó 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define il inline 
#define rt register int
#define _isl(i) (i.x / block)
#define _isr(i) (i.y / block)
#define MAX 1000005
using namespace std;
int block, ans;
int pos[MAX];
int cnt[MAX];
int a[MAX];
int anss[MAX];
struct node{
	int x, y, num;
}que[MAX];
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
il void write(int x)
{
	rt i = 0;
	while (x)
		pos[++i] = x % 10,
		x /= 10;
	for (; i; --i)
		putchar(pos[i] + '0');
	putchar('\n');
}
bool cmp(const node& i, const node& j)
{
	return _isl(i) ^ _isl(j) ? i.x < j.x : (_isl(i) & 1) ? i.y < j.y : i.y > j.y;  
}
il void add(int x)
{
	++cnt[x];
	if (cnt[x] == 1)
		++ans;
}
il void del(int x)
{
	--cnt[x];
	if (!cnt[x])
		--ans;
}
int main()
{
	rt n, m, l, r;
	n = read();
	for (rt i = 1; i <= n; ++i)
		a[i] = read();
	m = read();
	block = n / sqrt(m * 2 / 3);
	for (rt i = 1; i <= m; ++i)
		que[i].x = read(),
		que[i].y = read(),
		que[i].num = i;
	sort(que + 1, que + 1 + m, cmp);
	for (rt i = que[1].x; i <= que[1].y; ++i)
		add(a[i]);
	l = que[1].x,
	r = que[1].y;
	anss[que[1].num] = ans;
	for (rt i = 2; i <= m; ++i)
	{
		while (l < que[i].x) del(a[l++]);
		while (l > que[i].x) add(a[--l]);
		while (r < que[i].y) add(a[++r]);
		while (r > que[i].y) del(a[r--]);
		anss[que[i].num] = ans;
	}
	for (int i = 1; i <= m; ++i)
	{
		write(anss[i]); 
	}
	return 0;
}

