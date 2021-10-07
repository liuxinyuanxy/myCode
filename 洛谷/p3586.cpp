#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>
#define il inline
#define re register
#define LL long long
#define gc getchar
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    char ch;
    bool p = 0;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', isdigit(ch = gc()))
        ;
    s *= p ? -1 : 1;
}
vector<int> hs;
const int MAXN = 2000000;
int cnt;
LL tree1[MAXN], tree2[MAXN];
int val[MAXN];
#define lowbit(x) ((x) & -(x))
void insert(LL *tree, int p, int x)
{
    for (int i = p; i <= cnt; i += lowbit(i))
        tree[i] += x;
}
LL query(LL *tree, int x)
{
    LL ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
struct node
{
    int opt, k, a;
} Q[MAXN];
int main()
{
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= m; ++i)
    {
        char ch;
        while (!isalpha(ch = gc()))
            ;
        Q[i].opt = ch == 'U' ? 1 : 2;
        read(Q[i].k), read(Q[i].a);
        hs.push_back(Q[i].a);
    }
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    cnt = hs.size();
    for (int i = 1; i <= m; ++i)
    {
        if (Q[i].opt == 1)
        {
            int x = lower_bound(hs.begin(), hs.end(), Q[i].a) - hs.begin() + 1;
            if (val[Q[i].k])
            {
                insert(tree1, val[Q[i].k], -1);
                insert(tree2, val[Q[i].k], -hs[val[Q[i].k] - 1]);
            }
            val[Q[i].k] = x;
            insert(tree1, x, 1);
            insert(tree2, x, hs[x - 1]);
        }
        else
        {
            int x = lower_bound(hs.begin(), hs.end(), Q[i].a) - hs.begin() + 1;
            int s = query(tree1, cnt) - query(tree1, x - 1);
            LL s2 = query(tree2, x - 1);
            if (s2 >= (Q[i].k - s) * 1ll * Q[i].a)
                printf("TAK\n");
            else
                printf("NIE\n");
        }
    }
    return 0;
}