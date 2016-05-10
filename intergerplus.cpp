#include <iostream>
#include <string>
#include "intergerplus.h"
using namespace std;
int str2int(char *a)
{
	int sum=0,i=0;
	while(a[i])
	{
		if((a[i]>='0')&&(a[i]<='9'))
			sum=sum*10+a[i]-'0';
		i++;
	}
	if(a[0]=='-')
		sum=-sum;
	return sum;
}
int main()
{
	char* input=(char*)malloc(100);
	int sum=0;string temp="";
	cout<<"Please input a string(num<100):";
	gets(input);
	while(input[0]!='#')
	{
		int length=strlen(input);
		for(int i=0;i<length;i++)
		{
			if((input[i]=='-')||((input[i]>='0')&&(input[i]<='9')))
				temp+=input[i];
			if((temp!="")&&(((input[i+1]<'0')||(input[i+1]>'9'))||(input[i+1]=='\0')))
			{
				sum+=str2int((char*)temp.data());
				temp="";
			}
		}
		cout<<sum<<endl;
		memset(input,0,strlen(input));
		sum=0;
		cout<<"(if don't want to continue, please input '#')"
			"\nPlease input a string(num<100):";
		gets(input);
	}
	return 0;
}