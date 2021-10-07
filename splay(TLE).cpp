#include <iostream>
#include <cstdio>
#define MAX 1000005
using namespace std;
int tot;
int son[MAX][2], fa[MAX], num[MAX], val[MAX], rt;
inline int read()
{
    int t = 0, p = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            p = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        t = t  * 10 + ch - '0';
        ch = getchar();
    }
    return t * p;
}
void write(int w)
{
    if (w < 0)
    {
        putchar('-');
        w = -w;
    }
    if (w / 10)
        write(w / 10);
    putchar(w % 10 + '0');
}
inline int getwh(int x)
{
    return son[fa[x]][1] == x;
}
inline void updata(int x)
{
    num[x] = num[son[x][0]] + num[son[x][1]] + 1;
}
inline void rotate(int x)
{
    int f = fa[x], gf = fa[f], wh = getwh(x);
    fa[x] = gf;
    son[gf][getwh(f)] = x;
    fa[son[x][wh ^ 1]] = f;
    son[f][wh] = son[x][wh ^ 1];
    fa[f] = x;
    son[x][wh ^ 1] = f;
    updata(f);
    updata(x);
}
inline void splay(int x, int to)
{
    while (fa[x] != to)
    {
        int f = fa[x];
        if (fa[f] != to)
        {
            if (getwh(f) == getwh(x))
                rotate(f);
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
    ++tot;
    val[tot] = x;
    num[tot] = 1;
    if (!rt)
    {
        rt = tot;
        return ;
    }
    int o = rt, last = 0;
    while (o)
    {
        ++num[o];
        last = o;
        o = son[o][x > val[o]];
    }
    fa[tot] = last;
    son[last][x > val[last]] = tot;
    splay(tot, 0);
}
inline int findx(int x)
{
    int o = rt;
    while (val[o] != x && o)
        o = son[o][x > val[o]];
    return o;
}
inline void det(int x)
{
    register int temp = findx(x);
    if (temp == 0)
        return;
    splay(temp, 0);
    register int a = son[rt][0], b = son[rt][1];
    fa[a] = fa[b] = 0;
    if (!a || !b)
    {
        rt = a + b;
        return ;
    }
    while (son[a][1])
    {
        num[a] += num[b];
        a = son[a][1];
    }
    num[a] += num[b];
    son[a][1] = b;
    fa[b] = a;
    splay(b, 0);
}
inline int findrank(int x)
{
    register int ans = 0, o = rt;
    while (o)
    {
        if (x > val[o])
        {
            ans += num[son[o][0]]+1;
            o = son[o][1];
        }
        else
        {
            o = son[o][0];
        }
    }
    if (o)
        splay(o, rt);
    return ans;
}
inline int isrank(int x)
{
    register int o = rt;
    while (1)
    {
        if (num[son[o][0]] + 1 == x)
        {
            return o;
        }
        if (num[son[o][0]] < x)
        {
            x -= num[son[o][0]] + 1;
            o = son[o][1];
        }
        else
        {
            o = son[o][0];
        }
    }
}
int main()
{
    register int n;
    register int opt, x;
    n = read();
    for (register int i = 1; i <= n; ++i)
    {
        opt = read();
        x = read();
        switch (opt)
        {
        case 1:
            {
                insert(x);
                break;
            }
        case 2:
            {
                det(x);
                break;
            }
        case 3:
            {
                write(findrank(x) + 1);
                putchar('\n');
                break;
            }
        case 4:
            {
                write(val[isrank(x)]);
                putchar('\n');
                break;
            }
        case 5:
            {
                write(val[isrank(findrank(x))]);
                putchar('\n');
                break;
            }
        case 6:
            {
                int temp = isrank(findrank(x) + 1);
                write((val[temp] > x ? val[temp] : val[isrank(findrank(x + 1) + 1)]));
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}
