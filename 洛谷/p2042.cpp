#include <cctype>
#include <cstdio>
#include <iostream>
#define il inline
#define re register
#define LL long long
#define gc getchar
using namespace std;
template <typename T>
void rd(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
    rd(s);
    rd(args...);
}
const int MAXN = 1000000;
int fre[MAXN];
int cnt, top;
int rt;
int son[MAXN][2], fa[MAXN], sze[MAXN], val[MAXN], tag1[MAXN], tag2[MAXN];
LL sum[MAXN], maxsum[MAXN], maxl[MAXN], maxr[MAXN];
#define ls son[o][0]
#define rs son[o][1]
void update(int o)
{
    sze[o] = sze[ls] + sze[rs] + 1;
    sum[o] = sum[ls] + sum[rs] + val[o];
    maxsum[o] = max(maxr[ls] + val[o] + maxl[rs], max(maxsum[ls], maxsum[rs]));
    maxl[o] = max(maxl[ls], maxl[rs] + sum[ls] + val[o]);
    maxr[o] = max(maxr[rs], maxr[ls] + sum[rs] + val[o]);
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
    update(y);
    update(x);
}
void splay(int x, int &k)
{
    int y, z;
    while (x != k)
    {
        y = fa[x], z = fa[y];
        if (y != k)
            rotate(son[z][1] == y ^ son[y][1] == x ? x : y, k);
        rotate(x, k);
    }
}
void push_down(int o)
{
    if (tag1[o])
    {
        int c = val[o];
        if (ls)
        {
            val[ls] = c;
            sum[ls] = c * 1ll * sze[ls];
            tag1[ls] = 1;
            tag2[ls] = 0;
            maxl[ls] = maxr[ls] = c > 0 ? sum[ls] : 0;
            maxsum[ls] = c > 0 ? sum[ls] : c;
        }
        if (rs)
        {
            val[rs] = c;
            sum[rs] = c * 1ll * sze[rs];
            tag1[rs] = 1;
            tag2[rs] = 0;
            maxl[rs] = maxr[rs] = c > 0 ? sum[rs] : 0;
            maxsum[rs] = c > 0 ? sum[rs] : c;
        }
        tag1[o] = 0;
    }
    if (tag2[o])
    {
        if (ls)
        {
            tag2[ls] ^= 1;
            swap(son[ls][0], son[ls][1]);
            swap(maxl[ls], maxr[ls]);
        }
        if (rs)
        {
            tag2[rs] ^= 1;
            swap(son[rs][1], son[rs][0]);
            swap(maxl[rs], maxr[rs]);
        }
        tag2[o] ^= 1;
    }
}
int new_node()
{
    return top ? fre[top--] : ++cnt;
}
int a[MAXN];
void build(int &o, int f, int l, int r)
{
    if (l > r)
        return;
    int m = (l + r) >> 1;
    o = new_node();
    val[o] = a[m];
    fa[o] = f;
    tag1[o] = tag2[o] = 0;
    son[o][0] = son[o][1] = 0;
    if (l != r)
    {
        build(son[o][0], o, l, m - 1), build(son[o][1], o, m + 1, r);
        update(o);
    }
    else
    {
        sze[o] = 1;
        sum[o] = maxsum[o] = val[o];
        maxl[o] = maxr[o] = val[o] > 0 ? val[o] : 0;
    }
}
int find(int k)
{
    int o = rt;
    push_down(o);
    while (sze[son[o][0]] + 1 != k)
    {
        (sze[son[o][0]] + 1 < k) ? (k -= (sze[son[o][0]] + 1), o = son[o][1]) : o = son[o][0];
        push_down(o);
    }
    return o;
}
int split(int pos, int tot)
{
    // cout << 1 << endl;
    int l = find(pos), r = find(pos + tot + 1);
    // cout << 2 << endl;
    splay(l, rt);
    splay(r, son[l][1]);
    // cout << 3 << endl;
    return son[r][0];
}
void insert(int pos, int tot)
{
    int l = find(pos + 1), r = find(pos + 2);
    splay(l, rt);
    splay(r, son[l][1]);
    build(son[r][0], r, 1, tot);
    update(r);
    update(l);
}
void del(int o)
{
    if (!o)
        return;
    del(son[o][0]);
    del(son[o][1]);
    son[o][0] = son[o][1] = 0;
    fa[o] = 0;
    fre[++top] = o;
}
void del(int pos, int tot)
{
    int o = split(pos, tot);
    son[fa[o]][0] = 0;
    del(o);
    update(son[rt][1]);
    update(rt);
}
void modify(int pos, int tot, int c)
{
    int o = split(pos, tot);
    tag1[o] = 1;
    val[o] = c;
    sum[o] = c * 1ll * sze[o];
    maxsum[o] = c > 0 ? sum[o] : c;
    maxl[o] = maxr[o] = c > 0 ? sum[o] : 0;
    update(son[rt][1]);
    update(rt);
}
void reverse(int pos, int tot)
{
    int o = split(pos, tot);
    tag2[o] ^= 1;
    swap(son[o][0], son[o][1]);
    swap(maxl[o], maxr[o]);
    update(son[rt][1]);
    update(rt);
}
LL get_sum(int pos, int tot)
{
    int o = split(pos, tot);
    return sum[o];
}
LL max_sum()
{
    return maxsum[rt];
}
const int INF = -0x3f3fffff;
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
void dfs(int o)
{
    if (!o)
        return;
    push_down(o);
    dfs(son[o][0]);
    cout << val[o] << " ";
    dfs(son[o][1]);
}
int main()
{
    int n, m, pos, tot, c;
    rd(n, m);
    for (int i = 2; i <= n + 1; ++i)
        rd(a[i]);
    a[1] = a[n + 2] = INF;
    maxsum[0] = INF;
    build(rt, 0, 1, n + 2);
    for (int i = 1; i <= m; ++i)
    {
        // dfs(rt);
        // cout << endl;
        int opt = get_opt();
        if (opt == 6)
            printf("%lld\n", max_sum());
        else
        {
            rd(pos, tot);
            if (opt == 1)
            {
                for (int j = 1; j <= tot; ++j)
                    rd(a[j]);
                insert(pos, tot);
            }
            else if (opt == 2)
                del(pos, tot);
            else if (opt == 4)
                reverse(pos, tot);
            else if (opt == 5)
                printf("%lld\n", get_sum(pos, tot));
            else
            {
                rd(c);
                modify(pos, tot, c);
            }
        }
    }
    return 0;
}