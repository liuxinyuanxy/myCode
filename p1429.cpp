#include <iostream>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#define sqr(x) ((x) * (x))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
struct point{
	double x, y;
};
vector<point> v;
vector<point> temp;
inline void turn(point& x, double b)
{
	point t = x;
	x.x = t.x * cos(b) - t.y * sin(b);
	x.y = t.x * sin(b) + t.y * cos(b);
}
inline bool cmp(point a, point b)
{
	return a.x < b.x;
}
inline double dis(point a, point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
int main()
{
	srand(time(NULL));
	int n;
	double p;
	point t;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf%lf", &t.x, &t.y);
		v.push_back(t);
	}
	temp = v;
	double ans = 1e100;
	// cout << temp.size() << endl;
	for (int k = 1; k <= 3; ++k)
	{
		sort(temp.begin(), temp.end(), cmp);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j <= min(n - 1, i + 10); ++j)
			{
				if (i == j)
					continue;
				// cout << temp[i].x << " " << temp[i].y << " " << temp[j].x << " " << temp[j].y << endl;
				// cout << dis(temp[i], temp[j]) << endl;
				ans = min(ans, dis(temp[i], temp[j]));
			}
		}
		p = (double)rand() / RAND_MAX * 300.0;
		temp = v;
		for (auto& x : temp)
			turn(x, p);
	}
	printf("%.4lf", ans);
	return 0;
}