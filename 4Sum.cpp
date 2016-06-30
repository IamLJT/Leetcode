/*
��Ŀ��4Sum
Ҫ��Given an array S of n integers, are there elements a, b, c, and d in 
S such that a + b + c + d = target? Find all unique quadruplets in the array 
which gives the sum of target.

���⣺�ҳ��������������ĸ���֮�͵���Ŀ��ֵ��������ϡ�
˼·��ͬ��������ͬ��ֻ�Ǹ��Ӷ�ΪO(n^3)��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	int n=nums.size();
	if(n<4) return res;
	sort(nums.begin(), nums.end());

	for(int i=0; i<nums.size(); i++)
	{
		// �ų��ظ��Ͳ���Ҫ�����
		if(i>0&&nums[i]==nums[i-1]) continue;
		if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
		if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
		for(int j=i+1; j<n-2; j++)
		{
			if(j>i+1&&nums[j]==nums[j-1]) continue;
			if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
			if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;

			int front=j+1;
			int rear=n-1;
			while(front<rear)
			{
				int sum = nums[i]+nums[j]+nums[front]+nums[rear];
				if(sum<target) front++;
				else if(sum>target) rear--;
				else
				{
					vector<int> forplet(4, 0);
					forplet[0] = nums[i];
					forplet[1] = nums[j];
					forplet[2] = nums[front];
					forplet[3] = nums[rear];
					res.push_back(forplet);

					while(front<rear&&nums[front]==forplet[2]) front++;
					while(front<rear&&nums[rear]==forplet[3]) rear--;
				}
			}
		}
	}
	return res;
}

int main()
{
	int num[] = {1, 0, -1, 0, -2, 2};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	vector<vector<int>> res = fourSum(nums, 0);
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}