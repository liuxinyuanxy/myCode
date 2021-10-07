#include <iostream>
#include <cstdio>
#include <cstring>
#define _ 3000000
#define rt register int
using namespace std;
char ch1[_], ch2[_];
int nxt[_], len1, len2;
int z0, z1;
int main()
{
    rt p = 0;
    cin >> (ch1 + 1) >> (ch2 + 1);
    len1 = strlen(ch1 + 1);
	for (int i = 1; i <= len1; ++i)
	{
		if (ch1[i] == '0')
			++z0;
		else
			++z1;
	}
	len2 = strlen(ch2 + 1);
    for (rt i = 2; i <= len2; ++i)
    {
        p = nxt[i - 1];
        while (ch2[p + 1] != ch2[i] && p)
            p = nxt[p];
        if (ch2[p + 1] == ch2[i])
            nxt[i] = p + 1;
        else
            nxt[i] = 0;
    }
	int i = 0;
	while (z0 || z1)
	{
		++i;
		if (ch2[i] == '0' && z0)
		{
			cout << '0';
			--z0;
		}
		else
		{
			if (ch2[i] == '1' && z1)
			{
				cout << "1";
				--z1;
			}
			else
			{
				if (z0)
				{
					cout << "0";
					--z0;
				}
				else
				{
					cout << "1";
					--z1;
				}
			}
		}
		if (i == len2)
			i = nxt[i];
	}
	return 0;
}