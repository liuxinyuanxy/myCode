#include <iostream>
#include <cstdio>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 2005
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
int dis[_][_];
int c[_], d[_];
double ki[_];
double dp[_][_][2];
il int rd()
{
    rt s = 0; rc ch;
    while (ch = gc(), ch < '0' || ch > '9');
    while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
    return s;
}
il double rdd()
{
	double s = 0.0;
	rt p = 10;
	rc ch;
	while (ch = gc(), ch != '.');
	while (ch = gc(), ch >= '0' && ch <= '9')
		s = (s * p + ch - '0') / p,
		p *= 10;
	return s;
}
il double qiwang(rt a, rt b, double qa, double qb)
{
	return (dis[c[a]][c[b]] * (1 - qa) * (1 - qb) + dis[c[a]][d[b]] * (1 - qa) * qb + dis[d[a]][c[b]] * qa * (1 - qb) + dis[d[a]][d[b]] * qa * qb);
}
int main()
{
	rt a, b, w;
	rt n = rd(), m = rd(), v = rd(), e = rd();
	double ans = 1e20;
	for (rt i = 1; i <= n; ++i)
		c[i] = rd();
	for (rt i = 1; i <= n; ++i)
		d[i] = rd();
	for (rt i = 1; i <= n; ++i)
		ki[i] = rdd();
	for (rt i = 1; i <= e; ++i)
	{
		a = rd(), b = rd(), w = rd();
		if (a == b)
			continue;
		dis[a][b] = dis[b][a] = (!dis[a][b] ? w : min(w, dis[a][b]));
	}
	for (rt k = 1; k <= v; ++k)
		for (rt i = 1; i <= v; ++i)
			for (rt j = 1; j <= v; ++j)
				dis[i][j] = !dis[i][j] ? dis[k][i] + dis[k][j] : min(dis[i][j], dis[i][k] + dis[k][j]);
//	for (rt i = 1; i <= m; ++i)
//		for (rt j = 1; j <= n; ++j)
//			dp[j][i][0] = dp[j][i][1]= 9;
	for (rt i = 1; i <= m; ++i)
		for (rt j = i; j <= n; ++j)
			dp[j][i][0] = dp[j][i][1] = 1e20;
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i][0][0] = dp[i - 1][0][0] + qiwang(i, i - 1, 0, 0);
	for (rt i = 1; i <= m; ++i)
		for (rt j = i; j <= n; ++j)
		{
			dp[j][i][0] = min(dp[j - 1][i][0] + qiwang(j, j-1, 0, 0), dp[j - 1][i][1] + qiwang(j, j-1, 0, ki[j-1]));
			dp[j][i][1] = min(dp[j - 1][i - 1][0] + qiwang(j, j-1, ki[j], 0), dp[j - 1][i - 1][1] + qiwang(j, j-1, ki[j], ki[j-1]));
		}
	ans = dp[n][0][0];
	for (rt i = 1; i <= m; ++i)
		ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
//	for (rt i = 0; i <= m; ++i)
//	{
//		for (rt j = 1; j <= n; ++j)
//			printf("%.2f %.2f\t", dp[j][i][0], dp[j][i][1]);
//		cout << endl;
//	}
	printf("%.2lf", ans);
    return 0;
}
