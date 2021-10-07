#include <iostream>
#include <cstdio>
#define gc getchar
#define re register
#define il inline
#define mid(l, r) (((l) + (r)) >> 1)
using namespace std;
const int N = 2000000;
namespace segment_tree
{
	struct node
	{
		int val, ls, rs;
	}st[N];
	int cnt = 0;
	il int new_node()
	{
		return ++cnt;
	}
	il void updata(int o)
	{
		st[o].val = st[st[o].ls].val + st[st[o].rs].val;
	}
	il void modify(int pos, int x, int l, int r, int& o)
	{
		if (!o)
			o = new_node();
		if (l == r)
		{
			st[o].val += x;
			return;
		}
		int m = mid(l, r);
		pos <= m ? modify(pos, x, l, m, st[o].ls) : modify(pos, x, m + 1, r, st[o].rs);
		updata(o);
	}
	il int query(int ql, int qr, int l, int r, int o)
	{
		if (!o)
			return 0;
		if (ql == l && qr == r)
			return st[o].val;
		int m = mid(l, r);
		if (qr <= m)
			return query(ql, qr, l, m, st[o].ls);
		else
			if (ql > m)
				return query(ql, qr, m + 1, r, st[o].rs);
			else
				return query(ql, m, l, m, st[o].ls) + query(m + 1, qr, m + 1, r, st[o].rs);
	}
}
int tree[N];
int a[N];
int cnt;
il void modify(int o, int l, int r, int pos, int k, int p)
{
	segment_tree::modify(k, p, 1, cnt, tree[o]);
	if (l == r)
		return;
	int m = mid(l, r);
	pos <= m ? modify(o << 1, l, m, pos, k, p) : modify((o << 1) | 1, m + 1, r, pos, k, p);
}
il void change(int pos, int k)
{
	modify(1, 1, cnt, a[pos], pos, -1);
	modify(1, 1, cnt, a[pos] = k, pos, 1);
}
il int get_rank(int l, int r, int k, int ql, int qr, int o)
{
	if (ql == l && qr == r)
		return segment_tree::query(q, k - 1, 1, cnt, tree[o]);
	int m = mid(l, r);
	if (qr <= m)
		return get_rank(l, m, k, ql, qr, o << 1);
	else
		if (ql > m)
			return get_rank(m + 1, r, k, ql, qr, (o << 1) | 1);
		else
			return get_rank(l, m, k, ql, m, o << 1) + get_rank(m + 1, r, k, m + 1, qr, (o << 1) | 1);
}
int main()
{

	return 0;
}