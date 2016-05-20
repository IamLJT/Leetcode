/*
题目：Letter Combinations of a Phone Number
要求：Given a digit string, return all possible letter combinations 
that the number could represent. A mapping of digit to letters (just 
like on the telephone buttons) is given below.

题目大意：给一个数字串，返回所有可能的字母组合，字母是按电话机上的
字母分布的。

思路：利用递归的思路，索引所有可能出现的情况。
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void combine(vector<string>& res, const vector<string> table, const string& digits, int index, string s)
{
	if(index == digits.size())
		res.push_back(s);
	else
	{
		for(int i=0; i<table[digits[index]-'0'].size(); i++)
		{
			s.push_back(table[digits[index]-'0'][i]);
			combine(res, table, digits, index+1, s);
			s.pop_back();
		}
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> res;
	if(digits.size()==0) return res;
	string table0[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> table(table0, table0+10);
	combine(res, table, digits, 0, "");
	return res;
}

int main()
{
	string digits="234";
	vector<string> res=letterCombinations(digits);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}