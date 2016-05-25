/*
题目：Permutations II
要求：Given a collection of numbers that might contain duplicates, return all possible 
unique permutations.

题目大意：找出给的数字集合所有不相同的排序。

思路：首先排序，再从头开始遍历，只要不同位置上两数不相同则交换位置，继续递归去运算，则
可以将所有情况遍历到。具体看代码。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void uniquenum(vector<vector<int>>& res, vector<int> num, int begin, int end)
{
	if(begin==end-1) 
	{
		res.push_back(num);
		return ;
	}
	for(int i=begin; i<end; i++)
	{
		if(i!=begin&&num[i]==num[begin]) continue;
		swap(num[i], num[begin]);
		uniquenum(res, num, begin+1, end);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	uniquenum(res, nums, 0, nums.size());
	return res;
}

int main()
{
	int num[] = {1,2,3,4};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	vector<vector<int>> res=permuteUnique(nums);
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}