#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#define il inilne
#define re register
#define gc getchar
#define file "xor"
#ifdef DEBUG
#define F()
#else
#define F()                          \
    freopen(file ".in", "r", stdin); \
    freopen(file ".out", "w", stdout);
#endif
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
    s *= p ? -1 : 1;
}
const int N = 32;
struct node
{
    int a[N], sze;
    void insert(int x)
    {
        for (int i = 30; i >= 0; --i)
            if (x & (1 << i))
            {
                if (a[i])
                    x ^= a[i];
                else
                {
                    for (int j = i - 1; j >= 0; --j)
                        if (x & (1 << j))
                            x ^= a[j];
                    for (int j = 30; j > i; --j)
                        if (a[j] & (1 << i))
                            a[j] ^= x;
                    a[i] = x;
                    ++sze;
                    return;
                }
            }
    }
    void insert(node x)
    {
        for (int i = 30; i >= 0; --i)
            if (x.a[i])
                insert(x.a[i]);
    }
    int l, r;
    node *ls, *rs;
} sta[300000];
int top;
node *rt;
#define new_node() (&sta[++top])
#define mid ((o->l + o->r) >> 1)
void build(int l, int r, node *&o)
{
    o = new_node();
    o->l = l, o->r = r;
    if (l != r)
        build(l, mid, o->ls), build(mid + 1, r, o->rs);
}
void modify(int l, int r, int x, node *o)
{
    if (o->l == l && o->r == r)
        o->insert(x);
    else
    {
        if (r <= mid)
            modify(l, r, x, o->ls);
        else if (l > mid)
            modify(l, r, x, o->rs);
        else
            modify(l, mid, x, o->ls), modify(mid + 1, r, x, o->rs);
    }
}
void push_down(node *o)
{
    if (o->l != o->r)
    {
        o->ls->insert(*o);
        o->rs->insert(*o);
        push_down(o->ls);
        push_down(o->rs);
    }
    else
    {
        printf("%lld\n", 1ll << o->sze);
    }
}
map<int, int> M;
int main()
{
    F();
    int m, q;
    read(m);
    read(q);
    build(1, q, rt);
    for (int i = 1; i <= q; ++i)
    {
        int opt, x;
        read(opt), read(x);
        if (opt == 1)
            M.insert(make_pair(x, i));
        else
        {
            auto it = M.find(x);
            modify(it->second, i - 1, x, rt);
            M.erase(it);
        }
    }
    for (auto x : M)
        modify(x.second, q, x.first, rt);
    push_down(rt);
}