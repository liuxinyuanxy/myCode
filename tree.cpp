#include <iostream>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define pii std::pair<int, int>
#define il inline
#define rt register int
#define re register
#define rc re char
#define gc getchar
__gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbt;
int main()
{
	int n, p;
	char opt;
	scanf ("%d", &n);
	while (n--)
	{
		scanf (" %c%d", &opt, &p);
		switch(opt)
		{
			case 'I' : bbt.insert(p); break;
			case 'D' : bbt.erase(p); break;
			case 'K' : p > bbt.size() ? puts("invalid") : printf("%d\n", *bbt.find_by_order(p - 1)); break;
			case 'C' : printf("%d\n", bbt.order_of_key(p)); break;
		}
	}
	return 0;
}