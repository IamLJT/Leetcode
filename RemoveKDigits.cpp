/*
题目：Remove K Digits
要求：Given a non-negative integer num represented as a string, remove k 
digits from the number so that the new number is the smallest possible.
*/

#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) 
{
    int min=INT_MAX,pos=0,temp=0;
    string res="";
    while(k&&res.size()<num.size()-k)
    {
        for(int i=pos;i<pos+k+1;i++)
        {
            if((int)(num[i]-'0')<min)
            {
                min=num[i]-'0';
                temp=i;
            }
        }
        if(res.size()||min)
            res+=(char)(min+'0');
        min=INT_MAX;
        k-=temp-pos;
        pos=temp+1;
    }
    for(int i=pos;i<num.size()&&res.size()<num.size()-k;i++)
        res+=num[i];
	if(res.size()==0) res+="0";
    return res;
}

int main()
{
	string str;
	int k;
	cin >> str >> k;
	cout << removeKdigits(str,k) << endl;
	system("pause");
	return 0;
}