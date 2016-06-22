/*
题目：Multiply Strings
要求：Given two numbers represented as strings, return multiplication of the numbers as a string.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addstring(string s1, string s2)
{
    string s;
    int e=0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(!s1.size()&&!s2.size()) return s;
    int len=s1.size()>s2.size()?s1.size():s2.size();
    for(int i=0; i<len; i++)
    {
        if(i>=s1.size())
        {
            s+=(s2[i]-'0'+e)%10+'0';
            e=(s2[i]-'0'+e)/10;
        }
        else if(i>=s2.size())
        {
            s+=(s1[i]-'0'+e)%10+'0';
            e=(s1[i]-'0'+e)/10;
        }
        else
        {
            s+=((int)(s1[i]-'0')+(int)(s2[i]-'0')+e)%10+'0';
            e=((int)(s1[i]-'0')+(int)(s2[i]-'0')+e)/10;
        }
    }
    if(e!=0)
        s+=e+'0';
    reverse(s.begin(), s.end());
    return s;
}
string multistr(char c, string s0, int k)
{
    string s;
    reverse(s0.begin(), s0.end());
    int e=0;
    for(int i=0; i<s0.size(); i++)
    {
        s+=((s0[i]-'0')*(c-'0')+e)%10+'0';
        e=((s0[i]-'0')*(c-'0')+e)/10;
    }
    if(e!=0)
        s+=e+'0';
    reverse(s.begin(), s.end());
	for(int j=0; j<k; j++)
		s+='0';
    return s;
}
string adds(vector<string> num)
{
    while(num.size()>1)
    {
        string s1=num.back();
        num.pop_back();
        string s2=num.back();
        num.pop_back();
        num.push_back(addstring(s1,s2));
    }
    return num.back();
}
string multiply(string num1, string num2) {
    vector<string> num;
    if(!num1.size()||!num2.size()) return "";
    if(num1=="0"||num2=="0") return "0";
    for(int i=num1.size()-1; i>=0; i--)
        num.push_back(multistr(num1[i],num2, num1.size()-1-i));
    return adds(num);
}
string multiply(string num1, string num2) {
    vector<string> num;
    for(int i=num1.size()-1; i>=0; i--)
        num.push_back(multistr(num1[i],num2, num1.size()-1-i));
    return adds(num);
}

int main()
{
	cout << multiply("125", "234") << endl;
	system("pause");
	return 0;
}