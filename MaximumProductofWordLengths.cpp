/*
题目：Maximum Product of Word Lengths
要求：Given a string array words, find the maximum value of 
length(word[i]) * length(word[j]) where the two words do not 
share common letters. You may assume that each word will 
contain only lower case letters. If no such two words exist, 
return 0.

题目大意：给一个字符串数组，找出两个不包含相同字母的字符串
长度乘积的最大值，你可以假设所有字母都是小写，如果找不到，返
回0。

思路1：建立一个质数的数组，每个字母赋给一个质数，将第一个字符
串的所有字母对应的质数相乘，再去除第二个字符串的所有字母，如
能整除，说明有相同字母，舍去，如果都不能整除，说明没有，将他们
长度乘积保存下来，最终找出最大的乘积。（算法复杂度还是过高）

思路2：因为两两比较的过程少不了，而用质数乘积的形式比较是否有
重复字母也需要复杂度为O(k)的循环，所以不可取，那么可不可以把
比较重复字母的复杂度降为O(1)呢，答案是可以的，用质数乘积来找
子序列比较好，而本题只需比较出是否有1个重复的字母，那么只需在
第一次时记录下每个字母的位置，体现到二进制数上的位数，再与第
二个字母相与即可比较出。
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