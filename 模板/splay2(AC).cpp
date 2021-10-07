//splay
#include <iostream>
#include <cstdio>
#define MAX 1000000
using namespace std;
int fa[MAX], son[MAX][2], val[MAX], sum[MAX], cnt[MAX];
int tot, rt;
inline int getwh(int x)
{
    return son[fa[x]][1] == x;
}
inline void pushup(int x)
{
    sum[x] = sum[son[x][0]] + sum[son[x][1]] + cnt[x];
}
inline void rotate(int x)
{
    int f= fa[x], gf = fa[f], wh = getwh(x);
    fa[x] = gf;
    son[gf][getwh(f)] = x;
    fa[son[x][wh ^ 1]] = f;
    son[f][wh] = son[x][wh ^ 1];
    fa[f] = x;
    son[x][wh ^ 1] = f;
    pushup(f);
    pushup(x);
}
inline void splay(int x, int to)
{
    while (fa[x] != to)
    {
        if (fa[fa[x]] != to)
        {
            if (getwh(x) == getwh(fa[x]))
                rotate(fa[x]);
            else
                rotate(x);
        }
        rotate(x);
    }
    if (!to)
        rt = x;
}
inline void insert(int x)
{
    if (!rt)
    {
        val[++tot] = x;
        sum[tot] = 1;
        cnt[tot] = 1;
        rt = tot;
        return;
    }
    int o = rt, last;
    while (o)
    {
        ++sum[o];
        if (val[o] == x)
        {
            ++cnt[o];
            pushup(o);
            pushup(last);
            splay(o, 0);
            return;
        }
        last = o;
        o = son[o][x > val[o]];
    }
    val[++tot] = x;
    sum[tot] = 1;
    cnt[tot] = 1;
    fa[tot] = last;
    son[last][x > val[last]] = tot;
    pushup(tot);
    pushup(last);
    splay(tot, 0);
}
/*inline int find_x(int x)
{
    int o = rt;
    while (val[o] != x)
    {
        o = son[o][x > val[o]];
    }
    return o;
}*/
inline void merge(int x, int y)
{
    fa[x] = fa[y] = 0;
    if (!x || !y)
    {
        rt = x + y;
        return;
    }
    while (son[x][1])
        sum[x] += sum[y],
        x = son[x][1];
    sum[x] += sum[y];
    son[x][1] = y;
    fa[y] = x;
    splay(y, 0);
}
inline void del(int x)
{
    if (cnt[rt] > 1)
    {
        --cnt[rt];
        pushup(rt);
        return;
    }
    merge(son[rt][0], son[rt][1]);
}
inline int findrank(int x)
{
    int o = rt, ans = 0;
    while (o)
    {
        if (val[o] == x)
        {
            ans += sum[son[o][0]];
            splay(o, 0);
            return ans + 1;
        }
        if (x > val[o])
            ans += sum[son[o][0]] + cnt[o],
            o = son[o][1];
        else
            o = son[o][0];
    }
    return 1;
}
inline int isrank(int x)
{
    int o = rt;
    while (1)
    {
        if (sum[son[o][0]] + 1 <= x && sum[son[o][0]] + cnt[o] >= x)
            return val[o];
        if (x > sum[son[o][0]] + cnt[o])
        {
            x -= sum[son[o][0]] + cnt[o];
            o = son[o][1];
        }
        else
            o = son[o][0];
    }
}
inline int front()
{
    int o = son[rt][0];
    while (son[o][1])
        o = son[o][1];
    return val[o];
}
inline int back()
{
    int o = son[rt][1];
    while (son[o][0])
        o = son[o][0];
    return val[o];
}
int main()
{
    int n, opt, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
            case 1:
            {
                insert(x);
                break;
            }
            case 2:
            {
                del(findrank(x));
                break;
            }
            case 3:
            {
                printf("%d\n", findrank(x));
                break;
            }
            case 4:
            {
                printf("%d\n", isrank(x));
                break;
            }
            case 5:
            {
                insert(x);
                printf("%d\n", front());
                del(rt);
                break;
            }
            case 6:
            {
                insert(x);
                printf("%d\n", back());
                del(rt);
                break;
            }
        }
    }
    return 0;
}
