/*
题目：Jump Game
Given an array of non-negative integers, you are initially 
positioned at the first index of the array. Each element in
the array represents your maximum jump length at that 
position. Determine if you are able to reach the last index.

题目大意：从非负整数数组的第一个位置，判断是否能到达最后一个
位置，其中每个元素代表了从当前位置最大跳跃的长度。

思路1：从最后一个位置反向出发，每次找出能到达此处的最远位置，
再从这个位置出发，同样找到能到达此处的最远位置，当找出的位置
是初始位置则停止，并返回true，若有一次没有找出位置，则返回false。

思路2：从第一个位置出发，每次找出每一个位置能到达的最长距离max，
若最长距离小于此位置，则返回false，若能到达此位置，则去找此
位置能到达的最远距离，去和max比较谁更大，则max等于他们之间更大
的值，直到找到最后一个位置或者max超过了总距离。
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
