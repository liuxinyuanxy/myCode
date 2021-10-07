#include <iostream>
#include <cstdio>
#include <algorithm>
#define mid ((l + r) >> 1)
#define mid2 ((tree[i].left + tree[i].right) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
#define N 500005
#define M 200005
#define MAX 1000005
using namespace std;
struct node
{
    int left, right;
    int val;
}tree[N << 4];
struct que
{
    int l, r, num, ans;
}q[M];
int f[N], a[N];
int lst[MAX];
void updata(int i)
{
    tree[i].val = tree[ls].val + tree[rs].val;
    if (i == 1)
        return;
    updata(i >> 1);
}
void build(int i, int l, int r)
{
    tree[i].left = l,
    tree[i].right = r,
    tree[i].val = 1;
    if (l == r)
    {
        f[l] = i;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tree[i].val = tree[ls].val + tree[rs].val;
}
int query(int i, int l, int r)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        return tree[i].val;
    }
    if (mid2 >= r)
        return query(ls, l, r);
    else
        if (mid2 < l)
            return query(rs, l, r);
        else
            return query(ls, l, mid2) + query(rs, mid2 + 1, r);
}
bool cmp1(que a, que b)
{
    return a.r < b.r;
}
bool cmp2(que a, que b)
{
    return a.num < b.num;
}
int main()
{
    int n, m;
    scanf("%d", &n);
    build(1, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].num = i;
    }
    sort(q + 1, q + m + 1, cmp1);
    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (lst[a[i]])
        {
            int last = lst[a[i]];
            tree[f[last]].val = 0;
            updata(f[last]);
        }
        lst[a[i]] = i;
        while (q[j].r == i)
        {
            q[j].ans = query(1, q[j].l, q[j].r);
            ++j;
        }
    }
    sort(q + 1, q + 1 + m, cmp2);
    for (int i = 1; i <= m; ++i)
    {
        printf("%d\n", q[i].ans);
    }
    return 0;
}
