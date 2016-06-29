/*
��Ŀ��Largest Divisible Subset
Ҫ��Given a set of distinct positive integers, find the largest subset 
such that every pair (Si, Sj) of elements in this subset satisfies: 
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

��Ŀ���⣺�ҳ�������������ȡ��Ϊ0����������С�

˼·��������Ѱ�������������һ����ֻ������ǰ�������Ϊ�Ƿ������ˡ�ͬ����
��������������ֻ��Ҫ��һ����������ǰһ�������ɣ�Ȼ��ӵ�һ����ʼ��������
��֮��Ѱ������������������
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