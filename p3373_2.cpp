#include <iostream>
#include <cstdio>
#define lc (i << 1)
#define rc (i << 1 | 1)
#define root (i >> 1)
using namespace std;
typedef long long ll;
ll p;
ll ans = 0;
struct node
{
    int left, right;
    ll val, p1, p2;
}tree[400005];
inline void updata(int i)
{
    tree[i].val = (tree[lc].val + tree[rc].val) % p;
}
void downdata(int i)
{
    int c = (tree[i].right - tree[i].left) + 1;
    tree[i].p1 = (tree[i].p1 * tree[root].p1) % p;
    tree[i].p2 = (tree[i].p2 * tree[root].p1) % p;
    tree[i].p2 = (tree[i].p2 + tree[root].p2) % p;
    tree[i].val = (tree[i].val * tree[root].p1) % p;
    tree[i].val = (tree[i].val + tree[root].p2 * c) % p;
}
void build(int i, int l, int r)
{
    tree[i].left = l,
    tree[i].right = r,
    tree[i].val = tree[i].p2 = 0,
    tree[i].p1 = 1;
    if (l == r)
    {
        scanf("%lld", &tree[i].val);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid),
    build(rc, mid + 1, r);
    updata(i);
}
void add(int t, int l, int r, ll k, int i)
{
    int c = (r - l) + 1;
    if (tree[i].left == l && tree[i].right == r)
    {
        if (t == 1)
        {
            tree[i].p1 = (tree[i].p1 * k) % p;
            tree[i].p2 = (tree[i].p2 * k) % p;
            tree[i].val = (tree[i].val * k) % p;
        }
        if (t == 2)
        {
            tree[i].p2 = (tree[i].p2 + k) % p;
            tree[i].val = (tree[i].val + k * c) % p;
        }
        return;
    }
    downdata(lc),
    downdata(rc);
    tree[i].p1 = 1;
    tree[i].p2 = 0;
    int mid = (tree[i].left + tree[i].right) >> 1;
    if (mid >= r)
        add(t, l, r, k, lc);
    else
        if (mid < l)
            add(t, l, r, k, rc);
        else
            add(t, l, mid, k, lc),
            add(t, mid + 1, r, k, rc);
    updata(i);
}
void query(int l, int r, int i)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        ans += tree[i].val;
        ans %= p;
        return;
    }
    downdata(lc),
    downdata(rc);
    tree[i].p1 = 1;
    tree[i].p2 = 0;
    int mid = (tree[i].left + tree[i].right) >> 1;
    if (mid >= r)
        query(l, r, lc);
    else
        if (mid < l)
            query(l, r, rc);
        else
            query(l, mid, lc),
            query(mid + 1, r, rc);
    updata(i);

}
int main()
{
    int n, m;
    int x, y, temp;
    ll k;
    scanf("%d%d%lld", &n, &m, &p);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &temp, &x, &y);
        if (temp < 3)
        {
            scanf("%lld", &k);
            add(temp, x, y, k, 1);
        }
        else
        {
            ans = 0;
            query(x, y, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
