/*
题目：Missing Number
要求：Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

题目大意：从0-n中找出数组唯一缺少的一个数字

思路1：常规思路，先将数组排好序，再将每个数字与其所在的位置进行比较，如果不同则返回其位置，如果所有位置都相同则返回数组长度。

思路2：用异或运算符来比较，将所有的数字和所在的所有位置进行比较，由比较式A^B=B^A以及(A^B)^C=A^(B^C)可以发现，
A^C^B^A^C = A^A^C^C^B = B，因此所有的比较完毕后所留下来的即为缺少的值，若没有缺少的则返回的是初始的值，因为初始值给的是数组
长度，因此也满足原表达式。具体看源代码。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums)
{
	int res = nums.size();
	for(int i=0; i<nums.size(); i++)
	{
		res ^= nums[i];
		res ^= i;
	}
	return res;
}

int main()
{
	int num[] = {0, 1, 3};
	int x=-3;
	x &= -x;
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << missingNumber(nums) << endl;
	cout << x << endl;
	system("pause");
	return 0;
}
