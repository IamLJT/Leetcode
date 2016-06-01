#include <iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n) 
{
    int res=m, i=m, flag=0;
    for(; i<=n; i++)
    {
        if(i==0)
            return 0;
        res&=i;
        if(res%2==0)
        {
            res>>=1;
            i=i>>1;
            flag++;
            n>>=1;
        }
		if(i+1==INT_MIN)
			break;
    }
    return res<<flag;
}

int main()
{
	cout << rangeBitwiseAnd(2147483647,2147483647) << endl;
	system("pause");
	return 0;
}