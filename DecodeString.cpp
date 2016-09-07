/*
题目：Decode String
要求：Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square 
brackets is being repeated exactly k times. Note that k is guaranteed to be a positive 
integer.
You may assume that the input string is always valid; No extra white spaces, square 
brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and 
that digits are only for those repeat numbers, k. For example, there won't be input 
like 3a or 2[4].
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string decodeString(string s) 
{
	string res="",num="";
	vector<int> temp, num0; //	分别记录[的位置和[前面的数字
	stringstream ss;
	ss.clear();
	int numtemp;
	for(int i=0; i<(int)s.size(); i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			ss << s[i];
		}
		else if(s[i]=='[')
		{
			ss >> numtemp;
			ss.clear();
			num0.push_back(numtemp);
			temp.push_back(res.size()-1);
		}
		else if(s[i]==']')
		{
			string s=res.substr(temp.back()+1,res.size());
			for(int i=num0.back(); i>1; i--)
			{
				res+=s;
			}
			num0.pop_back();
			temp.pop_back();
		}
		else
			res+=s[i];
	}
	return res;
}

int main()
{
	string str="3[a2[c]]";
	cout << decodeString(str) << endl;
	system("pause");
	return 0;
}