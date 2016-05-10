/*
��Ŀ��Jump Game
Given an array of non-negative integers, you are initially 
positioned at the first index of the array. Each element in
the array represents your maximum jump length at that 
position. Determine if you are able to reach the last index.

��Ŀ���⣺�ӷǸ���������ĵ�һ��λ�ã��ж��Ƿ��ܵ������һ��
λ�ã�����ÿ��Ԫ�ش����˴ӵ�ǰλ�������Ծ�ĳ��ȡ�

˼·1�������һ��λ�÷��������ÿ���ҳ��ܵ���˴�����Զλ�ã�
�ٴ����λ�ó�����ͬ���ҵ��ܵ���˴�����Զλ�ã����ҳ���λ��
�ǳ�ʼλ����ֹͣ��������true������һ��û���ҳ�λ�ã��򷵻�false��

˼·2���ӵ�һ��λ�ó�����ÿ���ҳ�ÿһ��λ���ܵ���������max��
�������С�ڴ�λ�ã��򷵻�false�����ܵ����λ�ã���ȥ�Ҵ�
λ���ܵ������Զ���룬ȥ��max�Ƚ�˭������max��������֮�����
��ֵ��ֱ���ҵ����һ��λ�û���max�������ܾ��롣
*/
#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums)
{
	int pos=1, max=nums[0];
	while(pos<nums.size()-1)
	{
		if(max < pos)
			return false;
		if(max < pos + nums[pos])
			max = pos + nums[pos++];
		if(max >= nums.size()-1)
			return true;
	}
	return true;
}
