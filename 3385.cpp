#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 2005
using namespace std;
typedef pair<int, int> P;
int g[MAXN];
vector<P> vv[MAXN];
int main()
{
	int t, n, m, a, b, w;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			vv[i].clear(),
				vv[i].reserve(200);
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &a, &b, &w);
			if (w < 0)
			{
				vv[a].push_back(P(b, w));
			}
			else
			{
				vv[a].push_back(P(b, w));
				vv[b].push_back(P(a, w));
			}
		}
		bool p = 0;
		queue<int> q;
		bool vis[MAXN] = {0};
		int temp;
		int cnt[MAXN] = {0};
		int i = 1;
		memset(g, 0x7f, sizeof(g));
		g[i] = 0;
		q.push(i);
		cnt[i] = vis[i] = 1;
		while (!q.empty())
		{
			temp = q.front();
			for (auto x : vv[temp])
				if (g[temp] + x.second < g[x.first])
				{
					g[x.first] = g[temp] + x.second;
					if (!vis[x.first])
					{
						q.push(x.first);
						vis[x.first] = 1;
						++cnt[x.first];
						if (cnt[x.first] > n)
						{
							printf("YE5\n");
							p = 1;
						}
					}
					if (p)
						break;
				}
			if (p)
				break;
			q.pop();
			vis[temp] = 0;
		}
		if (!p)
			printf("N0\n");
	}
	return 0;
}
