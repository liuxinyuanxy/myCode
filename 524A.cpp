#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long long n, k;
	long long a, b, c;
	scanf("%I64d%I64d", &n, &k);
	a = n * 2, b = n * 5, c = n * 8;
	printf("%I64d", (int)ceil(double(a) / k) + (int)ceil(double(b) / k) + (int)ceil(double(c) / k));
	return 0;
}