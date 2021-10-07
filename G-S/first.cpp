#include <algorithm>
#include <cstdio>
#include <iostream>
#define mid(l, r) ((l) + (r) >> 1)
#define ls (o << 1)
#define rs ((o << 1) | 1)
using namespace std;
const int N = 100005;
int Q, M;
struct Que
{
    int r, m;
} que[N];
struct node
{
    int l, r, val;
} Node[N << 2];
void build(int l, int r, int o)
{
    Node[o].l = l, Node[o].r = r, Node[o].val = 1;
    if (l == r)
        return;
    build(l, mid(l, r), o << 1);
    build(mid(l, r) + 1, r, (o << 1) | 1);
}
void modify(int l, int r, int o, int m)
{
    if (Node[o].l == l && Node[o].r == r)
        Node[o].val = Node[o].val * 1ll * m % M;
    else
    {
        int mid = mid(Node[o].l, Node[o].r);
        if (r <= mid)
            modify(l, r, o << 1, m);
        else if (l > mid)
            modify(l, r, (o << 1) | 1, m);
        else
            modify(l, mid, o << 1, m), modify(mid + 1, r, (o << 1) | 1, m);
    }
}
void push_down(int o)
{
    if (Node[o].l == Node[o].r)
    {
        cout << Node[o].val << endl;
        return;
    }
    Node[ls].val = Node[ls].val * 1ll * Node[o].val % M;
    Node[rs].val = Node[rs].val * 1ll * Node[o].val % M;
    push_down(ls), push_down(rs);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> Q >> M;
        for (int i = 1; i <= Q; ++i)
        {
            int op, m;
            cin >> op >> m;
            if (op == 1)
                que[i].m = m, que[i].r = Q;
            else
                que[i].r = -1, que[m].r = i - 1;
        }
        build(1, Q, 1);
        for (int i = 1; i <= Q; ++i)
        {
            if (que[i].r == -1)
                continue;
            modify(i, que[i].r, 1, que[i].m);
        }
        push_down(1);
    }
    return 0;
}