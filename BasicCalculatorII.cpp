/*
题目：Basic Calculator II
要求：Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / 
operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int calculate(string s)
{
	string temp="";
	int k;
	stringstream ss;
	vector<int> v;
	vector<char> c;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			temp+=s[i];
		
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			ss<<temp;
			ss>>k;
			v.push_back(k);
			ss.clear();
			temp="";
			if(c.size()&&(c.back()=='*'||c.back()=='/'))
			{
				int v1=v.back();
				v.pop_back();
				int v2=v.back();
				v.pop_back();
				if(c.back()=='*')
					v.push_back(v2*v1);
				else
					v.push_back(v2/v1);
				c.pop_back();
			}
			c.push_back(s[i]);
		}
	}
	ss<<temp;
	ss>>k;
	v.push_back(k);
	ss.clear();
	temp="";
	if(c.size()&&(c.back()=='*'||c.back()=='/'))
	{
		int v1=v.back();
		v.pop_back();
		int v2=v.back();
		v.pop_back();
		if(c.back()=='*')
			v.push_back(v2*v1);
		else
			v.push_back(v2/v1);
		c.pop_back();
	}
	reverse(v.begin(), v.end());
	reverse(c.begin(), c.end());
	for(int i=c.size()-1; i>=0; i--)
	{
		int v2=v.back();
		v.pop_back();
		int v1=v.back();
		v.pop_back();
		if(c[i]=='-') v.push_back(v2-v1);
		if(c[i]=='+') v.push_back(v2+v1);
		if(c[i]=='/') v.push_back(v2/v1);
		if(c[i]=='*') v.push_back(v2*v1);
	}
	return v.back();
}

int main()
{
	string s="5";
	cout << calculate(s) << endl;
	system("pause");
	return 0;
}