#include <iostream>
#include <cctype>
#include <cstdio>
#define isdigit(x) ((x) >= '0' && (x) <= '9')
#define gc getchar
using namespace std;
template <typename T>
void rd(T &s)
{
	s = 0;
	char ch;
	bool p = 0;
	while (ch = gc(), p |= ch == '0', !isdigit(ch))
		;
	while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch));
}
int main()
{
	return 0;
}