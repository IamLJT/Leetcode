/*
题目：3Sum Closest
要求：Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. Return the sum of the three 
integers. You may assume that each input would have exactly one solution.

题目大意：找出数组中三个数之和与目标数最接近的值。

思路：最普通的思路就是求出所有的三个数和，复杂度为O(n^3)。换个思路想，如果
a+b+c->k，那么也可以理解为b+c->k-a，将k-a作为新的目标值即是在后面的数中寻找
两数之和最接近此目标即可。
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	int res=INT_MAX-abs(target);
	sort(nums.begin(), nums.end());

	for(int i=0; i<nums.size(); i++)
	{
		int t_new = target - nums[i];
		int front=i+1;
		int rear=nums.size()-1;

		while(front<rear)
		{
			int sum = nums[front]+nums[rear];
			if(sum > t_new)
				rear--;
			else if(sum < t_new)
				front++;
			else
				return target;
			if(abs(sum-t_new)<abs(res-target))
				res=sum+nums[i];
		}

		while(i<nums.size()-1&&nums[i+1]==nums[i])
			i++;
	}
	return res;
}

int main()
{
	int num[] = {1, 2, -1, -4};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << threeSumClosest(nums, 1) << endl;
	system("pause");
	return 0;
}