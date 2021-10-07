#include <iostream>
#include <cstdio>
using namespace std;
int head = 1000001, tail = 1000000, q[5000000];
int main()
{
    char c1, c2;
    int k, tot = 0;
    int s;
    cin >> s;
    for (int i = 1; i <= s; ++i)
    {
        cin >> c1 >> c2;
        if (c1 == 'A')
        {
            ++tot;
            if (c2 == 'L')
            {
                q[--head] = tot;
            }
            else
            {
                q[++tail] = tot;
            }
        }
        else
        {
            cin >> k;
            if (c2 == 'L')
                head += k;
            else
                tail -= k;
        }
    }
    for (int i = head; i <= tail; ++i)
        cout << q[i] << "\n";
    return 0;
}
