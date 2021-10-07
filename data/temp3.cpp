#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    map<string, int> word;
    string s;
    while (cin >> s)
        ++word[s];
    for (auto x:word)
        cout << x.first << ":" << x.second << endl;
    return 0;
}
