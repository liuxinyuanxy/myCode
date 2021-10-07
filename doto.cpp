#include <iostream>
#include <cstdio>
int f(int a, int t)
{
	if (a == 1)
		return 1;
	int ans = 0;
	for (int i = t; i >= 2; --i)
		if (a % i == 0)
			ans += f(a / i, i);
	return ans;
}
int main()
{
	int a, n;
	std::cin >> n;
	while (n--)
	{
		std::cin >> a;
		std::cout << f(a, a) << std::endl;
	}
	return 0;
}