#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-6
#define new_node() (++cnt)
#define mid(l, r) (((l) + (r)) >> 1)
#define sqr(x) ((x) * (x))
using namespace std;
const int N = 1000000;
struct node
{
	int ls, rs;
	int l, r;
	double val, sqval;
	double tag;
	int sze()
	{
		return this->r - this->l + 1;
	}
}st[N];
int rt, cnt = 0;
void updata(int o)
{
	st[o].val = st[st[o].ls].val + st[st[o].rs].val;
	st[o].sqval = st[st[o].ls].sqval + st[st[o].rs].sqval;
}
void pushdown(int x)
{
	if (fabs(st[x].tag) > eps)
	{
		int l = st[x].ls, r = st[x].rs;
		double o = st[x].tag;
		st[l].sqval += st[l].sze() * sqr(o)  + 2 * o * st[l].val;
		st[r].sqval += st[r].sze() * sqr(o)  + 2 * o * st[r].val;
		st[l].val += o * st[l].sze();
		st[r].val += o * st[r].sze();
		st[l].tag += o;
		st[r].tag += o;
		st[x].tag = 0;
	}
}
void build(int& o, int l, int r)
{
	o = new_node();
	st[o].l = l, st[o].r = r;
	st[o].tag = 0;
	if (l == r)
	{
		scanf("%lf", &st[o].val);
		st[o].sqval = sqr(st[o].val);
	}
	else
	{
		build(st[o].ls, l, mid(l, r)),
		build(st[o].rs, mid(l, r) + 1, r);
		updata(o);
	}
}
void modify(int o, int l, int r, double c)
{
	if (l == st[o].l && r == st[o].r)
	{
		st[o].tag += c;
		st[o].sqval += st[o].sze() * sqr(c) + 2 * c * st[o].val;
		st[o].val += c * st[o].sze();
		return;
	}
	pushdown(o);
	int m = mid(st[o].l, st[o].r);
	if (r <= m)
		modify(st[o].ls, l, r, c);
	else
		if (l > m)
			modify(st[o].rs, l, r, c);
		else
			modify(st[o].ls, l, m, c),
			modify(st[o].rs, m + 1, r, c);
	updata(o);
}
double sum, sqsum;
void get_ans(int o, int l, int r)
{
	if (st[o].l == l && st[o].r == r)
	{
		sum += st[o].val;
		sqsum += st[o].sqval;
		return;
	}
	pushdown(o);
	int m = mid(st[o].l, st[o].r);
	if (r <= m)
		get_ans(st[o].ls, l, r);
	else
		if (l > m)
			get_ans(st[o].rs, l, r);
		else
			get_ans(st[o].ls, l, m),
			get_ans(st[o].rs, m + 1, r);
}
int main()
{
	int n, m, opt, l, r;
	double c;
	scanf("%d%d", &n, &m);
	build(rt, 1, n);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &opt, &l, &r);
		if (opt == 1)
		{
			scanf("%lf", &c);
			// cout << c << endl;
			modify(rt, l, r, c);
		}
		else
		{
			sum = sqsum = 0;
			get_ans(rt, l, r);
			double p = sum / (r - l + 1);
			if (opt == 2)
			{
				printf("%.4lf\n", p);
			}
			else
			{
				printf("%.4lf\n", sqsum / (r - l + 1) - sqr(p));
			}
		}
	}
	return 0;
}