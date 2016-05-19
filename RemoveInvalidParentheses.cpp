/*
��Ŀ��Remove Invalid Parentheses
Ҫ��Remove the minimum number of invalid parentheses in 
order to make the input string valid. Return all possible 
results.
Note: The input string may contain letters other than the 
parentheses ( and ).

��Ŀ���⣺��ȥ���ٵ���Ч����ʹ���ַ���������˳������Ч��
�������п��ܵĽ����

˼·�������ҳ���Ҫɾ���ķ��ż��������дһ���ж��ַ����Ƿ�
��Ч�ĺ�����˳���ҹ�ȥ��û����Ҫɾ���ķ��ţ���ɾ����������
û����Ҫɾ���ķ���ʱ���жϴ�ʱ�ַ����Ƿ���Ч������Ч����
�棬�����������ң�ֱ�������ַ���β����

˼·���꣺���Բ���Ҫ�ж��ַ�����Ч�ĺ�������Ϊֻ��Ҫһ����
��ȥ��¼��ǰ�ж��ٸ�δ�ɶԵ�'('���ɡ�
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