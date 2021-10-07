#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
struct node{
    int left, right;
    ll num, add;
}tree[400050];
ll ans = 0;
inline void updata(int i)
{
    tree[i].num = tree[i << 1].num + tree[i << 1 | 1].num;
}
inline void downdata(int i, ll c)
{
    if (tree[i].add)
    {
        tree[i << 1].add += tree[i].add;
        tree[i << 1 | 1].add += tree[i].add;
        tree[i << 1].num += tree[i].add *(c - (c >> 1));
        tree[i << 1 | 1].num += tree[i].add *(c >> 1);
        tree[i].add = 0;
    }
}
void change(int i, int l, int r, int c)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        tree[i].add += c;
        tree[i].num += c * (r - l + 1);
        return;
    }
    downdata(i, tree[i].right - tree[i].left + 1);
    int mid = (tree[i].left + tree[i].right) >> 1;
    if (mid >= r)
        change(i << 1, l, r, c);
    else
        if (mid < l)
            change(i << 1 | 1, l, r, c);
        else
            change(i << 1, l, mid, c),
            change(i << 1 | 1, mid + 1, r, c);
    updata(i);
}
void build(int l, int r, int i)
{
    tree[i].left = l, tree[i].right = r, tree[i].add = tree[i].num = 0;
    if (l == r)
    {
        scanf("%lld", &tree[i].num);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, i << 1),
    build(mid + 1, r, i << 1 | 1);
    updata(i);
}
void query(int l, int r, int i)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        ans += tree[i].num;
        return;
    }
    downdata(i, tree[i].right - tree[i].left + 1);
    int mid = (tree[i].left + tree[i].right) >> 1;
    if (mid >= r)
        query(l, r, i << 1);
    else
        if (mid < l)
            query(l, r, i << 1 | 1);
        else
            query(l, mid, i << 1),
            query(mid + 1, r, i << 1 | 1);
    updata(i);
}
int main()
{
    int ch;
    int n, m;
    int x, y, k;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &ch);
        scanf("%d%d", &x, &y);
        if (ch == 1)
        {
            scanf("%d", &k);
            change(1, x, y, k);
        }else{
            ans = 0;
            query(x, y, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
