#include <iostream>
#include <cstdio>
using namespace std;
struct node{
    int left, right, value;
}tree[40005];
int MAX;
void build(int i, int left, int right)
{

    tree[i].left = left;
    tree[i].right = right;
    if (left == right)
        scanf("%d", &tree[i].value);
    else
        build(i << 1, left, (left + right) >> 1),
        build((i << 1) | 1, ((left + right) >> 1) + 1, right),
        tree[i].value = max(tree[i << 1].value, tree[i << 1 | 1].value);
}
void downdataTree(int i, int c)
{
    if (tree[i].left == tree[i].right)
    {
        tree[i].value = c;
        return;
    }
    int mid = (tree[i].left + tree[i].right) >> 1;
    if (i <= mid)
        downdataTree(i << 1, c);
    else
        downdataTree(i << 1 | 1, c);
    tree[i].value = max(tree[i << 1].value, tree[i << 1 | 1].value);
}
void query(int i, int l, int r)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        MAX = max(MAX, tree[i].value);
        return;
    }
    int mid = i << 1;
    if (tree[mid].right >= r)
    {
        query(mid, l, r);
    }else{
        if (tree[mid | 1].left <= l)
        {
            query(mid | 1, l, r);
        }else{
            query(mid, l, tree[mid].right);
            query(mid | 1, tree[mid | 1].left, r);
        }
    }
}
int main()
{
    int temp, m, n, r, l;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    cout << "OK\n";
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &temp, &l, &r);
        if (temp)
        {
            MAX = - (1 << 20);
            query(1, l, r);
            printf("%d\n", MAX);
        }else{
            downdataTree(l, r);
        }
    }
    return 0;
}
