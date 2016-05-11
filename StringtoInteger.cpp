/*
题目：String to Integer (atoi) 
要求：Implement atoi to convert a string to an integer.
*/

#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str) 
{
    int res=0, flag=1, i=0, count=0;
	long long res0=0;
    while(str[i++]==' ');
    string str0 = str.substr(i-1);        
    for(i=0; i<str0.size(); i++)
    {
        if(i==0 && str0[i]=='+')
            continue;
        if(i==0 && str0[i]=='-')
        {
            flag=-flag;
            continue;
        }
        if(str0[i]<'0' || str0[i]>'9')
            break;
        res0 = res0*10 + str0[i] - '0'; 
		
		if(flag==1 && res0>=INT_MAX) 
			return INT_MAX;
		if(flag==-1 && res0*flag<=INT_MIN) 
			return INT_MIN;
    }
    return (int)res0*flag;
}

int main()
{
	string str("2147483648");
	cout << myAtoi(str) << endl;
	system("pause");
	return 0;
}