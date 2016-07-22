/*
题目：Wiggle Subsequence
要求：A sequence of numbers is called a wiggle sequence if the differences 
between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. 
A sequence with fewer than two elements is trivially a wiggle sequence.

思路：首先清楚一点，最长交替序列一定是从第一个差值开始的（除零之外的），因为
差值转换为1、-1来看时，假如第一个值为1，,那么后面所有的1都可以忽略，将后面的
第一个-1加入差值序列（这里虽然没有将所有数与其前面的数的差值计算出来，但同样
可以进行比较，假如前两个数的差为正，后面紧跟的一个数与其前面数之差也为正，但
再后面的一个数与它的差为负，那么这个数与它前面的数之差也必为负）。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int wiggleMaxLength(vector<int>& nums) 
{
	if(nums.size()<2) return nums.size();
	int max=1, len=nums.size();
	vector<int> diff;
	for(int i=1; i<len; i++)
	{
		int t=nums[i]-nums[i-1];
		if(t!=0)
		{
			if(diff.size()==0||t/abs(t)==-diff.back())
				diff.push_back(t/abs(t));
		}
	}
	return max+diff.size();
}

int main()
{
	int a;
	vector<int> num;
	while(cin>>a)
		num.push_back(a);
	cout << wiggleMaxLength(num) << endl;
	system("pause");
	return 0;
}