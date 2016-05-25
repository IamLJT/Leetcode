/*
题目：Isomorphic Strings
要求：Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced 
to get t. All occurrences of a character must be replaced with 
another character while preserving the order of characters. No 
two characters may map to the same character but a character may 
map to itself.

题目大意：判断两字符串是否同形。

思路：与字母模板题相似，找两个map结构存放每个字母的位置，在插入到
map前比较两个字母在map中的位置是否相同，如果相同，则继续比较，如果
不同则返回false。
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool isIsomorphic(string s, string t)
{
	if(s.size()!=t.size()) return false;
	map<char, int> s0, t0;
	for(int i=0; i<s.size(); i++)
	{
		if(s0[s[i]]!=t0[t[i]])
			return false;
		s0[s[i]]=t0[t[i]]=i+1;
	}
	return true;
}

int main()
{
	string s="add", t="egt";
	cout << isIsomorphic(s, t) << endl;
	system("pause");
	return 0;
}