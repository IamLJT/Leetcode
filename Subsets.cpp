/*
题目：Subsets
要求：Given a set of distinct integers, nums, return all possible subsets.
	  Note:
		  Elements in a subset must be in non-descending order.
		  The solution set must not contain duplicate subsets.

题目大意：给一系列的互不相同的数，返回其所有可能的子集，注意，子集中的元素
必须是非降序排列，并且子集不重复。

思路1：首先想到每一个数在子集中出现的概率都是1/2，因此总共应该有2^nums.size()
种，然后每个数字nums[i]后面能接的情况又是2^(nums.size()-i-1)种,最后再加入[]这
中情况，所以从最后面一个数开始，它之前的每个子集加上它可以变成它的所有子集。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>>  res;
	vector<int> temp;
	res.push_back(temp);
	for(int i=nums.size()-1; i>=0; i--)
	{
		temp.push_back(nums[i]);
		int n=res.size();
		for(int j=0; j<n; j++)
		{
			temp.insert(temp.end(), res[j].begin(), res[j].end());
			res.push_back(temp);
			temp.clear();
			temp.push_back(nums[i]);
		}
		temp.clear();
	}
	return res;
}

int main()
{
	vector<vector<int>> res;
	int num[] = {1, 2, 3};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	res = subsets(nums);
	for(int i=0; i<res.size(); i++)
	{
		cout << "[";
		if(res[i].size())
			cout << res[i][0];
		for(int j=1; j<res[i].size(); j++)
		{
			cout << "," << res[i][j];
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}