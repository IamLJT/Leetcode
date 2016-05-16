/*
题目：Additive Number 
要求：Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for 
the first two numbers, each subsequent number in the sequence must be the 
sum of the preceding two.

题目大意：对一个字符串判断其中的数字是否满足可加性序列，可加性序列是第三个
数等于前两个数字之和，字符串中的数字可以不只1位。

思路：因为一开始的两个字符串长度不可能超过从它起始的字符串长度的1/2，然后判断
每次的开始两个字符串加上剩余的字符串是否满足可加性序列的情况，如果满足则返回
true，如果不满足，则比较剩余的字符串中是否包含前两个字符串的和，如果包含则去掉
第一个字符串，再继续比较，否的话则返回false。
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool check(long num1, long num2, string num)
{
	if(num.size()>1 && num[0]=='0')
		return false;
	long sum = num1+num2, nums = stol(num);
	int len = log10(sum)+1;
	if(sum==nums) return true;
	if(sum>nums || sum!=stol(num.substr(0, len)))
		return false;
	else
		return check(num2, sum, num.substr(len));
}

bool isAdditiveNumber(string num)
{
	for(int i=1; i<=num.size()/2; i++)
	{
		for(int j=1; j<=(num.size()-i)/2; j++)
		{
			if(i>=2 && num[0]=='0' || j>=2 && num[i]=='0')
				continue;
			if(check(stol(num.substr(0, i)), stol(num.substr(i, j)), num.substr(i+j)))
				return true;
		}
	}
	return false;
}

int main()
{
	string num = "121125";
	if(isAdditiveNumber(num))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}