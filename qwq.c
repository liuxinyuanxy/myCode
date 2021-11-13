#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define gc getchar
#define read(x) scanf("%d", &x)
#define MAXN 5000000
int fa[MAXN], son[MAXN][2], sze[MAXN], val[MAXN], a[MAXN];
int tag1[MAXN], tag2[MAXN];
int sum[MAXN], maxl[MAXN], maxr[MAXN], maxsum[MAXN];
int fre[MAXN], cnt = 0, top = 0;
int rt;
int max(int a, int b)
{
    return a > b ? a : b;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int new_node()
{
    return top ? fre[top--] : ++cnt;
}
#define mid(l, r) (((l) + (r)) >> 1)
#define ls(o) (son[o][0])
#define rs(o) (son[o][1])
void updata(int o)
{
    sum[o] = sum[ls(o)] + sum[rs(o)] + val[o];
    sze[o] = sze[ls(o)] + sze[rs(o)] + 1;
    maxl[o] = max(maxl[ls(o)], sum[ls(o)] + val[o] + maxl[rs(o)]);
    maxr[o] = max(maxr[rs(o)], sum[rs(o)] + val[o] + maxr[ls(o)]);
    maxsum[o] = max(max(maxsum[ls(o)], maxsum[rs(o)]), maxr[ls(o)] + val[o] + maxl[rs(o)]);
}
void push_down(int o)
{
    int v;
    if (tag1[o])
    {
        int c = val[o];
        if ((v = ls(o)))
        {
            tag1[v] = 1;
            tag2[v] = 0;
            val[v] = c;
            sum[v] = c * sze[v];
            maxl[v] = maxr[v] = (c > 0 ? sum[v] : 0);
            maxsum[v] = (c > 0 ? sum[v] : c);
        }
        if ((v = rs(o)))
        {
            tag1[v] = 1;
            tag2[v] = 0;
            val[v] = c;
            sum[v] = c * sze[v];
            maxl[v] = maxr[v] = (c > 0 ? sum[v] : 0);
            maxsum[v] = (c > 0 ? sum[v] : c);
        }
        tag1[o] = 0;
    }
    if (tag2[o])
    {
        if ((v = ls(o)))
        {
            tag2[v] ^= 1;
            swap(&ls(v), &rs(v));
            swap(&maxl[v], &maxr[v]);
        }
        if ((v = rs(o)))
        {
            tag2[v] ^= 1;
            swap(&ls(v), &rs(v));
            swap(&maxl[v], &maxr[v]);
        }
        tag2[o] = 0;
    }
}
void rotate(int x, int *k)
{
    int y = fa[x], z = fa[y];
    int p = rs(y) == x;
    if (y == *k)
        *k = x;
    else
        son[z][rs(z) == y] = x;
    fa[x] = z;
    fa[y] = x;
    fa[son[x][p ^ 1]] = y;
    son[y][p] = son[x][p ^ 1];
    son[x][p ^ 1] = y;
    updata(y);
    updata(x);
}
void splay(int x, int *k)
{
    int y, z;
    while (x != *k)
    {
        y = fa[x], z = fa[y];
        if (y != *k)
            rotate(ls(z) == y ^ ls(y) == x ? x : y, k);
        rotate(x, k);
    }
}
void init(int o)
{
    fa[o] = son[o][0] = son[o][1] = tag1[o] = tag2[o] = sum[o] = maxl[o] = maxr[o] = maxsum[o] = 0;
}
void build(int *O, int l, int r, int *a, int f)
{
    if (l > r)
        return;
    int o = new_node();
    *O = o;
    int m = mid(l, r);
    init(o);
    fa[o] = f;
    val[o] = a[m];
    sze[o] = r - l + 1;
    if (l == r)
    {
        sum[o] = maxsum[o] = val[o];
        maxl[o] = maxr[o] = max(val[o], 0);
        return;
    }
    build(&ls(o), l, m - 1, a, o);
    build(&rs(o), m + 1, r, a, o);
    updata(o);
}
int find(int k)
{
    int o = rt;
    while (1)
    {
        push_down(o);
        if (sze[ls(o)] + 1 == k)
            return o;
        if (sze[ls(o)] + 1 > k)
            o = ls(o);
        else
            k -= (sze[ls(o)] + 1), o = rs(o);
    }
}
int split(int pos, int tot)
{
    int l = find(pos), r = find(pos + tot + 1);
    splay(l, &rt);
    splay(r, &rs(l));
    return ls(r);
}
void insert(int pos, int tot, int *a)
{
    int l = find(pos + 1), r = find(pos + 2);
    splay(l, &rt);
    splay(r, &rs(l));
    build(&ls(r), 1, tot, a, r);
    updata(r);
    updata(l);
}
void dfs_del(int o)
{
    if (!o)
        return;
    fre[++top] = o;
    dfs_del(ls(o));
    dfs_del(rs(o));
}
void del(int pos, int tot)
{
    int o = split(pos, tot);
    dfs_del(o);
    ls(fa[o]) = 0;
    updata(fa[o]);
    updata(rt);
}
void modify(int pos, int tot, int c)
{
    int o = split(pos, tot);
    val[o] = c;
    sum[o] = c * sze[o];
    if (c > 0)
        maxsum[o] = maxl[o] = maxr[o] = sum[o];
    else
        maxsum[o] = c, maxl[o] = maxr[o] = 0;
    tag1[o] = 1;
    tag2[o] = 0;
    updata(fa[o]);
    updata(rt);
}
void reverse(int pos, int tot)
{
    int o = split(pos, tot);
    tag2[o] ^= 1;
    swap(&maxl[o], &maxr[o]);
    swap(&ls(o), &rs(o));
    updata(fa[o]);
    updata(rt);
}
int get_sum(int pos, int tot)
{
    int o = split(pos, tot);
    return sum[o];
}
int max_sum()
{
    return maxsum[rt];
}
void finish()
{
    char ch;
    while (ch = getchar(), !isspace(ch))
        ;
}
int get_opt()
{
    char ch;
    while (ch = getchar(), !isalpha(ch))
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
int main()
{
    int n, m, pos, tot, c;
    read(n);
    read(m);
    for (int i = 2; i <= n + 1; ++i)
        read(a[i]);
    a[1] = a[n + 2] = maxsum[0] = -0x3f3fffff;
    build(&rt, 1, n + 2, a, 0);
    for (int i = 1; i <= m; ++i)
    {
        int opt = get_opt();
        if (opt == 6)
            printf("%d\n", max_sum());
        else
        {
            read(pos);
            read(tot);
            if (opt == 1)
            {
                for (int j = 1; j <= tot; ++j)
                    read(a[j]);
                insert(pos, tot, a);
            }
            else if (opt == 2)
                del(pos, tot);
            else if (opt == 4)
                reverse(pos, tot);
            else if (opt == 5)
                printf("%d\n", get_sum(pos, tot));
            else
            {
                read(c);
                modify(pos, tot, c);
            }
        }
    }
}