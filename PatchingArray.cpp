/*
题目：Patching Array 
Given a sorted positive integer array nums and an integer n, 
add/patch elements to the array such that any number in range 
[1, n] inclusive can be formed by the sum of some elements 
in the array. Return the minimum number of patches required.

题目大意：给定一个数组nums和一个数n，求添加最少的数使得区间
[1, n]中的每个数都可以由数组nums中元素累加组成。

思路：首先定义一个整形变量top，假设数组nums目前可以累加的数
的范围为[1,top]，如果向数组中添加元素k（k<=top）可以将累加的
数的范围扩充到[1,top+k]，而题目中要求向数组nums添加元素的个
数最少，因此当且仅当k=top时，累加数的范围可以取到上限[1,2*top]。
因此，在遍历数组nums时，有两种操作：当数组中有小于等于top的
数，则使用数组中的元素，同时top+=nums[index]；若没有，则添加
新元素top到数组中，即添加数+1，同时令top=2*top。
*/
#include <iostream>
#include <vector>
using namespace std;
int minPatches(vector<int>& nums, int n)
{
	int index = 0, count = 0;
    long long top = 1;
    while(top <= n)
    {
    	if(index<nums.size() && nums[index]<=top)
    	{
    		top += nums[index++];
    	}
    	else
    	{
    		count++;
    		top = 2*top;
    	}
    }
    return count;
}
int main()
{
	int num[] = {1,5,10};
	vector<int> nums(num,num+3);
	cout << minPatches(nums,20) << endl;
	system("pause");
	return 0;
}