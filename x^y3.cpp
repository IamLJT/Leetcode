#include <iostream>
#include <String.h>
using namespace std;
int main()
{
	int x,y;
	cout<<"Please input x,y:";
	while(scanf("%d %d",&x,&y))
	{
		int sum=1;
		for(int i=0;i<y;i++)
		{
			if(sum>=1000)
				sum%=1000;
			else
				sum*=x;
		}
		if(sum>=1000)
			sum%=1000;
		cout<<"The last 3 num is: ";
		if(sum<100)
			cout<<"0"<<sum;
		else if(sum<10)
			cout<<"00"<<sum;
		else
			cout<<sum;
		cout<<"\nPlease input x,y:";
	}
	return 0;
}