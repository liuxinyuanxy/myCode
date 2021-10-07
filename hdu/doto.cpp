#include<iostream>
#include<cstdio>
#define re register
#define int long long
#define _ 25
using namespace std;
long long input1,input2,input3;
int dp[_][_][_];
int w(re int a,re int b,re int c)
{
	if (dp[a][b][c] != -1)
		return dp[a][b][c];
	if(a<=0||b<=0||c<=0)return dp[a][b][c] = 1;
    if(a>20||b>20||c>20)return dp[a][b][c] = w(20,20,20);
    if(a<b&&b<c)return dp[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return dp[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
signed main()
{
	for (re int i = 0; i < _; ++i)
		for (re int j = 0; j < _; ++j)
			for (re int k = 0; k < _; ++k)
				dp[i][j][k] = -1;
	for(;;)
    {
        cin>>input1>>input2>>input3;
        if(input1==-1&&input2==-1&&input3==-1)
        {
            break;
        }
        cout<<"w("<<input1<<", "<<input2<<", "<<input3<<") = "\
		((input1 <= 0 || input2 <= 0 || input3 <= 0) ? 1 : \
		(input1 > 20 || input2 > 20 || input3 > 20 ? w(20, 20, 20) : (w(input1,input2,input3)))) \
		<< endl;
    }
}