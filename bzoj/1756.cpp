#include <iostream>
#include <cstdio>
#define rt register int
#define gc getchar
#define new_node() (&(tree[++cnt]))
#define min(a, b) ((a < b) ? (a) : (b))
#define max(a, b) ((a < b) ? (b) : (a))
using namespace std;
const int MAXN = 1000005;
int cnt, tot;
template <typename T> void rd(T& s)
{
	s = 0;
	bool p = 0;
	char ch;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
	rd(s);
	rd(args...);
}
struct node
{
	int l, r;
	int pre, sa, val, sum;
	node *ls, *rs;
	node() : pre(0), sa(0), val(0), sum(0), ls(NULL), rs(NULL) {}
}tree[MAXN], *root;
node* build(int l, int r)
{
	node* p = new_node();
	p->l = l;
	p->r = r;
	if (l != r)
	{
		p->ls = build(l, (l + r) >> 1),
		p->rs = build(((l + r) >> 1) + 1, r);
	}
	return p;
}
int k;
void push_up(node* o)
{
	o->val = max(o->ls->sa + o->rs->pre, max(o->ls->val, o->rs->val));
	o->pre = max(o->ls->pre, o->ls->sum + o->rs->pre);
	o->sa = max(o->rs->sa, o->rs->sum + o->ls->sa);
	o->sum = o->ls->sum + o->rs->sum;
}
void updata(node* o, int pos)
{
	if (o->l == o->r)
	{
		o->pre = o->sa = o->val = o->sum = k;
		return;
	}
	if (pos <= o->ls->r)
		updata(o->ls, pos);
	else
		updata(o->rs, pos);
	push_up(o);
}
node query(node* p, int l, int r)
{
	if (p->l == l && p->r == r)
		return *p;
	int mid = (p->l + p->r) >> 1;
	if (r <= mid)
		return query(p->ls, l, r);
	else
		if (l > mid)
			return query(p->rs, l, r);
		else
		{
			node t1, t2, t;
			t1 = query(p->ls, l, mid);
			t2 = query(p->rs, mid + 1, r);
			t.val = max(t1.sa + t2.pre, max(t1.val, t2.val));
			t.pre = max(t1.pre, t1.sum + t2.pre);
			t.sa = max(t2.sa, t2.sum +	t1.sa);
			t.sum = t1.sum + t2.sum;
			return t;
		}
}
int main()
{
	int n, m, pos, c;
	rd(n, m);
	root = build(1, n);
	for (int i = 1; i <= n; ++i)
		rd(k),
		updata(root, i);
	for (int i = 1; i <= m; ++i)
	{
		rd(c, pos, k);
		if (c == 2)
			updata(root, pos);
		else
			printf("%d\n", query(root, min(pos, k), max(pos, k)).val);
	}
	return 0;
}