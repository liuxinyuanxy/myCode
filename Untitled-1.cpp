#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int main()
{
	string file = "C:\\Users\\Dell\\Desktop\\data\\vinci\\vinci3";
    int p = 3;
    for (int i = 0; i <= 5; ++i)
    {
        string in = file + (char)(i + '0') + ".in";
        string out = file + (char)(i + '0') + ".out";
        ofstream ofs1(in);
	    ofstream ofs2(out);
        ofs1 << p * 10 + i << endl;
        ofs2 << a[p * 10 + i] << endl;
        ofs1.close();
        ofs2.close();
    }
	// main();
}