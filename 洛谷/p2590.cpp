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
int n;
int cnt;
int head[MAXN], nxt[MAXN], to[MAXN], val[MAXN];
int id[MAXN], pos[MAXN], tot;
class segment_tree
{
private:
	struct node
	{
		int sum, l, r, lc, rc, tag;
		node *ls, *rs;
	} sta[MAXN];
	int cnt;
	il void update(node *o)
	{
		o->sum = o->ls->sum + o->rs->sum - int(o->ls->rc == o->rs->lc);
		o->lc = o->ls->lc;
		o->rc = o->rs->rc;
	}
	il void pushdown(node *o)
	{
		if (o->tag)
		{
			o->tag = 0;
			int c = o->lc;
			node *t = o->ls;
			if (t)
			{
				t->tag = t->sum = 1;
				t->lc = t->rc = c;
			}
			t = o->rs;
			if (t)
			{
				t->tag = t->sum = 1;
				t->lc = t->rc = c;
			}
		}
	}

public:
	int maxlid, maxrid, maxlc, maxrc;
	node *rt;
	void build(node *&o, int l, int r)
	{
		o = &sta[++cnt];
		o->l = l, o->r = r;
		if (l == r)
			o->ls = o->rs = nullptr, o->lc = o->rc = val[id[l]], o->sum = 1;
		else
			build(o->ls, l, (l + r) >> 1), build(o->rs, ((l + r) >> 1) + 1, r), update(o);
	}
	void modify(node *o, int l, int r, int c)
	{
		if (o->l == l && o->r == r)
		{
			o->sum = o->tag = 1;
			o->lc = o->rc = c;
			return;
		}
		pushdown(o);
		int mid = o->l + o->r >> 1;
		if (r <= mid)
			modify(o->ls, l, r, c);
		else if (l > mid)
			modify(o->rs, l, r, c);
		else
			modify(o->ls, l, mid, c), modify(o->rs, mid + 1, r, c);
		update(o);
	}
	il void upt(node *o)
	{
		if (o->l < maxlid)
			maxlid = o->l, maxlc = o->lc;
		if (o->r > maxrid)
			maxrid = o->r, maxrc = o->rc;
	}
	int query(node *o, int l, int r)
	{
		if (o->l == l && o->r == r)
			return upt(o), o->sum;
		pushdown(o);
		int mid = o->l + o->r >> 1;
		if (r <= mid)
			return query(o->ls, l, r);
		else if (l > mid)
			return query(o->rs, l, r);
		else
			return query(o->ls, l, mid) + query(o->rs, mid + 1, r) - int(o->ls->rc == o->rs->lc);
	}
} st;
class HLD
{
private:
	int top[MAXN], fa[MAXN], sze[MAXN], son[MAXN];
	int dis[MAXN];
	void dfs1(int u)
	{
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
		top[u] = t;
		pos[u] = ++tot;
		id[tot] = u;
		if (son[u])
			dfs2(son[u], t);
		for (int i = head[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (v != fa[u] && v != son[u])
				dfs2(v, v);
	}
	void modify(int u, int v, int c)
	{
		while (top[u] != top[v])
		{
			if (dis[top[u]] < dis[top[v]])
				swap(u, v);
			st.modify(st.rt, pos[top[u]], pos[u], c);
			u = fa[top[u]];
		}
		if (dis[u] > dis[v])
			swap(u, v);
		st.modify(st.rt, pos[u], pos[v], c);
	}
	int query(int u, int v)
	{
		int ans = 0, utopc = 0, vtopc = 0;
		while (top[u] != top[v])
		{
			if (dis[top[u]] < dis[top[v]])
				swap(u, v), swap(utopc, vtopc);
			st.maxlid = 0x3fffffff, st.maxrid = (int)0x80000000;
			ans += st.query(st.rt, pos[top[u]], pos[u]) - int(utopc == st.maxrc);
			utopc = st.maxlc;
			u = fa[top[u]];
		}
		if (dis[u] > dis[v])
			swap(u, v), swap(utopc, vtopc);
		st.maxlid = 0x3fffffff, st.maxrid = (int)0x80000000;
		ans += st.query(st.rt, pos[u], pos[v]) - int(vtopc == st.maxrc) - int(utopc == st.maxlc);
		return ans;
	}

public:
	char ch[1000];
	void init()
	{
		dfs1(1);
		dfs2(1, 1);
		st.build(st.rt, 1, n);
	}
	void operate()
	{
		int u, v, w;
		gstr(ch);
		read(u, v);
		if (ch[0] == 'C')
			read(w), modify(u, v, w);
		else
			print(query(u, v));
	}
} hld;
void ins(int u, int v)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}
int main()
{
	read(n);
	int q;
	read(q);
	int u, v;
	for (int i = 1; i <= n; ++i)
		read(val[i]);
	for (int i = 1; i < n; ++i)
	{
		read(u, v);
		ins(u, v), ins(v, u);
	}
	hld.init();
	for (int i = 1; i <= q; ++i)
		hld.operate();
	return 0;
}