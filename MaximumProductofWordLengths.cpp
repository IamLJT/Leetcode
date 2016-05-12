/*
��Ŀ��Maximum Product of Word Lengths
Ҫ��Given a string array words, find the maximum value of 
length(word[i]) * length(word[j]) where the two words do not 
share common letters. You may assume that each word will 
contain only lower case letters. If no such two words exist, 
return 0.

��Ŀ���⣺��һ���ַ������飬�ҳ�������������ͬ��ĸ���ַ���
���ȳ˻������ֵ������Լ���������ĸ����Сд������Ҳ�������
��0��

˼·1������һ�����������飬ÿ����ĸ����һ������������һ���ַ�
����������ĸ��Ӧ��������ˣ���ȥ���ڶ����ַ�����������ĸ����
��������˵������ͬ��ĸ����ȥ�����������������˵��û�У�������
���ȳ˻����������������ҳ����ĳ˻������㷨���ӶȻ��ǹ��ߣ�

˼·2����Ϊ�����ȽϵĹ����ٲ��ˣ����������˻�����ʽ�Ƚ��Ƿ���
�ظ���ĸҲ��Ҫ���Ӷ�ΪO(k)��ѭ�������Բ���ȡ����ô�ɲ����԰�
�Ƚ��ظ���ĸ�ĸ��ӶȽ�ΪO(1)�أ����ǿ��Եģ��������˻�����
�����бȽϺã�������ֻ��Ƚϳ��Ƿ���1���ظ�����ĸ����ôֻ����
��һ��ʱ��¼��ÿ����ĸ��λ�ã����ֵ����������ϵ�λ���������
������ĸ���뼴�ɱȽϳ���
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
int nums[] = {2, 3, 5, 7, 11,
			13, 17, 19, 23, 29, 
			31, 37, 41, 43, 47, 
			53, 57, 59, 61, 67,
			71, 73, 79, 83, 89, 91};

bool isinclude(string a, string b)
{
	long long sum=1;
	for(int i=0; i<a.size(); i++)
		sum *= nums[a[i]-'a'];
	for(int i=0; i<b.size(); i++)
		if(!(sum%nums[b[i]-'a']))
			return true;
	return false;
}

int maxProduct(vector<string>& words)
{
	int res=0;
	for(int i=0; i<words.size(); i++)
	{
		for(int j=i; j<words.size(); j++)
		{
			if(!isinclude(words[i], words[j]) && 
				words[i].size()*words[j].size()>res)
				res = words[i].size()*words[j].size();
		}
	}
	return res;
}
*/

int maxProduct(vector<string>& words)
{
	int res=0;
	vector<int> word(words.size(), 0);
	for(int i=0; i<words.size(); i++)
		for(int j=0; j<words[i].size(); j++)
			word[i] |= 1<<(words[i][j]-'a');
	for(int i=0; i<words.size(); i++)
		for(int j=i; j<words.size(); j++)
			if(!(word[i] & word[j]) && (words[i].size()*words[j].size()>res))
				res=words[i].size()*words[j].size();
	return res;
}

int main()
{
	string word[]={"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	vector<string> words(word, word+sizeof(word)/sizeof(string));
	cout << maxProduct(words) << endl;
	system("pause");
	return 0;
}