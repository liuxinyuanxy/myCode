#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
    map<string, int> word;
    string s;
    while (cin >> s)
    {
        auto p = word.insert(pair <string, int > (s, 1));
        if (!p.second)
            ++word[s];
    }
    for (auto x:word)
        cout << x.first << ":" << x.second << endl;
    return 0;
}
