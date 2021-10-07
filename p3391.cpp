#include <iostream>
#include <cstdio>
#define il inline
#define re register
#define gc getchar
using namespace std;
const int MAX = 1000000;
int rt;
struct node
{
	int son[2], val;
	int sze;
	int tag, fa;
}st[MAX];
int cnt;
il void updata(int x)
{
	st[x].sze = st[st[x].son[0]].sze + st[st[x].son[1]].sze + 1;
}
void rotate(int x, int& k)
{
	int y = st[x].fa;
	int z = st[y].fa;
	int l, r;
	l = st[y].son[1] == x;
	r = l ^ 1;
	if (y == k)
		k = x;
	else
		st[z].son[st[z].son[1] == y] = x;
	st[x].fa = z;
	st[y].fa = x;
	st[st[x].son[r]].fa = y;
	st[y].son[l] = st[x].son[r];
	st[x].son[r] = y;
    updata(y);
    updata(x);
}
void splay(int x, int& k)
{
	int y, z;
	while (x != k)
	{
		y = st[x].fa;
		z = st[y].fa;
		if (y != k)
        {
			if (st[z].son[1] == y ^ st[y].son[1] == x)
				rotate(x, k);
			else
				rotate(y, k);
        }
		rotate(x, k);
	}
}
void push_down(int o)
{
    if (st[o].tag)
    {
        if (st[o].son[0])
            st[st[o].son[0]].tag ^= 1;
        if (st[o].son[1])
            st[st[o].son[1]].tag ^= 1;
        st[o].tag = 0;
        swap(st[o].son[0], st[o].son[1]);
    }
}
int find(int k)
{
	int o = rt, ans = 0;
	while (true)
	{
		push_down(o);
		if (st[st[o].son[0]].sze + ans + 1 == k)
		{
            return o;
        }
        if (st[st[o].son[0]].sze + ans + 1 < k)
            ans += st[st[o].son[0]].sze + 1,
            o = st[o].son[1];
        else
            o = st[o].son[0];
    }
}
void insert(int& o, int k, int f)
{
	if (!o)
		o = ++cnt,
		st[o].fa = f,
		st[o].val = k - 1,
		st[o].sze = 1,
		splay(o, rt);
	else
		insert(st[o].son[st[o].val < k], k, o);
}
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
int n;
void dfs(int o)
{
    if (!o)
        return;
    push_down(o);
    dfs(st[o].son[0]);
    if (st[o].val > 0 && st[o].val <= n)
        printf("%d ", st[o].val);
    dfs(st[o].son[1]);
}
int main()
{
    int m, l, r, ll, rr;
    rd(n, m);
    for (int i = 1; i <= n + 2; ++i)
        insert(rt, i, 0);
    for (int i = 1; i <= m; ++i)
    {
        rd(l, r);
        ll = find(l);
        rr = find(r + 2);
        splay(ll, rt);
        splay(rr, st[ll].son[1]);
        st[st[st[rt].son[1]].son[0]].tag ^= 1;
        // dfs(rt);
        // cout << endl;
    }
    dfs(rt);
    return 0;
}