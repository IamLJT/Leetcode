/*
��Ŀ��Longest Increasing Subsequence
Ҫ��Given an unsorted array of integers, find the length 
of longest increasing subsequence.

��Ŀ���⣺�ҳ�һ����������ĵ��������У����ظ����еĳ���

˼·1���������뵽����O(n^2)���㷨���������Ǵӵ�һ��ֵ����
��һ��ֵ���ڲ�����Ǵ���������ֵ��ʼ�����һ��ֵ��������
�������count++����󷵻���С��count��

˼·2������һ���µ����������洢�Ѿ������������֣����ĳ��ȴ�
��Ŀǰ״̬�����ҵ�������������еĳ��ȣ�ÿ�α���һ����
���ݣ��ҳ�������������λ�ã�������棬�������ݱ�֮ǰ������
�����������������������������ݣ�����ʵ�ֹ��̿����롣
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	vector<int> res;
	for(int i=0; i<nums.size(); i++)
	{
		auto it = lower_bound(res.begin(), res.end(), nums[i]);
		//	lower_bound��������ǰ�պ������ڵ�һ�����ڵ���nums[i]��λ�ã����û�У��򷵻����һ��ֵ
		if(it == res.end())
			res.push_back(nums[i]);
		else
			*it = nums[i];
	}
	return res.size();
}

int main()
{
	int num[] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << lengthOfLIS(nums) << endl;
	system("pause");
	return 0;
}