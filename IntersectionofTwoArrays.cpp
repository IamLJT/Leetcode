/*
��Ŀ��Intersection of Two Arrays
Ҫ��Given two arrays, write a function to compute their intersection.

��Ŀ���⣺�ҳ���������Ľ���Ԫ�أ�ȷ��ÿ��Ԫ��ֻ����1��

˼·���ù�ϣ�������ÿ�����ĸ����������±�Ϊ�����֣�ÿ����������������
�������0�����ܱ�ֻ֤����1�ν�������
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