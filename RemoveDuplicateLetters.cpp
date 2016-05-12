/*
题目：Remove Duplicate Letters
要求：Given a string which contains only lowercase letters, 
remove duplicate letters so that every letter appear once 
and only once. You must make sure your result is the smallest 
in lexicographical order among all possible results.

题目大意：给一个只包含小写字母的字符串，从中移除掉重复的字母，
并且保证你的结果是按字母表顺序中最小排列的。

思路1：从字母串中从左至右寻找最左边的最小字母或是只出现1次的字
母，找到则停止，加入到输出的字符串中，并将所有该字母及该字母左
边的所有字母从字符串中剔除，再重复进行此操作，直到字符串中没有
剩余字母。
*/

#include <iostream>
#include <string>
using namespace std;

string removeDuplicateLetters(string s) 
{
	string res;
	int numchar[26], pos;
	while(s.size())
	{
		pos=0;
		memset(numchar, 0, 26*sizeof(int));
		for(int i=0; i<s.size(); i++)
			numchar[s[i]-'a']++;
		for(int i=0; i<s.size(); i++)
		{
			if(s[pos]>s[i]) pos=i;
			if(--numchar[s[i]-'a']==0) break;
		}
		res+=s[pos];
		for(int i=pos+1; i<s.size();)
		{
			if(s[i]==s[pos])
			{
				s=s.replace(i,1,"");
				continue;
			}
			i++;
		}
		s = s.substr(pos+1);
	}
	return res;
}

int main()
{
	string str="thesqtitxyetpxloeevdeqifkz";
	cout << removeDuplicateLetters(str) << endl;
	system("pause");
	return 0;
}