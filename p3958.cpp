#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define sqr(x) ((x) * (x))
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
using namespace std;
ll n, h, r;
struct node{
	ll x, y, z;
	bool vis;
}point[3000];
il double dis(const node& a, const node& b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}
bool cmp(const node& a, const node& b)
{
	return a.z < b.z;
}
il ll rd()
{
	rll s = 0, p = 1; rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
bool dfs(rll u)
{
	if (point[u].z + r >= h)
		return true;
	point[u].vis = 1;
	for (rll i = 1; i <= n; ++i)
	{
		if (!point[i].vis && dis(point[i], point[u]) <= r * 2.0)
			if (dfs(i))
				return true;
	}
	return false;
}
int main()
{
	rll T = rd();
	bool p;
	while (T--)
	{
		n = rd(), h = rd(), r = rd();
		p = 0;
		for (rll i = 1; i <= n; ++i)
			point[i].x = rd(),
			point[i].y = rd(),
			point[i].z = rd(),
			point[i].vis = 0;
		sort(point + 1, point + 1 + n, cmp);
		for (rll i = 1; i <= n; ++i)
			if (!point[i].vis && point[i].z <= r)
				if(dfs(i))
				{
					p = 1;
					break;
				}
		puts(p ? "Yes" : "No");
	}
	return 0;
}

