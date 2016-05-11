/*
题目：Create Maximum Number 
要求：Given two arrays of length m and n with digits 0-9 representing 
two numbers. Create the maximum number of length k <= m + n from digits 
of the two. The relative order of the digits from the same array must 
be preserved. Return an array of the k digits. You should try to 
optimize your time and space complexity.

题目大意：给两个数组，里面是0-9的数，再给一个k值，k值是小于等于两数组长
度的和，找出k位的最大的一个数，并且数字在原数组中相对位置不变。

思路：nums1和nums2长度分别为l1、l2，从较短数组开始，如果长度<k，则取t从0
到数组长度，则另外一个数组取长为k-t（如果长度>=k，则t从0取到k），找对数组
中对应位数的最大值，且相对位置不变，组合时也是从较短数开始，按位置不变的
情况插入到较长数中，最终比较出最大的数。(复杂度比较高)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> max(vector<int> nums, int t)
{
	vector<int> res;
	vector<int> temp;
	int high=0, count=0;
	if(!t) return res;
	for(int j=0; j<nums.size(); j++)
	{
		if(count < t)
		{
			res.push_back(nums[j]);
			count++;
			if(!high && j>0 && nums[j] > nums[j-1])
			{
				high = j;
			}
		}
		else
		{
			if(high)
			{
				res.erase(res.begin()+high-1);
				high = high -1;
				res.push_back(nums[j]);
				if(res.size() != count)
					cout << "Wrong!!!" << endl;
				for(int i=high-1; i<count; i++)
				{
					if(i>0 && res[i]>res[i-1])
					{
						high = i;
						break;
					}
					high=0;
				}
			}
			else if(nums[j]>res[res.size()-1])
			{
				res[res.size()-1] = nums[j];
				if(res.size()>1 && res[res.size()-1]>res[res.size()-2])
					high = res.size()-1;
			}
		}
	}
	return res;
}

int position(vector<int>& num, int i, int nums) // 寻找第一比它小的数
{
	for(int j=i; j<num.size(); j++)
	{
		if(num[j] <= nums)
			return j;
	}
	return num.size();
}

vector<int> fixnums(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> res(nums1);
	int j=0;
	int pos;
	for(int i=0; i<nums2.size(); i++)
	{
		//pos = lower_bound(res.begin()+j, res.end(), nums2[i])-res.begin();
		pos = position(res, j, nums2[i]);
		res.insert(res.begin()+pos, nums2[i]);
		j = pos+1;
	}
	return res;
}

long num(vector<int> nums)
{
	long sum=0;
	for(int i=0; i<nums.size(); i++)
	{
		sum = sum*10 + nums[i];
	}
	return sum;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
	int t = nums1.size() < k ? nums1.size() : k;
	vector<int> res;
	vector<int> temp, temp1, temp2;
	long max0=0;
	for(int i=0; i<=t; i++)
	{
		if(k-i > nums2.size())
			continue;
		temp1 = max(nums1, i);
		temp2 = max(nums2, k-i);
		temp = fixnums(temp1, temp2);
		if(num(temp) > max0)
		{
			res.clear();
			res = temp;
			max0 = num(temp);
		}
		temp = fixnums(temp2, temp1);
		if(num(temp) > max0)
		{
			res.clear();
			res = temp;
			max0 = num(temp);
		}
	}
	return res;
}

int main()
{
	int num1[] = {8,5,9,5,1,6,9};
	int num2[] = {2,6,4,3,8,4,1,0,7,2,9,2,8};
	vector<int> nums1(num1, num1+sizeof(num1)/sizeof(int));
	vector<int> nums2(num2, num2+sizeof(num2)/sizeof(int));
	vector<int> res;
	res = maxNumber(nums1, nums2, 20);
	cout << "[";
	if(res.size())
		cout << res[0];
	for(int i=1; i<res.size(); i++)
		cout << " " << res[i];
	cout << "]\n";
	system("pause");
	return 0;
}