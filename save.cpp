#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int a[2], b;
int main()
{
	char ch[100];
	cin.getline(ch, 100);
	cin >> (ch + 2);
	cout << strlen(ch);
	string a, b;
	cin >> a >> b;
	a.insert(2, b);
	getline(cin, s);
	cout << s;
	cout << a;
	return 0;
}