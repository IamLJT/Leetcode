#include <iostream>
#include <string>
using namespace std;
int romanchartoint(char c)
{
	switch(c)
	{
	case 'I': return 1;		break;
	case 'V': return 5;		break;
	case 'X': return 10;	break;
	case 'L': return 50;	break;
	case 'C': return 100;	break;
	case 'D': return 500;	break;
	case 'M': return 1000;	break;
	default:  return 0;		break;
	}
}
int RomanToInt(string s) 
{
	for(int i = 0; i<s.size(); i++)
	{
		if(!romanchartoint(s[i]))
		{
			printf("ÊäÈë´íÎó£¡\n");
			return 0;
		}
	}
	int Result = romanchartoint(s[s.size()-1]);
	for(int i = s.size()-1; i>0; i--)
	{
		if(romanchartoint(s[i]) > romanchartoint(s[i-1]))
			Result -= romanchartoint(s[i-1]);
		else
			Result += romanchartoint(s[i-1]);
	}
	return Result;
}
int main()
{
	string s = "IIX";
	cout << "Result = " << RomanToInt(s) << endl;
	system("pause");
	return 0;
}