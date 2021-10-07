#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#define mid(l, r) ((l + r) >> 1)

namespace init
{
    template <class T>
    void rd(T& s)
    {
        s = 0;
        bool p = 0;
        char ch;
        while (ch = getchar(), p |= ch == '-', ch < '0' || ch > '9')
            ;
        while (s = s * 10 + ch - '0', ch = getchar(), ch >= '0' && ch <= '9')
            ;
        s *= (p ? -1 : 1);
    }
    char rdch_int()
    {
        char ch;
        while (ch = getchar(), ch < '0' || ch > '9');
        return ch;
    }
    char rdch_char()
    {
        char ch;
        while (ch = getchar(), !isalpha(ch));
        return ch;
    }
} // init

namespace SORT
{
    #define N 100005
    void bubbleSort(int* a, int n)
    {
        for (int i = 1; i < n; ++i)
            for (int j = n - 1; j >= i; --j)
                if (a[j] > a[j + 1])
                    std::swap(a[j], a[j + 1]);
    }
    void selectionSort(int* a, int n)
    {
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (a[i] > a[j])
                    std::swap(a[i], a[j]);
    }
	void insertSort(int* a, int n)
	{
		std::vector<int> v;
		v.push_back(a[1]);
		for (int i = 2; i <= n; ++i)
			v.insert(std::lower_bound(v.begin(), v.end(), a[i]), a[i]);
		for (int i = 1; i <= n; ++i)
			a[i] = v[i - 1];
	}
    void mergeSort(int* a, int n, int l, int r)
    {
        int b[N];
        if (l == r)
            return;
        int m = mid(l, r);
        mergeSort(a, n, l, m);
        mergeSort(a, n, m + 1, r);
        int l1 = l, r1 = m + 1, l2 = m + 1, r2 = r + 1, p = l;
        while (l1 < r1 && l2 < r2)
            if (a[l1] <= a[l2])
                b[p++] = a[l1++];
            else
                b[p++] = a[l2++];
        while (l1 < r1)
            b[p++] = a[l1++];
        while (l2 < r2)
            b[p++] = a[l2++];
        for (int i = l; i <= r; ++i)
            a[i] = b[i];
    }
    void quickSort(int* a, int n, int l, int r)
    {
        int x = l, y = r, m = a[mid(l, r)];
        do
        {
            while (a[l] < m)
                ++l;
            while (a[r] > m)
                --r;
            if (l <= r)
                std::swap(a[l++], a[r--]);
        } while (l <= r);
        if (l < y)
            quickSort(a, n, l, y);
        if (r > x)
            quickSort(a, n, x, r);
    }
} // SORT

int n, a[100005];
int main()
{
    // freopen("in.txt", "r", stdin);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    SORT::insertSort(a, n);
    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << " ";
}