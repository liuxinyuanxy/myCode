#include <iostream>
#include <cstdio>
#include <cmath>
#define rt register long long
using namespace std;
bool a[1000005];
//inline char nc(){
//    static char buf[100000],*p1=buf,*p2=buf;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline long long _read(){
    register char ch=getchar();rt sum=0;
    while(!(ch>='0'&&ch<='9'))ch=getchar();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum;
}
void write(const long long& aaa)
{
	if (aaa / 10)
		write(aaa / 10);
	putchar(aaa % 10 + '0');
}
int main()
{
	rt t, len = 0;
	register long long ans = 0;
	register char ch;
	t = _read();
	while (t--)
	{
		ans = 0;
		len = 0;
		ch = getchar();
		while (ch != '0' && ch != '1')
			ch = getchar();
		while (ch == '0' || ch == '1')
		{
			a[++len] = ch - '0';
			ch = getchar();
		}
		for (rt i = 1; i <= len; ++i)
		{
			ans = ans + ((a[i] != a[i-1]) ? 1 : 2) * ((i - 1) * (len - i + 1));
			ans = ans + (a[i] ? 1 : 2) * (len - i + 1);
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

