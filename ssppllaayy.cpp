#include <iostream>
#include <cstdio>
#define gc getchar
#define re register
#define LL long long
#define il inline
#define mid(l, r) (((l) + (r)) >> 1)
using namespace std;
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
const int N = 550000;
int rt;
int son[N][2], fa[N], sze[N], val[N], ms[N], sum[N], ml[N], mr[N];
int tag1[N], tag2[N];
il void updata(int o)
{
	int ls = son[o][0], rs = son[o][1];
	sze[o] = sze[ls] + sze[rs] + 1;
	sum[o] = sum[ls] + sum[rs] + val[o];
	ms[o] = max(max(ms[ls], ms[rs]), mr[ls] + ml[rs] + val[o]);
	ml[o] = max(ml[ls], sum[ls] + val[o] + ml[rs]);
	mr[o] = max(mr[rs], sum[rs] + val[o] + mr[ls]);
}
il void push_down(int o)
{
	int ls = son[o][0], rs = son[o][1], c = val[o];
	if (tag1[o])
	{
		tag1[o] = 0;
		tag2[ls] = tag2[rs] = 0;
		if (ls)
		{
			tag1[ls] = 1;
			val[ls] = c;
			sum[ls] = sze[ls] * c;
			if (c > 0)
				ms[ls] = ml[ls] = mr[ls] = sum[ls];
			else
				ms[ls] = c,
				ml[ls] = mr[ls] = 0;
		}
		if (rs)
		{
			tag1[rs] = 1;
			val[rs] = c;
			sum[rs] = sze[rs] * c;
			if (c > 0)
				ms[rs] = ml[rs] = mr[rs] = sum[rs];
			else
				ms[rs] = c,
				ml[rs] = mr[rs] = 0;
		}
	}
	if (tag2[o])
	{
		tag2[o] ^= 1;
		tag2[ls] ^= 1;
		tag2[rs] ^= 1;
		swap(son[ls][0], son[ls][1]);
		swap(son[rs][0], son[rs][1]);
		swap(ml[ls], mr[ls]);
		swap(ml[rs], mr[rs]);
	}
}
void rotate(int x, int &k)
{
	int y = fa[x], z = fa[y];
	int l = son[y][1] == x, r = l ^ 1;
	if (y == k)
		k = x;
	else
		son[z][son[z][1] == y] = x;
	fa[x] = z;
	fa[y] = x;
	fa[son[x][r]] = y;
	son[y][l] = son[x][r];
	son[x][r] = y;
	updata(y);
	updata(x);
}
void splay(int x, int& k)
{
	int y, z;
	while (x != k)
	{
		y = fa[x], z = fa[y];
		if (y != k)
		{
			if (son[z][1] == y ^ son[y][1] == x)
				rotate(x, k);
			else
				rotate(y, k);
		}
		rotate(x, k);
	}
}
int find(int x, int k)
{
	push_down(x);
	int ls = son[x][0];
	if (sze[ls] + 1 == k)
		return x;
	if (sze[ls] + 1 < k)
		return find(son[x][1], k - sze[ls]- 1);
	return find(ls, k);
}
il int split(int pos, int tot)
{
	int l = find(rt, pos), r = find(rt, pos + tot + 1);
	splay(l, rt);
	splay(r, son[rt][1]);
	return son[r][0];
}
il void init(int o)
{
	son[o][0] = son[o][1] = fa[o] = val[o] = sze[o] = ms[o] = sum[o] = ml[o] = mr[o] = tag1[o] = tag2[o] = 0;
}
int a[N], fre[N], tot, cnt = 0;
il int new_node()
{
	return tot ? fre[tot--] : ++cnt;
}
void build(int& o, int l, int r, int f)
{
	if (l > r)
		return;
	int m = mid(l, r);
	o = new_node();
	init(o);
	fa[o] = f;
	sze[o] = r - l + 1;
	val[o] = a[m];
	if (l == r)
	{
		ms[o] = sum[o] = val[o];
		ml[o] = mr[o] = max(0, val[o]);
		return;
	}
	build(son[o][0], l, m - 1, o);
	build(son[o][1], m + 1, r, o);
	updata(o);
}
void insert(int pos, int tot)
{
	for (int i = 1; i <= tot; ++i)
	{
		rd(a[i]);
	}
	int l = find(rt, pos + 1), r = find(rt, pos + 2);
	splay(l, rt);
	splay(r, son[rt][1]);
	build(son[r][0], 1, tot, r);
	updata(r);
	updata(l);
}
void clear(int& o)
{
	if (son[o][0])
		clear(son[o][0]);
	if (son[o][1])
		clear(son[o][1]);
	fre[++tot] = o;
	init(o);
}
void del(int pos, int tot)
{
	int o = split(pos, tot), f = fa[o];
	clear(o);
	son[f][0] = 0;
	updata(f);
	updata(fa[f]);
}
void modify(int pos, int tot, int c)
{
	int o = split(pos, tot);
	tag1[o] = 1;
	tag2[o] = 0;
	val[o] = c;
	sum[o] = c * sze[o];
	if (c > 0)
		ms[o] = ml[o] = mr[o] = sum[o];
	else
		ms[o] = c,
		ml[o] = mr[o] = 0;
	updata(fa[o]);
	updata(fa[fa[o]]);
}
void reverse(int pos, int tot)
{
	int o = split(pos, tot);
	tag2[o] ^= 1;
	swap(son[o][0], son[o][1]);
	swap(ml[o], mr[o]);
	updata(fa[o]);
	updata(fa[fa[o]]);
}
void get_sum(int pos, int tot)
{
	int o = split(pos, tot);
	printf("%d\n", sum[o]);
}
void get_maxsum()
{
	printf("%d\n", ms[rt]);
}
void finish()
{
	char ch;
	while (ch = gc(), !isspace(ch))
		;
}
int get_opt()
{
	char ch;
	while (ch = gc(), !isalpha(ch))
		;
	if (ch == 'I')
	{
		finish();
		return 1;
	}
	if (ch == 'D')
	{
		finish();
		return 2;
	}
	if (ch == 'M')
	{
		ch = gc();
		ch = gc();
		if (ch == 'K')
		{
			finish();
			return 3;
		}
		else
		{
			finish();
			return 6;
		}
	}
	if (ch == 'R')
	{
		finish();
		return 4;
	}
	finish();
	return 5;
}
const int INF = 0x3f3f3f3f;
int main()
{
	int n, m;
	rd(n, m);
	ms[0] = -INF;
	a[1] = a[n + 2] = -INF;
	for (int i = 2; i <= n + 1; ++i)
	{
		rd(a[i]);
	}
	build(rt, 1, n + 2, 0);
	int pos, tot;
	for (int i = 1; i <= m; ++i)
	{
		int opt = get_opt();
		if (opt == 6)
		{
			get_maxsum();
		}
		else
		{
			rd(pos, tot);
			if (opt == 1)
			{
				insert(pos, tot);
			}
			if (opt == 2)
			{
				del(pos, tot);
			}
			if (opt == 3)
			{
				int c;
				rd(c);
				modify(pos, tot, c);
			}
			if (opt == 4)
			{
				reverse(pos, tot);
			}
			if (opt == 5)
			{
				get_sum(pos, tot);
			}
		}
	}
	return 0;
}