#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define sqr(a) ((a) * (a))
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
struct node{
	ll x, y, z;
}poi[100000];
il ll rd()
{
	rll s = 0, p = 1;rc ch;
	while (ch = gc(), (ch < '0' || ch > '9') && ch != '-');
	if (ch == '-') p = -1, ch = gc();
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
	return s * p;
}
bool cmp(const node& a, const node& b)
{
	return a.z < b.z;
}
double dis(const node& a, const node& b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}
int main()
{
	double ans = 0;
	int n = rd();
	for (rt i = 1; i <= n; ++i)
		poi[i].x = rd(), poi[i].y = rd(), poi[i].z = rd();
	sort(poi + 1, poi + 1 + n, cmp);
	for (rt i = 2; i <= n; ++i)
		ans += dis(poi[i], poi[i - 1]);
	printf("%.3lf", ans);
	return 0;
}


