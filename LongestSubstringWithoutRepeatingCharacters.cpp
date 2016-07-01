/*
��Ŀ��Longest Substring Without Repeating Characters
Ҫ��Given a string, find the length of the longest substring without repeating characters.

���⣺�ҳ����û���ظ���ĸ���ֵ��Ӵ�
˼·����һ��������ÿ����ĸ��λ�ã���������һ�����λ�ã����������ظ�����ĸ���������и���ĸ
��λ����һ�α����������������������λ�ã����Ҽ�¼�˳����Ƿ�Ϊ��ǰ���ȵ����ֵ��
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	//	֮��������256�ĳ�������Ϊ�������������ַ��������Ǵ�Сд��
	vector<int> dict(256, -1);
	int maxLen=0, start=-1;
	for(int i=0; i<s.size(); i++)
	{
		if(dict[s[i]]>start)
			start=dict[s[i]];
		dict[s[i]]=i;
		maxLen=max(maxLen, i-start);
	}
	return maxLen;
}

int main()
{
	cout << lengthOfLongestSubstring("adssabxd") << endl;
	system("pause");
	return 0;
}