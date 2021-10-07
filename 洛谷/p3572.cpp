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
const int MAXN = 2000000;
int dp[MAXN], d[MAXN];
int qu[MAXN], l, r;
int main()
{
	int n;
	read(n);
	for (int i = 1; i <= n; ++i)
		read(d[i]);
	int q;
	read(q);
	while (q--)
	{
		int k;
		read(k);
		l = r = 0;
		qu[r++] = 1;
		dp[1] = 0;
		for (int i = 2; i <= n; ++i)
		{
			while (qu[l] + k < i)
				++l;
			dp[i] = dp[qu[l]] + int(d[i] >= d[qu[l]]);
			while (l != r && (dp[i] < dp[qu[r - 1]] || (dp[i] == dp[qu[r - 1]] && d[i] >= d[qu[r - 1]])))
				--r;
			qu[r++] = i;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}