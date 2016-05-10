/*
��Ŀ��Patching Array 
Given a sorted positive integer array nums and an integer n, 
add/patch elements to the array such that any number in range 
[1, n] inclusive can be formed by the sum of some elements 
in the array. Return the minimum number of patches required.

��Ŀ���⣺����һ������nums��һ����n����������ٵ���ʹ������
[1, n]�е�ÿ����������������nums��Ԫ���ۼ���ɡ�

˼·�����ȶ���һ�����α���top����������numsĿǰ�����ۼӵ���
�ķ�ΧΪ[1,top]����������������Ԫ��k��k<=top�����Խ��ۼӵ�
���ķ�Χ���䵽[1,top+k]������Ŀ��Ҫ��������nums���Ԫ�صĸ�
�����٣���˵��ҽ���k=topʱ���ۼ����ķ�Χ����ȡ������[1,2*top]��
��ˣ��ڱ�������numsʱ�������ֲ���������������С�ڵ���top��
������ʹ�������е�Ԫ�أ�ͬʱtop+=nums[index]����û�У������
��Ԫ��top�������У��������+1��ͬʱ��top=2*top��
*/
#include <iostream>
#include <vector>
using namespace std;
int minPatches(vector<int>& nums, int n)
{
	int index = 0, count = 0;
    long long top = 1;
    while(top <= n)
    {
    	if(index<nums.size() && nums[index]<=top)
    	{
    		top += nums[index++];
    	}
    	else
    	{
    		count++;
    		top = 2*top;
    	}
    }
    return count;
}
int main()
{
	int num[] = {1,5,10};
	vector<int> nums(num,num+3);
	cout << minPatches(nums,20) << endl;
	system("pause");
	return 0;
}