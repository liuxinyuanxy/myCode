#include <iostream>
#include <cstdio>
#include <algorithm>
#define gc getchar
#define re register
using namespace std;
template <typename T> void rd(T& s)
{
    s = 0;
    re bool p = 0;
    re char ch;
    while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9');
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
    s *= (p ? -1 : 1);
}
template <typename T, typename... Args> void rd(T& s, Args&... args)
{
    rd(s);
    rd(args...);
}
const int MAX = 30000000;
const int MAXN = 100005;
struct Node
{
    int val;
    int ls, rs;
    Node(int val, int ls, int rs) : val(val), ls(ls), rs(rs) {}
    Node() {}
} st[MAX];
int tree[MAXN];
int cnt;
#define new_node(v, x, y) ((st[++cnt] = Node(v, x, y)), cnt)
void modify(re int &o, re int x, re int k, re int l, re int r)
{
    if (!o)
        o = new_node(0, 0, 0);
    st[o].val += k;
    if (l == r)
        return;
    if (x <= ((l + r) >> 1))
        modify(st[o].ls, x, k, l, (l + r) >> 1);
    else
        modify(st[o].rs, x, k, ((l + r) >> 1) + 1, r);
}
int query(re int o, re int l, re int r, re int ll, re int rr)
{
    if (!o)
        return 0;
    if (ll == l && rr == r)
        return st[o].val;
    re int mid = (ll + rr) >> 1;
    return (r <= mid ? query(st[o].ls, l, r, ll, mid) : (l > mid ? query(st[o].rs, l, r, mid + 1, rr) : query(st[o].ls, l, mid, ll, mid) + query(st[o].rs, mid + 1, r, mid + 1, rr)));
}
#define LL long long
#define lowbit(x) ((x) & -(x))
int a[MAXN];
int hs[MAXN];
int n;
void add(re int pos, re int x, re int k)
{
    for (re int i = pos; i <= n; i += lowbit(i))
        modify(tree[i], x, k, 1, n);
}
LL que(re int x, re int y)
{
    LL ans = 0;
    for (re int i = x; i; i -= lowbit(i))
    {
        ans += query(tree[i], 1, y, 1, n);
    }
    return ans;
}
LL q(re int x, re int y)
{
    return que(x - 1, n) + que(n, y - 1) - 2 * que(x - 1, y - 1);
}
int main()
{
    re int m, t;
    re long long ans = 0;
    rd(n, m);
    for (re int i = 1; i <= n; ++i)
    {
        rd(t);
        a[i] = t;
		hs[i] = t;
    }
	sort(hs + 1, hs + 1 + n);
	for (re int i = 1; i <= n; ++i)
	{
		a[i] = lower_bound(hs + 1, hs + 1 + n, a[i]) - hs;
        add(i, a[i], 1);
	}
    for (re int i = 1; i <= n; ++i)
    {
        ans += q(i, a[i]);
    }
    ans /= 2;
    for (re int i = 1; i <= m; ++i)
    {
        printf("%lld ", ans);
        rd(t);
        ans -= q(t, a[t]);
        add(t, a[t], -1);
    }
    printf("%lld ", ans);
    return 0;
}