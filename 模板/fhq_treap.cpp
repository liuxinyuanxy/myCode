//fhq_treap
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXN 300000
using namespace std;
int son[MAXN][2], size[MAXN], val[MAXN], rnd[MAXN];
int tot = 0, rt = 0;
inline void updata(int x)
{
	size[x] = size[son[x][0]] + size[son[x][1]] + 1;
}
inline int new_node(int v)
{
	++tot;
	size[tot] = 1;
	rnd[tot] = rand();
	val[tot] = v;
	return tot;
}
int merge(int x, int y)
{
	if (!x || !y)
		return x + y;
	updata(x), updata(y);
	if (rnd[x] < rnd[y])
	{
		son[x][1] = merge(son[x][1], y);
		updata(x);
		return x;
	}
	else
	{
		son[y][0] = merge(x, son[y][0]);
		updata(y);
		return y;
	}
}
void split(int x, int k, int& a, int& b)
{
	if (!x)
	{
		a = b = 0;
		return;
	}
	updata(x);
	if (val[x] <= k)
		a = x,
		split(son[x][1], k, son[x][1], b);
	else
		b = x,
		split(son[x][0], k, a, son[x][0]);
	updata(x);
}
inline void insert(int v)
{
	int a, b;
	split(rt, v, a, b);
	rt = merge(merge(a, new_node(v)), b);
}
inline void del(int v)
{
	int a, b, c;
	split(rt, v, a, c);
	split(a, v - 1, a, b);
	b = merge(son[b][0], son[b][1]);
	rt = merge(merge(a, b), c);
}
inline int find_rank(int x)
{
	int a, b, c;
	split(rt, x - 1, a, b);
	c = size[a] + 1;
	merge(a, b);
	return c;
}
inline int is_rank(int r, int x)
{
	int o = r;
	while(1)
	{
		if (size[son[o][0]] + 1 == x)
		{
			return val[o];	
		}
		else
		{
			if (size[son[o][0]] + 1 > x)
			{
				o = son[o][0];
			}
			else
			{
				x -= size[son[o][0]] + 1;
				o = son[o][1];
			}
		}
	}	
} 
inline int front(int x)
{
	int a, b, c;
	split(rt, x - 1, a, b);
	c = is_rank(a, size[a]);
	rt = merge(a, b);
	return c;
}
inline int back(int x)
{
	int a, b, c;
	split(rt, x, a, b);
	c = is_rank(b, 1);
	rt = merge(a, b);
	return c;
}
int main()
{
	srand(time(NULL));
	int n, opt, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &opt, &x);
		if (opt == 1) insert(x); else
		if (opt == 2) del(x); else
		if (opt == 3) printf("%d\n", find_rank(x)); else
		if (opt == 4) printf("%d\n", is_rank(rt, x)); else
		if (opt == 5) printf("%d\n", front(x)); else
		printf("%d\n", back(x));
	}
	return 0;
}
