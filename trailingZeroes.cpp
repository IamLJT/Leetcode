#include <iostream>
using namespace std;
int trailingZeroes(int n)
{
	int num=0, sum=1;
	while(n)
	{
		sum*=n;
		if(!(sum%10))
		{
			sum/=10;
			num++;
		}
		n--;
	}
	return num;
}
int main()
{
	cout << trailingZeroes(10) << endl;
	system("pause");
	return 0;
}