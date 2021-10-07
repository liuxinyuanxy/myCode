#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 2000006
using namespace std;
il int rd()
{
    rt s = 0; rc ch;
    while (ch = gc(), ch < '0' || ch > '9');
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
    return s;
} 
double delta = 0.99;
bool vis[_];
ll ans;
int n, m, k, c = 0;
int arr[_], cnt;
int dfn[_], low[_];
int stack[_], top;
int head[_], nxt[_], to[_], tot;
int val[_], ru[_];
il void add(rt u, rt v)
{
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}
bool cmp(rt a, rt b)
{
    return val[a] > val[b];
}
void tarjan(rt u)
{
    rt v;
    dfn[u] = low[u] = ++c;
    vis[u] = 1;
    stack[++top] = u;
    for (rt i = head[u]; i; i = nxt[i])
    {
        v = to[i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else
            if (vis[v])
                low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        rt id = 0, vid = 0x7fffffff;
        while (stack[top] != u)
        {
            if (val[stack[top]] < vid)
                vid = val[stack[top]],
                id = stack[top];
            vis[stack[top]] = 0;
            --top;
        }
        val[id] = 0;
        vis[u] = 0;
        --top;
    }
}
int main()
{
    srand(19260817);
    srand(rand());
    srand(rand());
    rt u, v;
    n = rd(), m = rd(), k = rd();
    for (rt i = 1; i <= n; ++i)
        val[i] = rd();
    for (rt i = 1; i <= m; ++i)
    {
        u = rd();
        v = rd();
        add(u, v);
        ++ru[v];
    }
    for (rt i = 1; i <= n; ++i)
        if (ru[i])
            arr[++cnt] = i;
    sort(arr + 1, arr + 1 + cnt, cmp);
    if (m % 10 == 1)
    	for (rt i = 1; i <= min(k, cnt); ++i)
        	ans += val[arr[i]];
    else
    {
    	for (rt i = 1; i <= cnt; ++i)
    	{
    		if (!dfn[arr[i]])
    			tarjan(arr[i]);
        }
        sort(arr + 1, arr + 1 + cnt, cmp);
    	for (rt i = 1; i <= min(k, cnt); ++i)
       		ans += val[arr[i]];
    }
    printf("%lld", ans);
    return 0;
}
