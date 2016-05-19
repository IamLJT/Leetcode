/*
题目：Intersection of Two Arrays
要求：Given two arrays, write a function to compute their intersection.

题目大意：找出两个数组的交叉元素，确保每个元素只出现1次

思路：用哈希容器存放每个数的个数，索引下标为该数字，每次索引到的数，将
其个数置0，则能保证只出现1次交叉数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> map;
	vector<int> res;
	for(int i=0; i<nums1.size(); i++)
		map[nums1[i]]++;
	for(int i=0; i<nums2.size(); i++)
	{
		if(map[nums2[i]])
		{
			res.push_back(nums2[i]);
			map[nums2[i]]=0;
		}
	}
	return res;
}

int main()
{
	int num1[] = {1,2,3}, num2[] = {3,2};
	vector<int> nums1(num1, num1+sizeof(num1)/sizeof(int));
	vector<int> nums2(num2, num2+sizeof(num2)/sizeof(int));
	vector<int> res = intersection(nums1, nums2);
	if(res.size()) cout << res[0];
	for(int i=1; i<res.size(); i++)
		cout << " " << res[i];
	cout << endl;
	system("pause");
	return 0;
}