#include <iostream>
#include <cstdio>
#define INF 0x7fffffff
#define Q 500000
using namespace std;
int a[200005];
int qu[Q], num[Q];
int head = 1, tail = 0;
int ans = 0;
void push(int i)
{
    if (a[i] == -INF)
        return;
    while (head <= tail && a[i] >= qu[tail])
        --tail;
    qu[++tail] = a[i];
    num[tail] = i;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < l; ++i)
        a[i] = -INF;
    for (int i = l; i <= n; ++i)
    {
        while (head <= tail && num[head] < i - r)
            ++head;
        a[i] += qu[head];
        push(i - l + 1);
    }
    for (int i = n; i + r > n; --i)
    {
        ans = max(ans, a[i]);
    }
    cout << ans;
    return 0;
}
