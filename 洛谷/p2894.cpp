#include <cstdio>
#include <cstring>
#include <iostream>
#define il inline
using namespace std;
#ifdef DEBUG
#define Gc() getchar()
#define D() cerr << __LINE__ << endl;
#else
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define D()
#endif

namespace io
{
const int __SIZE = (1 << 21) + 1;
char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55];
int __f, qr, _eof, _sze;
inline void flush()
{
	fwrite(obuf, 1, oS - obuf, stdout), oS = obuf;
}
inline void gc(char &x) { x = Gc(); }
inline void pc(char x)
{
	*oS++ = x;
	if (oS == oT)
		flush();
}
inline void pstr(const char *s)
{
	int __len = strlen(s);
	for (__f = 0; __f < __len; ++__f)
		pc(s[__f]);
}
inline void gstr(char *s)
{
	for (__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)
		__c = Gc();
	for (; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc())
		*s = __c;
	*s = 0;
}
template <class I>
inline bool read(I &x)
{
	_eof = 0;
	for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc())
	{
		if (__c == '-')
			__f = -1;
		_eof |= __c == EOF;
	}
	for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc())
		x = x * 10 + (__c & 15), _eof |= __c == EOF;
	x *= __f;
	return !_eof;
}
template <class I, class... Args>
inline int read(I &x, Args &... args)
{
	return read(x) + read(args...);
}
template <class I>
inline void print(I x)
{
	if (!x)
		pc('0');
	if (x < 0)
		pc('-'), x = -x;
	while (x)
		qu[++qr] = x % 10 + '0', x /= 10;
	while (qr)
		pc(qu[qr--]);
	pc('\n');
}
struct Flusher_
{
	~Flusher_() { flush(); }
} io_flusher_;
} // namespace io
using io::gc;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;
using io::read;
const int MAXN = 1000000;
int cnt;
int belong[MAXN], val[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN];
int id[MAXN], pos[MAXN], tot;
int sze[MAXN], son[MAXN], top[MAXN], dis[MAXN], fa[MAXN];
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
void dfs1(int u)
{
	D();
	sze[u] = 1;
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u])
		{
			fa[v] = u;
			dis[v] = dis[u] + 1;
			dfs1(v);
			if (sze[v] > sze[son[u]])
				son[u] = v;
			sze[u] += sze[v];
		}
}
void dfs2(int u, int t)
{
	D();
	pos[u] = ++tot;
	id[tot] = u;
	top[u] = t;
	if (son[u])
		dfs2(son[u], t);
	for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}
class Splay
{
private:
	int son[MAXN][2], fa[MAXN], val1[MAXN], val2[MAXN], rk[MAXN];
	int fre[MAXN], top, cnt;
	void update(int o)
	{
		D();
		val1[o] = val1[son[o][0]] + val1[son[o][1]];
		val2[o] = max(val2[son[o][0]], val2[son[o][1]]);
		D();
	}
	void rotate(int x, int &k)
	{
		D();
		int y = fa[x], z = fa[y];
		int l = son[y][1] == x, r = l ^ 1;
		if (y == k)
			k = x;
		else
			son[z][son[z][1] == y] = x;
		fa[x] = z;
		fa[son[x][r]] = y;
		son[y][l] = son[x][r];
		son[x][r] = y;
		fa[y] = x;
		update(y), update(x);
		D();
	}
	void splay(int x, int &k)
	{
		D();
		int y, z;
		while (x != k)
		{
			y = fa[x], z = fa[y];
			if (z != k)
				rotate(((son[z][1] == y ^ son[y][1] == x) ? x : y), k);
			rotate(x, k);
		}
		D();
	}
	int findl(int o, int x)
	{
		D();
		int ans = 0;
		while (o)
			x >= rk[o] ? (ans = o, o = son[o][0]) : o = son[o][1];
		D();
		return ans;
	}
	int findr(int o, int x)
	{
		D();
		int ans = 0;
		while (o)
			x <= rk[o] ? (ans = o, o = son[o][1]) : o = son[o][0];
		D();
		return ans;
	}
	int split(int &o, int l, int r)
	{
		D();
		int x = findl(o, l), y = findr(o, r);
		splay(x, o), splay(y, son[o][1]);
		D();
		return son[y][0];
	}
	int findleft(int o)
	{
		D();
		while (son[o][0])
			o = son[o][0];
		D();
		return o;
	}
	int merge(int l, int r)
	{
		D();
		if (!l || !r)
			return l + r;
		splay(findleft(r), r);
		fa[l] = r;
		son[r][0] = l;
		update(r);
		D();
		return r;
	}
#define new_node() (top ? fre[top--] : ++cnt)
public:
	int rt[MAXN];
	void insert(int &o, int x, int f)
	{
		D();
		if (!o)
			o = new_node(), val1[o] = val2[o] = val[id[x]], rk[o] = x, son[o][0] = son[o][1] = 0, fa[o] = f, splay(o, rt[belong[id[x]]]);
		else
			insert(x < rk[o] ? son[o][0] : son[o][1], x, o);
	}
	void del(int &o, int x)
	{
		D();
		splay(findl(o, x), o);
		fa[son[o][0]] = fa[son[o][1]] = 1;
		fre[++top] = o;
		o = merge(son[o][0], son[o][1]);
		D();
	}
	il int query1(int &o, int l, int r)
	{
		D();
		int x = split(o, l, r);
		D();
		return val1[x];
	}
	il int query2(int &o, int l, int r)
	{
		D();
		int x = split(o, l, r);
		D();
		return val2[x];
	}
} splay;
char ch[2000];
int query1(int u, int v)
{
	D();
	int ans = 0;
	int x = belong[u];
	while (top[u] != top[v])
	{
		if (dis[top[u]] < dis[top[v]])
			swap(u, v);
		ans += splay.query1(splay.rt[x], pos[top[u]], pos[u]);
		u = fa[top[u]];
	}
	if (dis[u] > dis[v])
		swap(u, v);
	ans += splay.query2(splay.rt[x], pos[v], pos[u]);
	D();
	return ans;
}
int query2(int u, int v)
{
	D();
	int ans = 0;
	int x = belong[u];
	while (top[u] != top[v])
	{
		if (dis[top[u]] < dis[top[v]])
			swap(u, v);
		ans = max(ans, splay.query2(splay.rt[x], pos[top[u]], pos[u]));
		u = fa[top[u]];
	}
	if (dis[u] > dis[v])
		swap(u, v);
	ans = max(ans, splay.query2(splay.rt[x], pos[v], pos[u]));
	D();
	return ans;
}
int main()
{
	D();
	int n, q;
	read(n, q);
	for (int i = 1; i <= n; ++i)
		read(belong[i], val[i]);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		read(u, v);
		ins(u, v), ins(v, u);
	}
	D();
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i <= n; ++i)
		splay.insert(splay.rt[belong[i]], pos[i], 0);
	for (int i = 1; i <= q; ++i)
	{
		D();
		int x, y;
		gstr(ch);
		read(x, y);
		if (ch[0] == 'C')
			if (ch[1] == 'C')
				splay.del(splay.rt[belong[x]], pos[x]), belong[x] = y, splay.insert(splay.rt[y], pos[x], 0);
			else
				splay.del(splay.rt[belong[x]], pos[x]), val[x] = y, splay.insert(splay.rt[belong[x]], pos[x], 0);
		else if (ch[1] == 'S')
			print(query1(x, y));
		else
			print(query2(x, y));
		D();
	}
	return 0;
}