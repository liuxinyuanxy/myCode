#include <iostream>
#include <cstdio>
using namespace std;
struct node{
    int left, right, value;
}tree[40005];
int father[10000];
int MAX;
void build(int i, int left, int right)
{

    tree[i].left = left;
    tree[i].right = right;
    if (left == right)
        father[left] = i;
    else
        build(i << 1, left, (left + right) >> 1),
        build((i << 1) | 1, ((left + right) >> 1) + 1, right);
}
void updataTree(int i)
{
    if (i == 1)
        return;
    int u = i >> 1;
    int l = u << 1;
    int r = l | 1;
    tree[u].value = max(tree[l].value, tree[r].value);
    updataTree(u);
}
void query(int i, int l, int r)
{
    if (tree[i].left == l && tree[i].right == r)
    {
        MAX = max(MAX, tree[i].value);
        return;
    }
    int child = i << 1;         //left child
    if (tree[child].right >= l)
    {
        if (tree[child].right >= r)
            query(child, l, r);
        else
            query(child, l, tree[child].right);
    }
    child |= 1;                 //right child
    if (tree[child].left <= r)
    {
        if (tree[child].left <= l)
            query(child, l, r);
        else
            query(child, tree[child].left, r);
    }
}
int main()
{
    int temp, m, n, r, l;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &temp);
        tree[father[i]].value = temp;
        updataTree(father[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &temp, &l, &r);
        if (temp)
        {
            MAX = - (1 << 20);
            query(1, l, r);
            printf("%d\n", MAX);
        }else{
            tree[father[l]].value = r;
            updataTree(father[l]);
        }
    }
    return 0;
}
