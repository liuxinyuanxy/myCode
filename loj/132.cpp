#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define il inline
#define re register
#define gc getchar
#define LL long long
#define int LL
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
const int MAXN = 2000000;
int del1[MAXN], del2[MAXN];
int sum[MAXN];
int n;
#define lowbit(x) ((x) & -(x))
void add(int pos, int x, int *tree)
{
    while (pos <= n)
        tree[pos] += x, pos += lowbit(pos);
}
int que(int pos, int *tree)
{
    int ans = 0;
    while (pos)
        ans += tree[pos], pos -= lowbit(pos);
    return ans;
}
void modify(int l, int r, int x)
{
    add(l, x, del1), add(r + 1, -x, del1);
    add(l, l * x, del2), add(r + 1, -(r + 1) * x, del2);
}
int query_(int r)
{
    return sum[r] + (r + 1) * que(r, del1) - que(r, del2);
}
int query(int l, int r)
{
    return query_(r) - query_(l - 1);
}
signed main()
{
    int q;
    read(n), read(q);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        read(x);
        sum[i] = sum[i - 1] + x;
    }
    for (int i = 1; i <= q; ++i)
    {
        int op, l, r, x;
        read(op), read(l), read(r);
        if (op == 1)
            read(x), modify(l, r, x);
        else
            printf("%lld\n", query(l, r));
    }
    return 0;
}