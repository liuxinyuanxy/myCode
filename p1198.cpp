#include <iostream>
#include <cstdio>
#define MAXN 200002
#define mid() ((tree[i].left + tree[i].right) >> 1)

using namespace std;
typedef long long ll;
int n = MAXN - 1;
ll d;
bool p = 0;
ll ans = 0, tot = 0;
int father[MAXN * 4];
struct node
{
    int left, right;
    ll value;
}tree[MAXN * 4];
void build(int l, int r, int i)
{
    tree[i].left = l,
    tree[i].right = r,
    tree[i].value = 0;
    if (l == r)
    {
        father[l] = i;
        return;
    }
    build(l, mid(), i << 1);
    build(mid() + 1, r, i << 1 | 1);
}
void updata(int i)
{
    int l = i << 1, r = i << 1 | 1;
    tree[i].value = max(tree[l].value, tree[r].value);
    if (i == 1)
        return;
    updata(i >> 1);
}
void query(int l, int r, int i)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        if (p)
            ans = tree[i].value,
            p = 0;
        else
            ans = max(ans, tree[i].value);
        return;
    }
    int mid = mid();
    if (mid >= r)
        query(l, r, i << 1);
    else
        if (mid < l)
            query(l, r, i << 1 | 1);
        else
            query(l, mid, i << 1),
            query(mid + 1, r, i << 1 | 1);
}
int main()
{
    int m;
    ll l;
    char ch;
    build(1, MAXN, 1);
    cin >> m >> d;
    for (int i = 1; i <= m; ++i)
    {
        cin >> ch ;
        cin >> l;
        if (ch == 'Q')
        {
            ans = 0;
            p = 1;
            query(tot - l + 1, tot, 1);
            cout << ans << endl;
        }else{
            ++tot;
            tree[father[tot]].value = (l + ans) % d;
            updata(father[tot] >> 1);
        }
    }
    return 0;
}
