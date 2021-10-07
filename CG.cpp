#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define il inline
#define re register
#define rt re int
#define sqr(x) ((x) * (x))
using namespace std;
struct point{
	double x, y;
};
int n;
int s[100005], t[100005];
point po[100005];
il double area(point p, point q, point s)
{
	return p.x * q.y - p.y * q.x + q.x * s.y - q.y * s.x + s.x * p.y - s.y * p.x;
}
il bool toLeft(point p, point q, point s)
{
	return area(p, q, s) > 0;
}
il double dis(rt x, rt y)
{
	return sqrt(sqr(po[x].x - po[y].x) + sqr(po[x].y - po[y].y));
}
bool cmp(point p, point q)
{
	return toLeft(po[1], p, q);
}
void ltl()
{
	int tmp = 1;
	for (rt i = 2; i <= n; ++i)
		if (po[i].y < po[tmp].y)
			tmp = i;
		else
			if (po[i].y == po[tmp].y)
				if (po[i].x < po[tmp].x)
					tmp = i;
	swap(po[1], po[tmp]);
}
int maintb()
{
	int tops1, tops2, topt = 0;
	double ans = 0;
	scanf("%d", &n);
	for (rt i = 1; i <= n; ++i)
		scanf("%lf%lf", &po[i].x, &po[i].y);
	ltl();
// 	cout << p0.x << "\t" << p0.y << "\n";
	sort(po + 2, po + 1 + n, cmp);
	tops1 = 2;
	tops2 = 1;
	s[tops1] = 2;
	s[tops2] = 1;
	for (rt i = n; i >= 3; --i)
	{
		t[++topt] = i;
	}
	while (topt)
		toLeft(po[s[tops2]], po[s[tops1]], po[t[topt]]) ? (++tops2, s[++tops1] = t[topt--]) : (--tops1, --tops2);
	for (rt i = 2; i <= tops1; ++i)
	{
		ans += dis(s[i], s[i - 1]);
	}
	ans += dis(s[tops1], s[1]);
	printf("%.2lf", ans);
	return 0;
}