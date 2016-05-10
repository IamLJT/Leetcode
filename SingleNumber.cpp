/*
题目：Single Number
要求：Given an array of numbers nums, in which exactly two elements appear only 
once and all the other elements appear exactly twice. Find the two elements that
appear only once.

题目大意：一串数字，只有两个元素出现1次，其他元素都出现了两次，找出这两个元素。

思路：将所有数字进行异或运算，则得到的结果即为两个只出现1次的数字的异或，因为
它们不相同，所有一定他们的异或运算后对应的二进制内一定包含了1，取最右边出现的
1，那么这个1一定出现在其中1个数中，而另外一个数是不包含这个1的，因此将这些数
分为两半，一半是包含这个1的，一半不包含，分别进行异或运算后即为这两个数。
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums)
{
	int temp=0;
	vector<int> res(2, 0);
	for(int i=0; i<nums.size(); i++)
		temp ^= nums[i];
	temp &= -temp;		//	得到最右边1的位置
	for(int i=0; i<nums.size(); i++)
	{
		if(nums[i]&temp)
			res[0] ^= nums[i];
		else
			res[1] ^= nums[i];
	}
	return res;
}

int main()
{
	int num[] = {1, 2, 1, 3, 2, 5};
	vector<int> nums(num, num+sizeof(num)/sizeof(int)), res;
	res = singleNumber(nums);
	cout << res[0] << " " << res[1] << endl;
	system("pause");
	return 0;
}
