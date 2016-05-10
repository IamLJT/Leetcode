/*
��Ŀ��Missing Number
Ҫ��Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

��Ŀ���⣺��0-n���ҳ�����Ψһȱ�ٵ�һ������

˼·1������˼·���Ƚ������ź����ٽ�ÿ�������������ڵ�λ�ý��бȽϣ������ͬ�򷵻���λ�ã��������λ�ö���ͬ�򷵻����鳤�ȡ�

˼·2���������������Ƚϣ������е����ֺ����ڵ�����λ�ý��бȽϣ��ɱȽ�ʽA^B=B^A�Լ�(A^B)^C=A^(B^C)���Է��֣�
A^C^B^A^C = A^A^C^C^B = B��������еıȽ���Ϻ����������ļ�Ϊȱ�ٵ�ֵ����û��ȱ�ٵ��򷵻ص��ǳ�ʼ��ֵ����Ϊ��ʼֵ����������
���ȣ����Ҳ����ԭ���ʽ�����忴Դ���롣
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums)
{
	int res = nums.size();
	for(int i=0; i<nums.size(); i++)
	{
		res ^= nums[i];
		res ^= i;
	}
	return res;
}

int main()
{
	int num[] = {0, 1, 3};
	int x=-3;
	x &= -x;
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << missingNumber(nums) << endl;
	cout << x << endl;
	system("pause");
	return 0;
}
