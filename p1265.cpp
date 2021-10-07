#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define MAX 5001
using namespace std;
double g[MAX];
bool done[MAX];
struct point{
	double x, y;
}p[MAX];
inline double dis(int i, int j)
{
	return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
int main()
{
	int n, id;
	int tot = 0;
	double x, y, ans = 0, mint;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf%lf", &x, &y);
		p[i].x = x,
		p[i].y = y;
	}
	for (int i = 1; i <= n; ++i)
		g[i] = 999999999999999999;
	g[1] = 0;
	while (tot < n)
	{
		mint = 999999999999999999;
		id = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (g[i] < mint && !done[i])
				mint = g[i],
				id = i;
		}
		++tot;
		ans += g[id];
		done[id] = 1;
		for (int i = 1; i <= n; ++i)
			if (!done[i])
				if (g[i] > dis(i, id))
					g[i] = dis(i, id);
	}
	printf("%.2lf", ans);
	return 0;
}

