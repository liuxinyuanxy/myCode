#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define re register
using namespace std;
string s[30000];
int dp[30000];
bool check(re int u, re int v)
{
	re int len1 = s[u].length(), len2 = s[v].length();
	if (len1 == len2)
	{
		bool p = 0;
		for (re int i = 0; i < len1; ++i)
			if (s[u][i] != s[v][i])
			{
				if (p)
					return 0;
				else
					p = 1;
			}
		return p;
	}
	if (len1 == len2 - 1)
	{
		bool p = 0;
		for (re int i = 0, j = 0; i < len1; ++i, ++j)
		{
			if (s[u][i] != s[v][j])
			{
				if (p)
					return 0;
				++j;
				p = 1;
				if (s[u][i] != s[v][j])
					return 0;
			}
			if (j >= len2)
				return 0;
		}
		return 1;
	}
	if (len1 == len2 + 1)
	{
		bool p = 0;
		for (re int i = 0, j = 0; j < len2; ++i, ++j)
		{
			if (s[u][i] != s[v][j])
			{
				if (p)
					return 0;
				++i;
				p = 1;
				if (s[u][i] != s[v][j])
					return 0;
			}
			if (i >= len1)
				return 0;
		}
		return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, ans = 1;
	cin >> n;
	for (re int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		dp[i] = 1;
		for (re int j = 1; j < i; ++j)
			if (check(j, i))
			{
				dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] > ans)
				{
					ans = dp[i];
					break;
				}
				// cout << s[i] << " " << s[j] << endl;
			}
	}
	cout << ans << endl;
	return 0;
}