#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int color[10005];
vector<int> node[10005];
int len[10005];
bool p;
int n, m;
int aaa[3];
int ans = 0;
void dfs(int i)// s :: total            t :: ans
{
    int to;
    for (int j = 0; j < len[i]; ++j)
    {
        to = node[i][j];
        if (color[to])
        {
            if (color[to] == color[i])
            {
                printf("Impossible\n");
                exit(0);
            }
            continue;
        }
        if (color[i] == 1)
        {
            color[to] = 2;
        }
        else
        {
            color[to] = 1;
        }
        dfs(to);
    }
}
int main()
{
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
        ++len[a];
        ++len[b];
    }
    for (int i = 1; i <= n; ++i)
    {
        aaa[1] = aaa[2] = 0;
        if (!color[i])
        {
            color[i] = 1;
            dfs(i);
            for (int j = 1; j <= n; ++j)
            {
                if (color[j] == 1 || color[j] == 2)
                {
                    ++aaa[color[j]];
                    color[j] = 3;
                }
            }
            ans += min(aaa[1], aaa[2]);
        }
    }
    printf("%d", ans);
    return 0;
}
