#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> node;
queue<int> q;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(false);
    int n, temp;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        a[i] = temp;
        q.push(temp);
        pq.push(temp);
        node.push_back(temp);
    }
    for (auto x:node)
        cout << x << endl;
        cout << endl;

    sort(a, a + n);
    for (auto x:a)
        cout << x << endl;
        cout << endl;

    for (auto& x:node)
        ++x;
    for (auto x:node)
        cout << x << endl;
        cout << endl;

    sort(node.begin(), node.end());
    for (auto x:node)
        cout << x << endl;
        cout << endl;

    return 0;
}
