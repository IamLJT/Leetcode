/*
题目：Convert a Number to Hexadecimal
要求：Given an integer, write an algorithm to convert it to hexadecimal. 
For negative integer, two’s complement method is used.
Note:
1.All letters in hexadecimal (a-f) must be in lowercase.
2.The hexadecimal string must not contain extra leading 0s. If the number is 
zero, it is represented by a single zero character '0'; otherwise, the first 
character in the hexadecimal string will not be the zero character.
3.The given number is guaranteed to fit within the range of a 32-bit signed integer.
4.You must not use any method provided by the library which converts/formats 
the number to hex directly.
*/

#include <iostream>
#include <string>
using namespace std;

string toHex(int num)
{
	string res="";
    int flag=0;
    if(num<0)
    {
    	num=INT_MAX+num+1;
    	flag=1;
    }
    if(flag==1)
    {
        for(int i=0;i<8;i++)
        {
            int t=num%16;
            if(i==7)
                t+=8;
            if(t>=10) 
                res=(char)('a'+(t-10))+res;
        	else
        		res=(char)('0'+t)+res;
        	num/=16;
        }
    }
    while(num&&flag==0)
    {
    	int t=num%16;
    	if(num/16==0&&flag==1)
    		t+=8;
    	if(t>=10) res=(char)('a'+(t-10))+res;
    	else
    		res=(char)('0'+t)+res;
    	num/=16;
    }
    if(res.size()==0) res+='0';
    return res;
}

int main()
{
	int num=INT_MIN;
	cout << toHex(num) << endl;
	system("pause");
	return 0;
}