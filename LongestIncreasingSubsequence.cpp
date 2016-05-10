/*
题目：Longest Increasing Subsequence
要求：Given an unsorted array of integers, find the length 
of longest increasing subsequence.

题目大意：找出一个序列中最长的递增子序列，返回该序列的长度

思路1：很容易想到的是O(n^2)的算法，外层遍历是从第一个值到最
后一个值，内层遍历是从外层遍历的值开始到最后一个值，遇到增
大的数则count++，最后返回最小的count。

思路2：建立一个新的数组用来存储已经遍历过的数字，它的长度代
表到目前状态下所找到的最长递增子序列的长度，每次遍历一个新
数据，找出它在新数组中位置，将其代替，若新数据比之前的数据
都大，则向新数组中添加入这个新数据，具体实现过程看代码。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	vector<int> res;
	for(int i=0; i<nums.size(); i++)
	{
		auto it = lower_bound(res.begin(), res.end(), nums[i]);
		//	lower_bound函数返回前闭后开区间内第一个大于等于nums[i]的位置，如果没有，则返回最后一个值
		if(it == res.end())
			res.push_back(nums[i]);
		else
			*it = nums[i];
	}
	return res.size();
}

int main()
{
	int num[] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << lengthOfLIS(nums) << endl;
	system("pause");
	return 0;
}