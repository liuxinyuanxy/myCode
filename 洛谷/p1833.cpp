#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#define gc getchar
#define il inline
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
		;
	s *= p ? -1 : 1;
}
template <typename T, typename... Args>
void read(T &s, Args &... args)
{
	read(s), read(args...);
}
const int MAXN = 20000;
int dp[MAXN], qu[MAXN], l, r;
int qu2[MAXN];
int main()
{
	int h1, h2, m1, m2;
	read(h1, m1, h2, m2);
	int T = (h2 - h1) * 60 + (m2 - m1);
	int n;
	read(n);
	for (int w = 1; w <= n; ++w)
	{
		int t, c, p;
		read(t, c, p);
		if (!p)
			for (int j = t; j <= T; ++j)
				dp[j] = max(dp[j], dp[j - t] + c);
		else
		{
			for (int i = 0; i < t; ++i)
			{
				l = r = 0;
				for (int j = 0; i + j * t <= T; ++j)
				{
					int x = i + j * t;
					while (l != r && dp[x] - j * c >= qu2[r - 1])
						--r;
					qu[r++] = j, qu2[r - 1] = dp[x];
					while (l != r && j - qu[l] > p)
						++l;
					dp[x] = max(dp[x], (j - qu[l]) * c + qu2[l]);
				}
			}
		}
		// cout << endl;
		// for (int i = 1; i <= T; ++i)
		// 	cout << dp[i] << " ";
		// cout << endl;
	}
	cout << dp[T] << endl;
	return 0;
}