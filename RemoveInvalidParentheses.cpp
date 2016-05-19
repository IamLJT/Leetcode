/*
题目：Remove Invalid Parentheses
要求：Remove the minimum number of invalid parentheses in 
order to make the input string valid. Return all possible 
results.
Note: The input string may contain letters other than the 
parentheses ( and ).

题目大意：移去最少的无效括号使得字符串的括号顺序变得有效，
返回所有可能的结果。

思路：首先找出需要删除的符号及其个数，写一个判断字符串是否
有效的函数，顺序找过去有没有需要删除的符号，则删除继续，当
没有需要删除的符号时，判断此时字符串是否有效，若有效，则保
存，并继续往下找，直到到达字符串尾部。

思路引申：可以不需要判断字符串有效的函数，因为只需要一个变
量去记录此前有多少个未成对的'('即可。
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool isValid(string s)
{
	vector<char> temp;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] == '(')
			temp.push_back('(');
		if(s[i] == ')')
		{
			if(temp.size())
				temp.pop_back();
			else
				return false;
		}
	}
	if(temp.size()) return false;
	return true;
}

void remove(unordered_set<string>& res, int index, int left, int right, string s)
{
	if(index>s.size()) return;
	if(index == s.size() && left==0 && right==0 && isValid(s))
		res.insert(s);
	if(left && s[index]=='(')
		remove(res, index, left-1, right, s.substr(0, index)+s.substr(index+1));
	if(right && s[index]==')')
		remove(res, index, left, right-1, s.substr(0, index)+s.substr(index+1));
	remove(res, index+1, left, right, s);
}

vector<string> removeInvalidParentheses(string s)
{
	unordered_set<string> res;
	int left=0, right=0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='(')
			left++;
		if(s[i]==')')
		{
			if(left) left--;
			else right++;
		}
	}
	remove(res, 0, left, right, s);
	return vector<string>(res.begin(), res.end());
}

int main()
{
	string s="(a)())()";
	vector<string> res=removeInvalidParentheses(s);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}