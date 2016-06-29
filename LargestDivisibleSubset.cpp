/*
题目：Largest Divisible Subset
要求：Given a set of distinct positive integers, find the largest subset 
such that every pair (Si, Sj) of elements in this subset satisfies: 
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

题目大意：找出最大的满足两数取余为0的最大子序列。

思路：类似于寻找最长递增子序列一样，只是这次是把条件换为是否整除了。同样，
可以先排序，这样只需要后一个数能整除前一个数即可，然后从第一个开始遍历，在
它之后寻找能满足条件的数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> largestDivisibleSubset(vector<int>& nums)
{
	vector<int> res, dp(nums.size(), 0), parent(nums.size(), 0);
	sort(nums.begin(), nums.end());
	if(nums.empty()) return res;
	int m=0, mi=0;
	for(int i=nums.size()-1; i>=0; i--)
	{
		for(int j=i; j<nums.size(); j++)
		{
			if(nums[j]%nums[i]==0 && dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				parent[i]=j;

				if(dp[i]>m)
				{
					m = dp[i];
					mi = i;
				}
			}
		}
	}

	for(int i=0; i<m; i++)
	{
		res.push_back(nums[mi]);
		mi = parent[mi];
	}

	return res;
}

int main()
{
	int num[] = {6, 12, 1, 2, 3, 4, 6, 8};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	vector<int> res=largestDivisibleSubset(nums);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}