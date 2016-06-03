/*
题目：Basic Calculator
要求：Implement a basic calculator to evaluate a simple expression 
string. The expression string may contain open ( and closing 
parentheses ), the plus + or minus sign -, non-negative integers 
and empty spaces . You may assume that the given expression is 
always valid.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int calculate(string s)
{
	string temp="";
	vector<int> v;
	vector<char> c;
	int k,a,b;
	stringstream ss;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			temp+=s[i];
		if(s[i]=='+'||s[i]=='-'||s[i]=='('||s[i]==')')
		{
			if(temp!="")
			{
				ss<<temp;
				ss>>k;
				v.push_back(k);
				ss.clear();
				temp="";
			}
			if(s[i]==')')
			{
				a=c.size()-1;
				b=v.size()-1;
				while(c[a]!='(')
				{
					a--;
					b--;
				}
				reverse(v.begin()+b, v.end());
				reverse(c.begin()+a+1, c.end());
				for(int j=c.size()-1; j>a; j--)
				{
					int v1=v.back();
					v.pop_back();
					int v2=v.back();
					v.pop_back();
					if(c[j]=='+') v.push_back(v1+v2);
					if(c[j]=='-') v.push_back(v1-v2);
					c.pop_back();
				}
				c.pop_back();
			}
			else
				c.push_back(s[i]);
		}
	}
	if(temp!="")
	{
		ss<<temp;
		ss>>k;
		v.push_back(k);
		ss.clear();
		temp="";
	}
	reverse(v.begin(), v.end());
	reverse(c.begin(), c.end());
	for(int i=c.size()-1; i>=0; i--)
	{
		int v1=v.back();
		v.pop_back();
		int v2=v.back();
		v.pop_back();
		if(c[i]=='+') v.push_back(v1+v2);
		if(c[i]=='-') v.push_back(v1-v2);
	}
	return v.back();
}

int main()
{
	string s="2-(5-6)";
	cout << calculate(s) << endl;
	system("pause");
	return 0;
}