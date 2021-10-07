#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct node
{
    string s;
    int x;
};
int hs(string s)
{
    unsigned long long ans = 0;
    int len  = s.length();
    for (int i = 0; i < len; ++i)
    {
        ans = ans * 131 + s[i];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    map<int, node> word;
    string s;
    int h;
    while (cin >> s)
    {
        h = hs(s);
        word[h].s = s;
        ++word[h].x;
    }
    for (auto x:word)
        cout << x.second.s << ":" << x.second.x << endl;
    return 0;
}
