/*
��Ŀ��Remove Duplicate Letters
Ҫ��Given a string which contains only lowercase letters, 
remove duplicate letters so that every letter appear once 
and only once. You must make sure your result is the smallest 
in lexicographical order among all possible results.

��Ŀ���⣺��һ��ֻ����Сд��ĸ���ַ����������Ƴ����ظ�����ĸ��
���ұ�֤��Ľ���ǰ���ĸ��˳������С���еġ�

˼·1������ĸ���д�������Ѱ������ߵ���С��ĸ����ֻ����1�ε���
ĸ���ҵ���ֹͣ�����뵽������ַ����У��������и���ĸ������ĸ��
�ߵ�������ĸ���ַ������޳������ظ����д˲�����ֱ���ַ�����û��
ʣ����ĸ��
*/

#include <iostream>
#include <string>
using namespace std;

string removeDuplicateLetters(string s) 
{
	string res;
	int numchar[26], pos;
	while(s.size())
	{
		pos=0;
		memset(numchar, 0, 26*sizeof(int));
		for(int i=0; i<s.size(); i++)
			numchar[s[i]-'a']++;
		for(int i=0; i<s.size(); i++)
		{
			if(s[pos]>s[i]) pos=i;
			if(--numchar[s[i]-'a']==0) break;
		}
		res+=s[pos];
		for(int i=pos+1; i<s.size();)
		{
			if(s[i]==s[pos])
			{
				s=s.replace(i,1,"");
				continue;
			}
			i++;
		}
		s = s.substr(pos+1);
	}
	return res;
}

int main()
{
	string str="thesqtitxyetpxloeevdeqifkz";
	cout << removeDuplicateLetters(str) << endl;
	system("pause");
	return 0;
}