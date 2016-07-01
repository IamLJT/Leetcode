/*
题目：Longest Substring Without Repeating Characters
要求：Given a string, find the length of the longest substring without repeating characters.

大意：找出最长的没有重复字母出现的子串
思路：用一个数组存放每个字母的位置，并且设置一个起点位置，若发现了重复的字母，即数组中该字母
的位置又一次被索引到，则重新设置起点位置，并且记录此长度是否为当前长度的最大值。
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int lengthOfLongestSubstring(string s)
{
	//	之所以设置256的长度是因为可能有其他的字符，或者是大小写的
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