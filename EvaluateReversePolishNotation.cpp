/*
��Ŀ��Evaluate Reverse Polish Notation
Ҫ��Evaluate the value of an arithmetic expression in 
Reverse Polish Notation. Valid operators are +, -, *, /. 
Each operand may be an integer or another expression.

��Ŀ���⣺�����沨�����ʽ��ֵ��

˼·������������ѹ���ջ�У�����������ջ�����Ϸ�������
���ֽ��������ٽ�ֵѹ���ջ�У�����ջ����ֻʣ��һ��ֵ��
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
bool isAllDigit(string s)
{
	for(int i=0; i<s.size(); i++)
	{
		if(!isdigit(s[i]))
			return false;
	}
	return true;
}

int s_to_int(string s)
{
	int sum=0;
	for(int i=0; i<s.size(); i++)
	{
		sum = sum*10 + s[i] - '0';
	}
	return sum;
}*/

int evalRPN(vector<string>& tokens)
{
	vector<int> res;
	int temp1, temp2;
	for(int i=0; i<tokens.size(); i++)
	{
		if(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-")
		{
		    temp1 = res[res.size()-1];
			res.pop_back();
			temp2 = res[res.size()-1];
			res.pop_back();
			if(tokens[i] == "*")
				res.push_back(temp2*temp1);
			if(tokens[i] == "/")
				res.push_back(temp2/temp1);
			if(tokens[i] == "+")
				res.push_back(temp2+temp1);
			if(tokens[i] == "-")
				res.push_back(temp2-temp1);
		}
		else
		{
		    res.push_back(atoi(tokens[i].c_str()));
		}
	}
	return res[0];
}

int main()
{
	string str[] = {"0","3","/"};
	vector<string> tokens(str, str+sizeof(str)/sizeof(string));
	cout << evalRPN(tokens) << endl;
	system("pause");
	return 0;
}