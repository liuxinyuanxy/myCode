#undef __cplusplus
#define __cplusplus 2011038L
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    // cout << __cplusplus;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << hash<int>()(123);
    for (auto x : v)
        cout << x << " ";
}