#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#define gc getchar
#define il inline
#define int LL
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
		;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
	read(s), read(args...);
}
bool flag = 0;
const int MAXN = 50005;
int a[MAXN];
int c, M;
int phi[100];
int qpw[3][105][10005], lim[3][105][10005];
void init()
{
	for (int i = 0; i <= M; ++i)
	{
		qpw[1][i][0] = 1;
		for (int j = 1; j <= 10000; ++j)
		{
			qpw[1][i][j] = qpw[1][i][j - 1] * c;
			if (qpw[1][i][j] >= phi[i])
				lim[1][i][j] = 1, qpw[1][i][j] %= phi[i];
			lim[1][i][j] |= lim[1][i][j - 1];
		}
	}
	for (int i = 0; i <= M; ++i)
	{
		qpw[2][i][0] = 1;
		lim[2][i][1] = lim[1][i][10000];
		for (int j = 1; j <= 10000; ++j)
		{
			qpw[2][i][j] = qpw[2][i][j - 1] * qpw[1][i][10000];
			if (qpw[2][i][j] >= phi[i])
				lim[2][i][j] = 1, qpw[2][i][j] %= phi[i];
			lim[2][i][j] |= lim[2][i][j - 1];
		}
	}
}
int qpow(int b, int p)
{
	flag = 0;
	int x1 = b % 10000, x2 = b / 10000;
	int ans = qpw[1][p][x1] * qpw[2][p][x2];
	flag |= lim[1][p][x1] | lim[2][p][x2];
	if (ans >= phi[p])
		flag = 1, ans %= phi[p];
	return ans;
}
int get(int ai, int sum, int now)
{
	flag = 0;
	// if (phi[now] == 1)
	// 	return (c == 1 || (ai == 0 && sum == 1)) ? 1 : 0;
	if (sum == 0)
	{
		if (ai >= phi[now])
			flag = 1, ai %= phi[now];
		return ai;
	}
	int tmp = get(ai, sum - 1, now + 1);
	return qpow((flag ? (tmp + phi[now + 1]) : tmp), now);
}
int get_phi(int x)
{
	int ans = x;
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
			ans -= ans / i;
		while (x % i == 0)
			x /= i;
	}
	if (x != 1)
		ans -= ans / x;
	return ans;
}
int p;
struct node
{
	int l, r, val;
	int minc;
	node *ls, *rs;
} sta[MAXN << 2];
node *rt;
int cnt = 0;
#define new_node() (&sta[++cnt])
void update(node *o)
{
	o->minc = min(o->ls->minc, o->rs->minc);
	o->val = (o->ls->val + o->rs->val) % p;
}
void build(int l, int r, node *&o)
{
	o = new_node();
	o->l = l, o->r = r, o->val = o->minc = 0;
	if (l != r)
		build(l, (l + r) >> 1, o->ls), build(((l + r) >> 1) + 1, r, o->rs), update(o);
	else
		o->val = a[l] % p, o->ls = o->rs = 0;
}
void modify(int l, int r, node *o)
{
	// cout << o->l << " " << o->r << " ! ";
	if (o->minc > M)
		return;
	if (o->l == o->r)
	{
		++o->minc;
		o->val = get(a[l], o->minc, 0);
		return;
	}
	if (o->l == l && o->r == r)
	{
		modify(l, (l + r) >> 1, o->ls), modify(((l + r) >> 1) + 1, r, o->rs);
		update(o);
		return;
	}
	int mid = (o->l + o->r) >> 1;
	if (r <= mid)
		modify(l, r, o->ls);
	else if (l > mid)
		modify(l, r, o->rs);
	else
		modify(l, mid, o->ls), modify(mid + 1, r, o->rs);
	update(o);
}
int query(int l, int r, node *o)
{
	// cout << o->l << " " << o->r << " ! ";
	if (o->l == l && o->r == r)
		return o->val % p;
	int mid = (o->l + o->r) >> 1;
	if (r <= mid)
		return query(l, r, o->ls);
	else if (l > mid)
		return query(l, r, o->rs);
	else
		return (query(l, mid, o->ls) + query(mid + 1, r, o->rs)) % p;
}
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("p3747.in", "r", stdin);
	freopen("p3747_my.out", "w", stdout);
	int n, m, op, l, r;
	read(n, m, p, c);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	build(1, n, rt);
	phi[0] = p;
	for (M = 1;; ++M)
	{
		phi[M] = get_phi(phi[M - 1]);
		// cout << phi[M] << " ";
		if (phi[M] == 1)
			break;
	}
	// cout << endl;
	phi[M + 1] = 1;
	init();
	// cout << M << endl;
	for (int i = 1; i <= m; ++i)
	{
		read(op, l, r);
		if (op)
			cout << query(l, r, rt) << endl;
		else
			modify(l, r, rt);
		// cout << endl;
	}
	return 0;
}