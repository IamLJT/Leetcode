/*
题目：Count of Range Sum
要求：Given an integer array nums, return the number of range 
sums that lie in [lower, upper] inclusive. Range sum S(i, j) is 
defined as the sum of the elements in nums between indices i 
and j (i ≤ j), inclusive.

题目大意：给定一个数组nums和两个值lower和upper，找出所有范围和
在这两个值之间的情况的个数。

思路：首先想到的是计算出所有的范围和，需要O(n^2)的时间复杂度
和O(n!)的空间复杂度，不可取。换个思路看，所有的范围和都是由两
个前n项和相减得到的，因此只需找出所有两个前n项和在lower和upper
之间的总个数即可。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int countRangeSum(vector<int>& nums, int lower, int upper)
{
	/*
	vector<int> sum;
	int sums=0, res=0;
	sum.push_back(sums);
	for(int i=0; i<nums.size(); i++)
	{
		
		sort(sum.begin(), sum.end());
		res += lower_bound(sum.begin(), sum.end(), sums-lower) 
			- upper_bound(sum.begin(), sum.end(), sums-upper);
		sums+=nums[i];
		sum.push_back(sums);
	}
	return res;
	*/
	multiset<long long> pSum;
	int res = 0,  i; 
	long long sum=0;
	for(i=0,pSum.insert(0); i<nums.size(); ++i)
	{
		sum +=nums[i];
		res += distance(pSum.lower_bound(sum-upper), pSum.upper_bound(sum-lower));
		pSum.insert(sum);
	}
	return res;
}

int main()
{
	int num[] = {-2, 5, -1};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << countRangeSum(nums, -2, 2) << endl;
	system("pause");
	return 0;
}