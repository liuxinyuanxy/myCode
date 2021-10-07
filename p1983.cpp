#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> to[1005];
int du[1005];
int g[1005];
int q[1005];
int l, r;
int ans;
bool hs[1005][1005];
int main()
{
	int t;
	int a[1005] = {0};
	int n, m, s;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &s);
		for (int j = 1; j <= s; ++j)
		{
			scanf("%d", &a[j]);
		}
		for (int j = 1; j < s; ++j)
			for (int k = a[j] + 1; k < a[j + 1]; ++k)
				for (int l = 1; l <= s; ++l)
					if (!hs[k][a[l]])
						++du[a[l]],
						hs[k][a[l]] = 1,
						to[k].push_back(a[l]);
	}
	l = r = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!du[i])
			g[i] = 1,
			q[r++] = i;
	}
	while (l != r)
	{
		t = q[l++];
		ans = max(ans, g[t]);
		for (auto x : to[t])
		{
			--du[x];
			if (!du[x])
			{
				q[r++] = x;
				g[x] = g[t] + 1;
			}
		}
	}
	printf("%d", ans);
	return 0;	
} 
