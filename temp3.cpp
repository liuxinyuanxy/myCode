#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
#define LL long long
using namespace std;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[1 << 21], *p1 = buf, *p2 = buf;
template <typename T>
void rd(T &s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '-', ch < '0' || ch > '9')
		;
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9')
		;
	s *= (p ? -1 : 1);
}
template <typename T, typename... Args>
void rd(T &s, Args &... args)
{
	rd(s);
	rd(args...);
}
const int MAXN = 100005;
int n;
pair<LL, pair<LL, int> > que[MAXN];
vector<LL> hs;
LL ans[MAXN << 2];
LL rev(LL w)
{
	LL p = 0;
	while (w != 0)
		p = p * 10 + w % 10,
		w /= 10;
	return p;
}
void init()
{
	int p = 0;
	LL w;
	LL Max = *(hs.end() - 1);
	for (LL i = 1; i <= Max; ++i)
	{
		p = 0;
		w = i;
		while (w <= Max)
		{
			while (w > hs[p])
				++p;
			++ans[p];
			w += rev(w);
		}
	}
}
int main()
{
	rd(n);
	for (int i = 1; i <= n; ++i)
	{
		rd(que[i].first, que[i].second.first, que[i].second.second);
		--que[i].first;
		hs.push_back(que[i].first);
		hs.push_back(que[i].second.first);
	}
	sort(hs.begin(), hs.end());
	hs.erase(unique(hs.begin(), hs.end()), hs.end());
	for (int i = 1; i <= n; ++i)
	{
		que[i].first = lower_bound(hs.begin(), hs.end(), que[i].first) - hs.begin();
		que[i].second.first = lower_bound(hs.begin(), hs.end(), que[i].second.first) - hs.begin();
	}
	init();
	LL p = 0;
	for (unsigned int i = 1; i < hs.size(); ++i)
	{
		ans[i] += ans[i - 1];
	}
	for (int i = 1; i <= n; ++i)
	{
		p ^= (ans[que[i].second.first] - ans[que[i].first]) % que[i].second.second;
	}
	cout << p;
	return 0;
}