#include <iostream>
#include <math.h>
using namespace std;

int countDigitOne(int n)
{
	//	将每一位赋1，这一位左边的数+1乘以右边位数的最大值，
	//	因为数11算两次1出现，所以不用担心会重复。
	if(n<=0) return 0;
    int left = n;	
    int Right = 0;
	int Result = 0;
	int RightSize = 0;
	long num=n;
	while(left)
	{
		left/=10;
		Right=num%(long)pow(10,RightSize);
		if(n%10 > 1)	//	如果位上的值大于1，则赋1的话所有值都满足
		    Result+=(left+1)*pow(10,RightSize);
		if(n%10 == 1)	//	如果位上的值等于1，则左边小于left的值都满足，等于left的最大到右边的值
		    Result+=left*pow(10,RightSize)+Right+1;
		if(n%10 == 0)	//	如果为0，则左边小于left的值满足，其他不满足
		    Result+=left*pow(10,RightSize);
		n=left;
		RightSize++;
	}
	return Result;
}

int main()
{

}