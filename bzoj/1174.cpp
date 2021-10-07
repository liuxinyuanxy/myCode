#include <iostream>
#include <cstdio>
#include <cstring>
#define mid(a, b) ((a + b) >> 1)
#define il inline
#define gc getchar
#define ll long long
#define re register
#define rc register char
#define rt register int
#define rll register ll
#define mp make_pair
#define _ 10000000
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std; 
ll ans;
int head[_], nxt[_], val[_], sze[_];
int root = 0, tot, cnt;
il void rd(int& s)
{
	rc ch; s = 0;
	while (ch = gc(), ch < '0' || ch > '9');
	while (s = s * 10 + ch - '0', ch = gc(), ch >= '0' && ch <= '9');
}
il void add(rt& u, rc ch)
{
	nxt[++tot] = head[u];
	head[u] = tot;
	val[tot] = ch;
	
	u = tot;
}
int main()
{
	bool p;
	rt n, o, len = 0;
	rc ch;
	rd(n);
	for (rt i = 1; i <= n; ++i)
	{
		o = root;
		len = 0;
		while (ch = gc(), iscntrl(ch));
		while (!iscntrl(ch)) 
		{
			p = 1;
			for (rt j = head[o]; j; j = nxt[j])
				if (val[j] == ch)
				{
					p = 0;
					o = j;
					break;
				}
			if (p)
				add(o, ch);
			ch = gc();
			++len;
			++sze[o];
			ans = max(ans, sze[o] * len);
		}
	}
	printf("%lld", ans);
	return 0;
}


