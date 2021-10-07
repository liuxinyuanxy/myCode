#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define il inline
using namespace std;
struct point{
	double x, y;
};
struct segment{
	point l, r;
};
il double area(point p, point q, point s)
{
	return p.x * q.y - p.y * q.x + q.x * s.y - q.y * s.x + s.x * p.y - s.y * p.x;
}
il bool toLeft(point p, point q, point s)
{
	return area(p, q, s) > 0;
}
il bool check(segment a, segment l)
{
	if (fabs(area(l.l, l.r, a.l)) <= 1e-6 || fabs(area(l.l, l.r, a.r)) <= 1e-6)
		return 1;
	return toLeft(l.l, l.r, a.l) != toLeft(l.l, l.r, a.r);
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	int T, n;
	segment t;
	cin >> T;
	while (T--)
	{
		bool p = 0, ppp = 0;
		cin >> n;
		vector<segment> v;
		vector<point> v2;
		for (int i = 1; i <= n; ++i)
		{
			cin >> t.l.x >> t.l.y >> t.r.x >> t.r.y;
			v.push_back(t);
			v2.push_back(t.l);
			v2.push_back(t.r);
		}
		if (n == 1)
		{
			cout << "Yes!\n";
			continue;
		}
		for (int i = 0; i < v2.size(); ++i)
		{
			for (int j = 0; j < v2.size(); ++j)
			{
				p = 0;
				t.l = v2[i];
				t.r = v2[j];
				if (fabs(t.l.x - t.r.x) < 1e-8 && fabs(t.l.y - t.r.y) < 1e-8)
					continue;
				// printf("%lf %lf %lf %lf\n", t.l.x, t.l.y, t.r.x, t.r.y);
				for (int kk = 0; kk < v.size(); ++kk)
				{
					segment k = v[kk];
					if (!check(k, t))
					{
						// printf("%lf %lf %lf %lf\n\n", k.l.x, k.l.y, k.r.x, k.r.y);
						p = 1;
						break;
					}
				}
				if (!p)
				{
					cout << "Yes!\n";
					ppp = 1;
					break;
				}
			}
			if (ppp)
				break;
		}
		if (!ppp)
			cout << "No!\n";
	}
	return 0;
}