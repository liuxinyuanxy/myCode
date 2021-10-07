#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <cmath>
using namespace std;
int main()
{
    double x = 1.0 / 10;
    double y = 0;
    for (int i = 1; i <= 10; ++i)
        y += x;
    printf("%.15f\n", y);
    x = 1.0 / 333;
    y = 0;
    for (int i = 1; i <= 333; ++i)
        y += x;
    printf("%.15f\n", y);

    cout << "largest int : " << INT_MAX << endl;
    cout << "smallest int : " << numeric_limits<int> :: min() << endl;

    if (numeric_limits<char>::is_signed)
        cout << "char is signed\n";
    else
        cout << "char is unsigned\n";
    return 0;
}
