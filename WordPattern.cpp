/*
题目：Word Pattern
要求：Given a pattern and a string str, find if str follows the same 
pattern. Here follow means a full match, such that there is a bijection 
between a letter in pattern and a non-empty word in str.

题目大意：判断字符串组内的字符串是否按所给字母样式排布。

思路：首先用字符串数组将字符串按照顺序保存下来，然后用两个map分别记录
每一个字母和字符串对应的位置，每次插入前先比较两元素对应的位置是否相同，
如果不同则返回false，如果相同则继续更新他们的位置，知道比较到末尾处。
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void genestr(vector<string>& res, string str)
{
	if(str.size()==0) return;
	auto pos=str.c_str();
	while(*pos!=' '&&*pos!='\0')
		pos++;
	res.push_back(str.substr(0,pos-str.c_str()));
	if(*pos!='\0')
		genestr(res, str.substr(pos+1-str.c_str()));
}

bool wordPattern(string pattern, string str)
{
	vector<string> res;
	genestr(res, str);
	if(res.size()!=pattern.size()) return false;
	map<string, int> string0;
	map<char, int> letter;
	for(int i=0; i<res.size(); i++)
	{
		if(letter[pattern[i]]!=string0[res[i]])
			return false;
		letter[pattern[i]]=string0[res[i]]=i+1;
	}
	return true;
}

int main()
{
	string pattern="abbc";
	string str="dog cat cat dog";
	cout << wordPattern(pattern, str) << endl;
	system("pause");
	return 0;
}