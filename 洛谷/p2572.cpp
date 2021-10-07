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
class segment_tree
{
private:
	struct node
	{
		int l, r, len[2], maxlen[2], llen[2], rlen[2];
		int tag1, tag2;
		int c;
		node *ls, *rs;
	} st[300000];
	int top;

public:
	node *rt;
	void update(node *o)
	{
		for (int i = 0; i < 2; ++i)
			o->len[i] = o->ls->len[i] + o->rs->len[i],
			o->maxlen[i] = max(max(o->ls->maxlen[i], o->rs->maxlen[i]), o->ls->rlen[i] + o->rs->llen[i]),
			o->llen[i] = o->ls->len[i ^ 1] ? o->ls->llen[i] : (o->ls->llen[i] + o->rs->llen[i]),
			o->rlen[i] = o->rs->len[i ^ 1] ? o->rs->rlen[i] : (o->rs->rlen[i] + o->ls->rlen[i]);
	}
	void pushdown(node *o)
	{
		if (o->tag1)
		{
			o->tag1 = 0;
			node *t = o->ls;
			int c = o->c;
			if (t)
			{
				t->tag1 = 1;
				t->tag2 = 0;
				t->c = c;
				t->len[c] = t->maxlen[c] = t->llen[c] = t->rlen[c] = t->r - t->l + 1;
				t->len[c ^ 1] = t->maxlen[c ^ 1] = t->llen[c ^ 1] = t->rlen[c ^ 1] = 0;
			}
			t = o->rs;
			if (t)
			{
				t->tag1 = 1;
				t->tag2 = 0;
				t->c = c;
				t->len[c] = t->maxlen[c] = t->llen[c] = t->rlen[c] = t->r - t->l + 1;
				t->len[c ^ 1] = t->maxlen[c ^ 1] = t->llen[c ^ 1] = t->rlen[c ^ 1] = 0;
			}
		}
		if (o->tag2)
		{
			o->tag2 = 0;
			node *t = o->ls;
			if (t)
			{
				t->tag2 ^= 1;
				swap(t->len[0], t->len[1]);
				swap(t->llen[0], t->llen[1]);
				swap(t->rlen[0], t->rlen[1]);
				swap(t->maxlen[0], t->maxlen[1]);
			}
			t = o->rs;
			if (t)
			{
				t->tag2 ^= 1;
				swap(t->len[0], t->len[1]);
				swap(t->llen[0], t->llen[1]);
				swap(t->rlen[0], t->rlen[1]);
				swap(t->maxlen[0], t->maxlen[1]);
			}
		}
	}
	void build(node *&o, int l, int r)
	{
		o = &st[++top];
		o->l = l, o->r = r;
		if (l == r)
		{
			int x;
			read(x);
			o->len[x] = o->maxlen[x] = o->llen[x] = o->rlen[x] = 1;
		}
		else
			build(o->ls, l, l + r >> 1), build(o->rs, (l + r >> 1) + 1, r), update(o);
	}
	void modify1(node *o, int l, int r, int k)
	{
		if (o->l == l && o->r == r)
		{
			o->tag1 = 1;
			o->tag2 = 0;
			o->c = k;
			o->len[k] = o->maxlen[k] = o->llen[k] = o->rlen[k] = r - l + 1;
			o->len[k ^ 1] = o->maxlen[k ^ 1] = o->llen[k ^ 1] = o->rlen[k ^ 1] = 0;
			return;
		}
		pushdown(o);
		int mid = o->l + o->r >> 1;
		if (r <= mid)
			modify1(o->ls, l, r, k);
		else if (l > mid)
			modify1(o->rs, l, r, k);
		else
			modify1(o->ls, l, mid, k), modify1(o->rs, mid + 1, r, k);
		update(o);
	}
	void modify2(node *o, int l, int r)
	{
		if (o->l == l && o->r == r)
		{
			o->tag2 ^= 1;
			swap(o->len[0], o->len[1]);
			swap(o->llen[0], o->llen[1]);
			swap(o->rlen[0], o->rlen[1]);
			swap(o->maxlen[0], o->maxlen[1]);
			return;
		}
		pushdown(o);
		int mid = o->l + o->r >> 1;
		if (r <= mid)
			modify2(o->ls, l, r);
		else if (l > mid)
			modify2(o->rs, l, r);
		else
			modify2(o->ls, l, mid), modify2(o->rs, mid + 1, r);
		update(o);
	}
	int query1(node *o, int l, int r)
	{
		if (o->l == l && o->r == r)
			return o->len[1];
		pushdown(o);
		int mid = o->l + o->r >> 1;
		if (r <= mid)
			return query1(o->ls, l, r);
		else if (l > mid)
			return query1(o->rs, l, r);
		else
			return query1(o->ls, l, mid) + query1(o->rs, mid + 1, r);
	}
	int query2(node *o, int l, int r)
	{
		if (o->l == l && o->r == r)
			return o->maxlen[1];
		pushdown(o);
		int mid = o->l + o->r >> 1;
		if (r <= mid)
			return query2(o->ls, l, r);
		else if (l > mid)
			return query2(o->rs, l, r);
		else
			return max(max(query2(o->ls, l, mid), query2(o->rs, mid + 1, r)), min(mid - l + 1, o->ls->rlen[1]) + min(r - mid, o->rs->llen[1]));
	}
	void travel(node *o)
	{
		pushdown(o);
		if (o->l == o->r)
			cerr << o->len[1] << " ";
		else
			travel(o->ls), travel(o->rs);
	}
} st;
int main()
{
	freopen("data.in", "r", stdin);
	int n, m;
	read(n, m);
	st.build(st.rt, 1, n);
	// cerr << endl;
	// st.travel(st.rt);
	// cerr << endl;
	for (int i = 1; i <= m; ++i)
	{
		int op, a, b;
		read(op, a, b);
		++a, ++b;
		if (op <= 1)
			st.modify1(st.rt, a, b, op);
		else if (op == 2)
			st.modify2(st.rt, a, b);
		else if (op == 3)
			print(st.query1(st.rt, a, b));
		else
			print(st.query2(st.rt, a, b));
		// st.travel(st.rt);
		// cerr << endl;
	}
	return 0;
}