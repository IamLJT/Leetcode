/*
题目：Range Sum Query - Mutable
要求：Given an integer array nums, find the sum of the elements between 
indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index 
i to val.

题目大意：找出任意范围和，用update更新数组里的元素，并且后面依然要求范围和。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumArray
{
public:
	NumArray(vector<int> &nums)
	{
		num=nums;
		sums=vector<int>(nums.size()+1, 0);
		for(int i=1; i<nums.size()+1; i++)
		    sums[i]=sums[i-1]+nums[i-1];
	}

	void update(int i, int val)
	{
		for(int k=i; k<num.size(); k++)
			sums[k+1] += val-num[i];
		num[i]=val;
	}

	int sumRange(int i, int j)
	{
		return sums[j+1]-sums[i];
	}

private:
	vector<int> num;
	vector<int> sums;
};

int main()
{
	int num[] = {1, 2, 3, 4, 5};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	NumArray numArray(nums);
	cout << numArray.sumRange(0,1) << endl;
	numArray.update(1,10);
	cout << numArray.sumRange(1,2) << endl;
	system("pause");
	return 0;
}