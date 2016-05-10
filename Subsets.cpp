/*
��Ŀ��Subsets
Ҫ��Given a set of distinct integers, nums, return all possible subsets.
	  Note:
		  Elements in a subset must be in non-descending order.
		  The solution set must not contain duplicate subsets.

��Ŀ���⣺��һϵ�еĻ�����ͬ���������������п��ܵ��Ӽ���ע�⣬�Ӽ��е�Ԫ��
�����Ƿǽ������У������Ӽ����ظ���

˼·1�������뵽ÿһ�������Ӽ��г��ֵĸ��ʶ���1/2������ܹ�Ӧ����2^nums.size()
�֣�Ȼ��ÿ������nums[i]�����ܽӵ��������2^(nums.size()-i-1)��,����ټ���[]��
����������Դ������һ������ʼ����֮ǰ��ÿ���Ӽ����������Ա�����������Ӽ���
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