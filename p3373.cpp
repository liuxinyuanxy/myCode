#include <iostream>
#include <cstdio>
#define lc (i << 1)
#define rc (i << 1 | 1)
using namespace std;
typedef long long ll;
ll p;
struct node
{
    ll left, right, val, p1, p2;
}tree[400010];
ll ans = 0;
void updata(ll i)
{
    ll l = lc, r = rc;
    tree[i].val = (tree[l].val + tree[r].val) % p;
    return;
}
void build(ll l, ll r, ll i)
{
    tree[i].left = l,
    tree[i].right = r;
    tree[i].p1 = 1,
    tree[i].p2 = tree[i].val = 0;
    if (l == r)
    {
        scanf("%lld", &tree[i].val);
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, lc);
    build(mid + 1, r, rc);
    updata(i);
}
void downdata(ll i, ll c)
{
    ll l = lc, r = rc;
    if (tree[i].p1)
        tree[l].p1 = (tree[l].p1 * tree[i].p1) % p,
        tree[r].p1 = (tree[r].p1 * tree[i].p1) % p,
        tree[l].p2 = (tree[l].p2 * tree[i].p1) % p,
        tree[r].p2 = (tree[r].p2 * tree[i].p1) % p,
        tree[l].val = (tree[l].val * tree[i].p1) % p,
        tree[r].val = (tree[r].val * tree[i].p1) % p,
        tree[i].p1 = 1;
    if (tree[i].p2)
        tree[l].p2 += tree[i].p2,
        tree[r].p2 += tree[i].p2,
        tree[l].val = (tree[l].val + tree[i].p2 * (c - (c >> 1))) % p,
        tree[r].val = (tree[r].val + tree[i].p2 * (c >> 1)) % p,
        tree[i].p2 = 0;
    return;
}
void add(ll t, ll l, ll r, ll k, ll i)
{
    ll c = r - l + 1;
    if (tree[i].left == l && tree[i].right == r)
    {
        if (t == 1)
        {
            tree[i].p1 = tree[i].p1 * k % p,
            tree[i].p2 = tree[i].p2 * k % p,
            tree[i].val = tree[i].val * k % p;
        }
        else
        {
            tree[i].p2 = (tree[i].p2 + k) % p;
            tree[i].val = (tree[i].val + k * c) % p;
        }
        return;
    }
    downdata(i, c);
    ll mid = (tree[i].left + tree[i].right) >> 1;
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
void query(ll l, ll r, ll i)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        ans = (ans + tree[i].val) % p;
        return;
    }
    downdata(i, tree[i].right - tree[i].left + 1);
    ll mid = (tree[i].left + tree[i].right) >> 1;
    if (mid >= r)
        query(l, r, lc);
    else
        if (mid < l)
            query(l, r, rc);
        else
            query(l, mid, lc),
            query(mid + 1, r, rc);
}
int main()
{
    ll n, m;
    ll temp, x, y, k;
    scanf("%lld%lld%lld", &n, &m, &p);
    build(1, n, 1);
    for (ll i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &temp, &x, &y);
        if (temp == 3)
        {
            ans = 0;
            query(x, y, 1);
            printf("%lld\n", ans);
        }
        else
        {
            scanf("%lld", &k);
            add(temp, x, y, k, 1);
        }
    }
    return 0;
}
