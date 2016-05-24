/*
题目：Contains Duplicate III
要求：Given an array of integers, find out whether there are two distinct 
indices i and j in the array such that the difference between nums[i] and 
nums[j] is at most t and the difference between i and j is at most k.

题目大意：找出数组中是否存在两个数大小之差<=t，且下标之差<=k。

思路：用一个set容器存放元素，并且保证元素一定是在相差k以内的，
然后比较set中的元素是否满足有大小之差<=t的，如果有，则返回true，
若没有，则继续存放删除数据到容器内，知道所有元素遍历完。
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	set<int> num;	//自动排序存放
	for(int i=0; i<nums.size(); i++)
	{
		if(i>k) num.erase(nums[i-k-1]);
		//保证容器中最多k个元素
		auto pos=num.lower_bound(nums[i]-t);
		// 因为需要|x-nums[i]|<=t，所以有-t<=x-nums[i]<=t，先找满足
		//x<=nums[i]-t的值，再去比较x是否满足x<=nums[i]+t。
		if(pos!=num.end()&&*pos<=nums[i]+t) return true;
		num.insert(nums[i]);
	}
	return false;
}

int main()
{
	int num[]={1,2,3,4,5};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << containsNearbyAlmostDuplicate(nums, 2, 1) << endl;
	system("pause");
	return 0;
}