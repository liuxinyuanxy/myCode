#include <iostream>
#include <cstdio>
#define MAXN 100016
#define new_node(a, b, c, d) (&(t[++cnt] = node(a, b, c, d)))
using namespace std;
int cnt;
struct node
{
	double k;
	int ans, sze;
	node *ls, *rs;
	node (double a, int b, node* c, node* d) : k(a), sze(b), ls(c), rs(d), ans(0) {}
	node () {}
}t[MAXN << 2], *root;
node* build(int x)
{
	node *n = new_node(0, x, 0, 0);
	if (x != 1)
		n->ls = build(x >> 1),
		n->rs = build(x - (x >> 1));
	return n;
}
template <typename T> void rd(T& s)
{
	bool p = 0;
	char ch;
	s = 0;
	while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
int updata(node *a, node *b)
{
	if (!b->ls)
		return a->k < b->k;
	if (a->k > b->ls->k)
		return updata(a, b->rs);
	return b->ans - b->ls->ans + updata(a, b->ls);
}
void modify(node *o, int x, double k)
{
	if (o->sze == 1)
	{
		o->ans = 1;
		o->k = k;
		return;
	}
	if (x <= o->ls->sze)
		modify(o->ls, x, k);
	else
		modify(o->rs, x - o->ls->sze, k);
	o->k = max(o->ls->k, o->rs->k);
	o->ans = o->ls->ans + updata(o->ls, o->rs);
}
int main()
{
	int m, n, x, y;
	rd(n, m);
	root = build(n);
	for (int i = 1; i <= m; ++i)
	{
		rd(x, y);
		modify(root, x, y / (double)(x));
		printf("%d\n", root->ans);
	}
	return 0;
}