/*
题目：Generate Parentheses
要求：Given n pairs of parentheses, write a function to 
generate all combinations of well-formed parentheses.

题目大意：产生n对有效的括号串，返回所有出现的情况。

思路：用一个变量标记还有多少个'('没有与之匹配，然后往每个
位置插入')'，并将变量-1，直到变量为0并且插入位置为2n-1，
停止并记录。
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(vector<string>& res, int n, int pair, int pos, string s)
{
	if(pos>2*n || pos+pair>2*n) return;
	if(pos==2*n && pair==0) res.push_back(s);
	if(pair)
		generate(res, n, pair-1, pos+1, s.substr(0,pos)+')'+s.substr(pos));
	generate(res, n, pair+1, pos+1, s);
}

vector<string> generateParenthesis(int n) 
{
	vector<string> res;
	string s="";
	for(int i=0; i<n; i++)
		s += '(';
	generate(res, n, 0, 0, s);
	return res;
}

int main()
{
	vector<string> res=generateParenthesis(3);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}