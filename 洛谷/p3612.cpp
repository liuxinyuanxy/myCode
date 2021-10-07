#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define LL long long
using namespace std;
char ch[100];
int len;
char get(LL slen, LL pos)
{
	if (!pos)
		pos = slen;
	if (slen == len)
		return ch[pos];
	LL nlen = slen >> 1;
	return get(nlen, pos <= nlen ? pos : ((pos - nlen - 1) % nlen));
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> (ch + 1);
	len = strlen(ch + 1);
	LL n, tmp = len;
	cin >> n;
	while (n > tmp)
		tmp <<= 1;
	cout << get(tmp, n);
	return 0;
}