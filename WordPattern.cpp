/*
��Ŀ��Word Pattern
Ҫ��Given a pattern and a string str, find if str follows the same 
pattern. Here follow means a full match, such that there is a bijection 
between a letter in pattern and a non-empty word in str.

��Ŀ���⣺�ж��ַ������ڵ��ַ����Ƿ�������ĸ��ʽ�Ų���

˼·���������ַ������齫�ַ�������˳�򱣴�������Ȼ��������map�ֱ��¼
ÿһ����ĸ���ַ�����Ӧ��λ�ã�ÿ�β���ǰ�ȱȽ���Ԫ�ض�Ӧ��λ���Ƿ���ͬ��
�����ͬ�򷵻�false�������ͬ������������ǵ�λ�ã�֪���Ƚϵ�ĩβ����
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