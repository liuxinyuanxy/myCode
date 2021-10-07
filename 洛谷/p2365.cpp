#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 10000;
int dp[MAXN], sumf[MAXN], sumt[MAXN];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
	{
		int ti, fi;
		cin >> ti >> fi;
		sumf[i] = sumf[i - 1] + fi;
		sumt[i] = sumt[i - 1] + ti;
	}
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 0x7fffffff;
		for (int j = 0; j < i; ++j)
			dp[i] = min(dp[i], dp[j] + (s + sumt[i] - sumt[j]) * (sumf[n] - sumf[j]));
	}
	cout << dp[n] << endl;
	return 0;
}