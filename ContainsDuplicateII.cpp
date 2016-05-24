/*
��Ŀ��Contains Duplicate II
Ҫ��Given an array of integers and an integer k, find out 
whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and 
j is at most k.

��Ŀ���⣺�ҳ��������Ƿ������������ȣ������ǵ��±��ֵ<=k��

˼·���ù�ϣ��ṹ�����Щ�����±꣬��������ĳһ�������±겻
Ϊ-1ʱ��Ƚ����ǵĲ�ֵ�Ƿ�<=k�������򷵻�true�������ǣ���
�±�ֵ���£��ټ�������Ƚϡ�
*/

#include <iostream>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    if(nums.size()<2) return false;
    int max=nums[0];
	int min=0;
    for(int i=1; i<nums.size(); i++)
    { 
		if(nums[i]>max)
            max=nums[i];
		if(nums[i]<min)
			min=nums[i];
	}
    vector<int> num(max+1-min, -1);
    for(int i=0; i<nums.size(); i++)
    {
        if(num[nums[i]-min]==-1)
            num[nums[i]-min]=i;
        else
        {
            if(i-num[nums[i]-min]<=k)
                return true;
            else
                num[nums[i]-min]=i;
        }
    }
    return false;
}

int main()
{
	vector<int> nums(5,-1);
	cout << containsNearbyDuplicate(nums, 0) << endl;
	system("pause");
	return 0;
}