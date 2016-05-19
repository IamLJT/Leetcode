/*
��Ŀ��Generate Parentheses
Ҫ��Given n pairs of parentheses, write a function to 
generate all combinations of well-formed parentheses.

��Ŀ���⣺����n����Ч�����Ŵ����������г��ֵ������

˼·����һ��������ǻ��ж��ٸ�'('û����֮ƥ�䣬Ȼ����ÿ��
λ�ò���')'����������-1��ֱ������Ϊ0���Ҳ���λ��Ϊ2n-1��
ֹͣ����¼��
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