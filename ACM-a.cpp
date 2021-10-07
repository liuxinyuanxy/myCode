#include <iostream>
#include <cstdio>
#include <cmath>
#define rt register int
using namespace std;
int n, m;
//inline char nc(){
//    static char buf[100000],*p1=buf,*p2=buf;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int _read(){
    register char ch=getchar();rt sum=0;
    while(!(ch>='0'&&ch<='9'))ch=getchar();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum;
}
void write(int aaa)
{
	if (aaa / 10)
		write(aaa / 10);
	putchar(aaa % 10 + '0');
}
int main()
{
	rt t;
	t = _read();
	while (t--)
	{
		n = _read(),
		m = _read();
		write(m);
		putchar(' ');
		if (m == 0)
			putchar('0');
		else
			for (rt i = 1; i <= m; ++i)
			{
				if (ceil(double(m) / i) - 1 <= n - m)
				{
					write(i);
					break;
				}
			}
		putchar('\n');
	}
	return 0;
}

