/*
��Ŀ��Count of Range Sum
Ҫ��Given an integer array nums, return the number of range 
sums that lie in [lower, upper] inclusive. Range sum S(i, j) is 
defined as the sum of the elements in nums between indices i 
and j (i �� j), inclusive.

��Ŀ���⣺����һ������nums������ֵlower��upper���ҳ����з�Χ��
��������ֵ֮�������ĸ�����

˼·�������뵽���Ǽ�������еķ�Χ�ͣ���ҪO(n^2)��ʱ�临�Ӷ�
��O(n!)�Ŀռ临�Ӷȣ�����ȡ������˼·�������еķ�Χ�Ͷ�������
��ǰn�������õ��ģ����ֻ���ҳ���������ǰn�����lower��upper
֮����ܸ������ɡ�
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