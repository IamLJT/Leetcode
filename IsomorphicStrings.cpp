/*
��Ŀ��Isomorphic Strings
Ҫ��Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced 
to get t. All occurrences of a character must be replaced with 
another character while preserving the order of characters. No 
two characters may map to the same character but a character may 
map to itself.

��Ŀ���⣺�ж����ַ����Ƿ�ͬ�Ρ�

˼·������ĸģ�������ƣ�������map�ṹ���ÿ����ĸ��λ�ã��ڲ��뵽
mapǰ�Ƚ�������ĸ��map�е�λ���Ƿ���ͬ�������ͬ��������Ƚϣ����
��ͬ�򷵻�false��
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