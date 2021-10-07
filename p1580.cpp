#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
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
using namespace std;
int cnt = 0;
string temp;
string at_name;
il string get_name(stringstream& ss)
{
	bool p1 = 1, p2 = 1;
	string name = "GG";
	while (ss >> temp)
	{
		if (temp == ":")
			return name;
		if (temp == "yyy" && p1)
			p1 = 0;
		else
			if (temp == "loves" && p2)
				p2 = 0;
			else
				name = temp;
	}
	return name;
}
il string get_at(stringstream& ss)
{
	string name = "GG";
	while (ss >> temp)
	{
		if (temp[0] == '@')
		{
			if (name != "GG")
				return "GG";
			ss >> temp;
			ss >> temp;
			name = temp;
		}
	}
	return name;
}
void fstline()
{
	string line, name;
	getline(cin, line);
	stringstream ss(line);
	name = get_name(ss);
	at_name = get_at(ss);
}
bool line()
{
	++cnt;
	string line, name, at_temp;
	getline(cin, line);
	stringstream ss(line);
	name = get_name(ss);
	if (name == "GG")
		return false;
	if (name == at_name)
	{
		cout << "Successful @yyy loves ";
		cout << at_name;
		cout << " attempt";
		exit(0);
	}
	at_temp = get_at(ss);
	if (at_temp != at_name)
	{
		cout << "Unsuccessful @yyy loves ";
		cout << at_name;
		cout << " attempt\n";
		cout << cnt << endl;
		cout << "yyy loves ";
		cout << name << endl;
		exit(0);
	}
	return true;
}
int main()
{
	cnt = 1;
	fstline();
	while (line());
	cout << "Unsuccessful @yyy loves ";
	cout << at_name;
	cout << " attempt\n";
	cout << cnt - 1 << endl;
	cout << "Good Queue Shape";
	return 0;
}


