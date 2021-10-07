/*
	2018.12.2
	今天自习课闲来无事，把部分学过的模板了打一遍，集中于此文件，便于未来复习
	2018.12.3
	继续补坑
	2018.12.4
	翘了一节微机课来补坑
	2018.12.5
	updata lct
	2018.12.6
	updata quickRead
	2018.12.9
	updata sort
	2018.12.12
	updata 时隔多天, updata inv && suffixSort
	2018.12.23
	updata string && Möbius
	2019.01.21
	准备期末考试，时隔一个月才来机房，然而期末依然炸了qwq
	updata 杜教筛
	2019.02.14
	updata CG
*/

/*
	所有代码未经编译，正确性未知，如有错误欢迎指正
	code by liuxinyuan
*/
#include <algorithm>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace init
{
// Not Recommended
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[1 << 21], *p1 = buf, *p2 = buf;
// 需C++11
template <typename T>
void rd(T &s)
{
	bool p = 0;
	char ch;
	s = 0;
	while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9')
		;
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
// NOIP用
void rd(int &s)
{
	s = 0;
	int p = 0;
	char ch;
	while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9')
		;
	s *= (p ? -1 : 1);
}
char rdch_int()
{
	char ch;
	while (ch = getchar(), ch < '0' || ch > '9')
		;
	return ch;
}
char rdch_char()
{
	char ch;
	while (ch = getchar(), !isalpha(ch))
		;
	return ch;
}
} // namespace init

namespace segment_tree
{
#define mid(l, r) ((l + r) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) (((x) << 1) | 1)
#define fa(x) ((x) >> 1)
#define len(x) (tree[x].r - tree[x].l + 1)
const int N = 1000000;
struct node
{
	long long l, r, val;
	long long lzy1, lzy2;
} tree[N << 4];
inline void updata(int x)
{
	tree[x].val = (tree[ls(x)].val + tree[rs(x)].val);
}
inline void downdata(int x)
{
	if (tree[x].lzy2 > 1)
	{
		tree[ls(x)].lzy2 *= tree[x].lzy2;
		tree[rs(x)].lzy2 *= tree[x].lzy2;
		tree[ls(x)].lzy1 *= tree[x].lzy2;
		tree[rs(x)].lzy1 *= tree[x].lzy2;
		tree[ls(x)].val *= tree[x].lzy2;
		tree[rs(x)].val *= tree[x].lzy2;
	}
	tree[x].lzy2 = 1;
	if (tree[x].lzy1)
	{
		tree[ls(x)].lzy1 += tree[x].lzy1;
		tree[rs(x)].lzy1 += tree[x].lzy1;
		tree[ls(x)].val += tree[x].lzy1 * len(ls(x));
		tree[rs(x)].val += tree[x].lzy2 * len(rs(x));
	}
	tree[x].lzy1 = 0;
}
void build(int i, int l, int r)
{
	tree[i].l = l;
	tree[i].r = r;
	tree[i].lzy1 = 0;
	tree[i].lzy2 = 1;
	if (l == r)
	{
		init::rd(tree[i].val);
		return;
	}
	int m = mid(l, r);
	build(ls(i), l, m),
		build(rs(i), m + 1, r);
	updata(i);
}
void add(int i, int l, int r, long long k)
{
	if (tree[i].l == l && r == tree[i].r)
	{
		tree[i].val += k * len(i);
		tree[i].lzy1 += k;
		return;
	}
	downdata(i);
	int m = mid(tree[i].l, tree[i].r);
	if (l > m)
		add(rs(i), l, r, k);
	else if (r <= m)
		add(ls(i), l, r, k);
	else
		add(ls(i), l, m, k),
			add(rs(i), m + 1, r, k);
	updata(i);
}
void mul(int i, int l, int r, long long k)
{
	if (tree[i].l == l && r == tree[i].r)
	{
		tree[i].lzy1 *= k;
		tree[i].val *= k;
		tree[i].lzy2 *= k;
		return;
	}
	downdata(i);
	int m = mid(tree[i].l, tree[i].r);
	if (l > m)
		mul(rs(i), l, r, k);
	else if (r <= m)
		mul(ls(i), l, r, k);
	else
		mul(ls(i), l, m, k),
			mul(rs(i), m + 1, r, k);
	updata(i);
}
long long query(int i, int l, int r)
{
	if (tree[i].l == l && tree[i].r == r)
		return tree[i].val;
	downdata(i);
	int m = mid(tree[i].l, tree[i].r);
	if (l > m)
		return query(rs(i), l, r);
	else if (r <= m)
		return query(ls(i), l, r);
	else
		return query(ls(i), l, m) + query(rs(i), m + 1, r);
}
} // namespace segment_tree

namespace fenwickTree
{
#define lowbit(x) ((x) & -(x))
const int N = 100000;
int tree[N];
int del1[N], del2[N];
int sum[N];
int tot;
void add(int *d, int x, int k)
{
	while (x <= tot)
		d[x] += k,
			x += lowbit(x);
}
int query(int *d, int x)
{
	int ans = 0;
	while (x)
		ans += d[x],
			x -= lowbit(x);
	return ans;
}
//单点修改 区间查询
void add_point_normal(int x, int k)
{
	add(tree, x, k);
}
int query_interval_normal(int l, int r)
{
	return query(tree, r) - query(tree, l - 1);
}
//区间修改 单点查询
void add_interval_normal(int l, int r, int k)
{
	add(tree, l, k);
	add(tree, r + 1, -k);
}
int query_point_normal(int x)
{
	return query(tree, x);
}
//区间修改 区间查询
void add_interval_special(int l, int r, int k)
{
	add(del1, l, k);
	add(del1, r + 1, -k);
	add(del2, l, k * l);
	add(del2, r + 1, -k * (r + 1));
}
int query_interval_special(int l, int r)
{
	return sum[r] + (r + 1) * query(del1, r) - query(del2, r) - (sum[l - 1] + l * query(del1, l - 1) - query(del2, l - 1));
}
//代替平衡树部分操作
int hs[N]; //大部分情况需将操作数离散化
void del(int x)
{
	--sum[x];
	add(tree, x, 1);
}
void insert(int x)
{
	++sum[x];
	add(tree, x, -1);
}
int find_rank(int x)
{
	int ans = 0, cnt = 0;
	for (int i = 21; i >= 0; --i)
	{
		ans += 1 << i;
		if (ans > tot || cnt + tree[ans] >= x)
			ans -= 1 << i;
		else
			cnt += tree[ans];
	}
	return hs[ans + 1];
}
int my_rank(int x)
{
	int ans = 1;
	--x;
	while (x)
		ans += tree[x],
			x -= lowbit(x);
	return ans;
}
int pre(int x)
{
	insert(x);
	int ans = find_rank(my_rank(x) - 1);
	del(x);
	return ans;
}
int nxt(int x)
{
	insert(x);
	int ans = find_rank(my_rank(x) + sum[x]);
	del(x);
	return ans;
}
} // namespace fenwickTree

namespace lct
{
const int N = 1000000;
int cnt;
int head[N], nxt[N], to[N];
int sze[N], son[N], dep[N], top[N], rk[N], id[N], fa[N], ed[N];
void dfs1(int u)
{
	sze[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = to[i];
		if (v == fa[i])
			continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		dfs1(v);
		sze[u] += sze[v];
		if (sze[v] > sze[son[u]])
			son[u] = v;
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++cnt;
	rk[cnt] = u;
	if (son[u])
		dfs2(son[u], t);
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = to[i];
		if (v == fa[u] || v == son[u])
			continue;
		dfs2(v, v);
	}
	ed[u] = cnt;
}
void add1(int x, int y, int k)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]])
			std::swap(x, y);
		fenwickTree::add_interval_special(id[top[x]], id[x], k);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y])
		std::swap(x, y);
	fenwickTree::add_interval_special(id[y], id[x], k);
}
int query1(int x, int y)
{
	int ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]])
			std::swap(x, y);
		ans += fenwickTree::query_interval_special(id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y])
		std::swap(x, y);
	ans += fenwickTree::query_interval_special(id[y], id[x]);
	return ans;
}
void add2(int x, int k)
{
	fenwickTree::add_interval_special(id[x], ed[x], k);
}
int query2(int x)
{
	return fenwickTree::query_interval_special(id[x], ed[x]);
}
} // namespace lct

namespace eulerFunction
{
const int N = 10000000;
int vis[N];
int phi[N];
int pri[N], cnt;
long long SolveWithlogN(long long n)
{
	int sum = n;
	for (long long i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			sum -= sum / i;
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		sum -= sum / n;
	return sum;
}
int main(int n)
{
	vis[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i])
			pri[++cnt] = i,
			phi[i] = i - 1;
		for (int j = i * 2; pri[j] * i <= n; ++j)
		{
			vis[pri[j] * i] = 1;
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else
				phi[i * pri[j]] = phi[i] * phi[pri[j]];
		}
	}
	return 0;
}
} // namespace eulerFunction

namespace prime
{
void solveWithN(int n)
{
	eulerFunction::main(n);
}
bool solveWithsqrtN(long long n)
{
	if (n == 1)
		return 0;
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return 0;
	return 1;
}
bool solve_develop(int n)
{
	if (n == 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	if (n % 6 != 1 && n % 6 != 5)
		return 0;
	for (long long i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	return 1;
}
} // namespace prime

namespace qpow
{
//please use this when p approaches LONG_LONG_MAX
//warning : this function is very slow(logB)
long long mul(long long a, long long b, long long p)
{
	long long s = 0;
	for (; b; b >>= 1, a = (a + a) % p)
		if (b & 1)
			s = (s + a) % p;
	return s;
}
long long pow_special(long long a, long long b, long long p)
{
	long long s = 1;
	for (; b; b >>= 1, a = mul(a, a, p))
		if (b & 1)
			s = mul(s, a, p);
	return s;
}
long long pow_normal(long long a, long long b, long long p)
{
	long long s = 1;
	for (; b; b >>= 1, a = (a * a % p))
		if (b & 1)
			s = (s * a) % p;
	return s;
}
} // namespace qpow

//haven't finished
namespace exgcd
{
typedef long long ll;
void exgcd(ll a, ll b, ll &x, ll &y, ll &gcd)
{
	if (!b)
		x = 1,
		y = 0,
		gcd = a;
	else
		exgcd(b, a % b, y, x, gcd),
			y -= (a / b) * x;
}
// ax = 1 (mod p)
// (a, p) = 1
ll inv(ll a, ll p)
{
	ll x, y, g;
	exgcd(a, p, x, y, g);
	if (g != 1)
		return -1;
	while (x < 0)
		x += p;
	return x;
}
} // namespace exgcd

namespace inv
{
typedef long long ll;
// p is a prime && (a, p) == 1
ll FermatLittleTheorem(ll a, ll p)
{
	return qpow::pow_special(a, p - 2, p);
	// return qpow::pow_normal(a, p - 2, p);
}
// (a, p) == 1
ll EulerTheorem(ll a, ll p)
{
	return qpow::pow_special(a, eulerFunction::SolveWithlogN(p) - 1, p);
	// return qpow::pow_normal(a, eulerFunction::SolveWithlogN(p) - 1, p);
}
ll exgcd(ll a, ll p)
{
	return exgcd::inv(a, p);
}
void solve_normal(ll n, ll p, ll *ans)
{
	ans[1] = 1;
	for (ll i = 2; i <= n; ++i)
	{
		ans[i] = (-(p / i) * ans[p % i]) % p;
		if (ans[i] < 0)
			ans[i] += p;
	}
}
void solve_fac(ll n, ll p, ll *fac, ll *facinv, ll *inv)
{
	facinv[0] = fac[0] = 1;
	for (ll i = 1; i < p; ++i)
		fac[i] = fac[i - 1] * i % p;
	facinv[p - 1] = EulerTheorem(fac[p - 1], p);
	for (ll i = p - 2; i >= 1; --i)
		facinv[i] = facinv[i + 1] * i % p;
	for (ll i = 1; i < p; ++i)
		inv[i] = facinv[i] * fac[i - 1] % p;
}
} // namespace inv

namespace Möbius
{
const int N = 10000000;
int mu[N] = {0}, vis[N] = {0}, pri[N] = {0}, cnt = 0;
void get_mu(int n)
{
	mu[1] = vis[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i])
			pri[++cnt] = i,
			mu[i] = -1;
		for (int j = 1; j <= cnt && pri[j] * i <= n; ++j)
		{
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
			mu[i * pri[j]] = -mu[i];
		}
	}
}
//f(n) = n / 1 + n / 2 + ... + n / n
int get_sum(int n)
{
	int ans = 0;
	for (int l = 1, r; l <= n; l = r + 1)
	{
		r = (n / (n / l));
		ans += (r - l + 1) * (n / l);
	}
	return ans;
}
} // namespace Möbius

namespace sum
{
typedef long long LL;
const int maxn = 1700000;
int N;
LL s1[maxn + 100], s2[1300];
int vis[1300];
LL S(int n)
{
	if (n <= maxn)
		return s1[n];
	int x = N / n;
	if (vis[x])
		return s2[x];
	vis[x] = 1;
	LL &ans = s2[x];
	ans = (1 + n) * 1ll * n / 2;
	for (int l = 2, r; l <= n; l = r + 1)
	{
		r = (n / (n / l));
		ans -= (r - l + 1) * S(n / l);
	}
	return ans;
}
} // namespace sum

namespace SORT
{
const int N = 100000;
void bubbleSort(int *a, int n)
{
	for (int i = 1; i < n; ++i)
		for (int j = n - 1; j >= i; --j)
			if (a[j] > a[j + 1])
				std::swap(a[j], a[j + 1]);
}
void selectionSort(int *a, int n)
{
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i] > a[j])
				std::swap(a[i], a[j]);
}
void insertSort(int *a, int n)
{
	std::vector<int> v;
	v.push_back(a[1]);
	for (int i = 2; i <= n; ++i)
		v.insert(std::lower_bound(v.begin(), v.end(), a[i]), a[i]);
	for (int i = 1; i <= n; ++i)
		a[i] = v[i - 1];
}
void mergeSort(int *a, int n, int l, int r)
{
	if (l == r)
		return;
	int m = mid(l, r);
	mergeSort(a, n, l, m);
	mergeSort(a, n, m + 1, r);
	std::inplace_merge(a + l, a + m + 1, a + r + 1);
	// int b[N];
	// int l1 = l, r1 = m + 1, l2 = m + 1, r2 = r + 1, p = l;
	// while (l1 < r1 && l2 < r2)
	// 	if (a[l1] <= a[l2])
	// 		b[p++] = a[l1++];
	// 	else
	// 		b[p++] = a[l2++];
	// while (l1 < r1)
	// 	b[p++] = a[l1++];
	// while (l2 < r2)
	// 	b[p++] = a[l2++];
	// for (int i = l; i <= r; ++i)
	// 	a[i] = b[i];
}
void quickSort(int *a, int n, int l, int r)
{
	int x = l, y = r, m = a[mid(l, r)];
	do
	{
		while (a[l] < m)
			++l;
		while (a[r] > m)
			--r;
		if (l <= r)
			std::swap(a[l++], a[r--]);
	} while (l <= r);
	if (l < y)
		quickSort(a, n, l, y);
	if (r > x)
		quickSort(a, n, x, r);
}
} // namespace SORT

namespace suffixSort
{
const int MAXN = 2000000;
int tax[MAXN], tp[MAXN], rak[MAXN], sa[MAXN];
// N : 后缀个数 M : 字符集大小
void redixSort(int N, int M)
{
	for (int i = 0; i <= M; ++i)
		tax[i] = 0;
	for (int i = 1; i <= N; ++i)
		++tax[rak[i]];
	for (int i = 1; i <= M; ++i)
		tax[i] += tax[i - 1];
	for (int i = N; i >= 1; --i)
		sa[tax[rak[tp[i]]]--] = tp[i];
}
void suffixSort(char *ch, int len)
{
	int M = 'z' - '0' + 1;
	for (int i = 1; i <= len; ++i)
		rak[i] = ch[i] - '0' + 1,
		tp[i] = i;
	redixSort(len, M);
	int p = 0;
	for (int w = 1; p < len; w <<= 1, M = p)
	{
		//这里的p仅为计数器
		p = 0;
		for (int i = 1; i <= w; ++i)
			tp[++p] = len - w + i;
		for (int i = 1; i <= len; ++i)
			if (sa[i] > w)
				tp[++p] = sa[i] - w;
		redixSort(len, M);
		std::swap(rak, tp); //此时tp为临时数组用于更新下次字符集和rak数组， 上一次的tp以被丢弃
		rak[sa[1]] = 1;
		//这里的p用于统计字符集大小
		p = 1;
		for (int i = 2; i <= len; ++i)
			rak[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w]) ? p : ++p;
	}
}
char ch[MAXN];
void run()
{
	std::cin >> (ch + 1);
	int len = strlen(ch + 1);
	suffixSort(ch, len);
}
} // namespace suffixSort

namespace KMP
{
//数组从一开始储存哦 qwq
void kmp(char *s1, char *s2, int l1, int l2, int *nxt, int *ans, int &cnt)
{
	cnt = 0;
	nxt[1] = 0;
	for (int i = 2; i <= l2; ++i)
	{
		int p = nxt[i - 1];
		while (s2[p + 1] != s2[i] && p)
			p = nxt[p];
		nxt[i] = s2[p + 1] == s2[i] ? p + 1 : 0;
	}
	int j = 0;
	for (int i = 1; i <= l1; ++i)
	{
		while (j && s1[i] != s2[j + 1])
			j = nxt[j];
		if (s1[i] == s2[j + 1])
			++j;
		if (j == l2)
			ans[++cnt] = j,
			j = nxt[j];
	}
}
} // namespace KMP

namespace manacher
{
const int N = 41000000;
void init(char *ch1, char *ch2, int len1, int &len2)
{
	len2 = 1;
	ch2[0] = '$';
	ch2[1] = '#';
	for (int i = 0; i < len1; ++i)
	{
		ch2[++len2] = ch1[i];
		ch2[++len2] = '#';
	}
}
int manachar(char *ch, int len)
{
	int l[N] = {0}, id = 0, md = 0, ans = 0;
	for (int i = 1; i <= len; ++i)
	{
		if (md > i)
			l[i] = std::min(md - i, l[id * 2 - i]);
		else
			l[i] = 1;
		while (ch[i - l[i]] == ch[i + l[i]])
			++l[i];
		if (i + l[i] > md)
			md = i + l[i],
			id = i;
	}
	for (int i = 1; i <= len; ++i)
		ans = std::max(ans, l[i]);
	return ans - 1;
}
} // namespace manacher

namespace trie
{
const int N = 100000;
struct node
{
	int son[100];
	int val;
	int x;
	int fail;
	node()
	{
		for (int i = 0; i < 100; ++i)
			son[i] = 0;
		val = x = fail = 0;
	}
} trie[N];
int head[N], nxt[N], val[N];
int x[N];
int root;
int cnt;
void add_normal(char *ch, int len)
{
	int o = root;
	for (int i = 0; i < len; ++i)
	{
		if (trie[o].son[ch[i] - '0'])
		{
			o = trie[o].son[ch[i] - '0'];
		}
		else
		{
			trie[o].son[ch[i] - '0'] = ++cnt;
			o = cnt;
		}
	}
	++trie[o].x;
}
void add_special(char *ch, int len)
{
	int o = root;
	for (int i = 0; i < len; ++i)
	{
		int p = 0;
		for (int j = head[o]; j; j = nxt[j])
			if (val[j] == ch[i])
				p = j;
		if (p)
			o = p;
		else
		{
			nxt[++cnt] = head[o];
			head[o] = cnt;
			val[cnt] = ch[i];
			o = cnt;
		}
	}
	++x[o];
}
void get_fail()
{
	const int M = N << 4;
	int qu[M + 2], l, r;
	l = r = 0;
	for (int i = '0' - '0'; i <= 'z' - '0'; ++i)
		if (trie[root].son[i])
			qu[r++] = trie[root].son[i];
	while (l != r)
	{
		int p = qu[l++];
		int t = trie[p].fail;
		if (l > M)
			l = 0;
		for (int i = '0' - '0'; i <= 'z' - '0'; ++i)
			if (trie[p].son[i])
			{
				qu[r++] = trie[p].son[i];
				if (r > M)
					r = 0;
				trie[trie[p].son[i]].fail = trie[t].son[i];
			}
			else
			{
				trie[p].son[i] = trie[t].son[i];
			}
	}
}
int Aho_Corasick_Automaton(char *ch, int len)
{
	int ans = 0;
	int o = root;
	for (int i = 0; i < len; ++i)
	{
		o = trie[o].son[ch[i] - '0'];
		for (int j = o; j && ~trie[j].x; j = trie[j].fail)
			ans += trie[j].x,
				trie[j].x = -1;
	}
	return ans;
}
} // namespace trie
namespace CG
{
#define sqr(x) ((x) * (x))
struct point
{
	double x, y;
};
struct segment
{
	point l, r;
};
inline double dis(point a, point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
struct circle
{
	point cen;
	double r;
};
typedef std::vector<point> polygon;
inline point make_vec(point a, point b)
{
	point x;
	x.x = b.x - a.x;
	x.y = b.y - a.y;
	return x;
}
//点积 a ⊥ b时点积为0
inline double dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}
// 叉积 a ∥ b时叉积为0，b在a逆时针为正，否则为负
// 几何意义是四边形不等式面积
inline double cro(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
// 求多边形面积
// 逆时针储存
inline double area(polygon &a)
{
	double ans = cro(a[a.size()], a[0]);
	for (int i = 0; i < a.size(); ++i)
	{
		ans += cro(a[i], a[i + 1]);
	}
	return ans / 2;
}
// 旋转
inline void turn(point &a, double b)
{
	point t = a;
	a.x = t.x * cos(b) - t.y * sin(b);
	a.y = t.x * sin(b) - t.y * cos(b);
}
// 判断点是否在直线上
inline bool on_line(point a, segment b)
{
	return cro(make_vec(a, b.l), make_vec(a, b.r)) == 0;
}
// 判断点是否在线段上
inline bool on_segment(point a, segment b)
{
	return dis(a, b.l) + dis(a, b.r) == dis(b.l, b.r);
}
// 海伦公式
inline double heron(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
} // namespace CG
int main()
{
}