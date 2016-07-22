/*
��Ŀ��Wiggle Subsequence
Ҫ��A sequence of numbers is called a wiggle sequence if the differences 
between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. 
A sequence with fewer than two elements is trivially a wiggle sequence.

˼·���������һ�㣬���������һ���Ǵӵ�һ����ֵ��ʼ�ģ�����֮��ģ�����Ϊ
��ֵת��Ϊ1��-1����ʱ�������һ��ֵΪ1��,��ô�������е�1�����Ժ��ԣ��������
��һ��-1�����ֵ���У�������Ȼû�н�����������ǰ������Ĳ�ֵ�����������ͬ��
���Խ��бȽϣ�����ǰ�������Ĳ�Ϊ�������������һ��������ǰ����֮��ҲΪ������
�ٺ����һ���������Ĳ�Ϊ������ô���������ǰ�����֮��Ҳ��Ϊ������
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