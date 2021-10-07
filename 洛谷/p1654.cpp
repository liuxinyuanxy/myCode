#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 150000;
long double a[MAXN];
long double s[MAXN];
long double s1[MAXN], s2[MAXN], s3[MAXN], s4[MAXN];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	s[0] = 1;
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] * a[i];
	s1[n + 1] = s2[n + 1] = s3[n + 1] = s4[n + 1] = 0;
	for (int i = n; i >= 1; --i)
	{
		s1[i] = s1[i + 1] + (s[i] * (1.0 - a[i + 1]));
		s2[i] = s2[i + 1] + (s[i] * (1.0 - a[i + 1]) * (3.0 * i + 3.0));
		s3[i] = s3[i + 1] + (s[i] * (1.0 - a[i + 1]) * (3.0 * i * i + 6.0 * i));
		s4[i] = s4[i + 1] + (s[i] * (1.0 - a[i + 1]) * (1.0 * i * i * i + 3.0 * i * i + 3.0 * i + 1));
	}
	long double ans = 0;
	for (int l = 1; l <= n; ++l)
		ans += 1.0 / s[l - 1] * (1.0 - a[l - 1]) * ((-double(l) * l * l * s1[l]) + (long double(l) * l * s2[l]) - double(l) * s3[l] - 3.0 * l * s1[l] + s4[l]);
	printf("%.1Lf", ans);
	return 0;
}