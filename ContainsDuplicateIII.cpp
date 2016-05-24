/*
��Ŀ��Contains Duplicate III
Ҫ��Given an array of integers, find out whether there are two distinct 
indices i and j in the array such that the difference between nums[i] and 
nums[j] is at most t and the difference between i and j is at most k.

��Ŀ���⣺�ҳ��������Ƿ������������С֮��<=t�����±�֮��<=k��

˼·����һ��set�������Ԫ�أ����ұ�֤Ԫ��һ���������k���ڵģ�
Ȼ��Ƚ�set�е�Ԫ���Ƿ������д�С֮��<=t�ģ�����У��򷵻�true��
��û�У���������ɾ�����ݵ������ڣ�֪������Ԫ�ر����ꡣ
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	set<int> num;	//�Զ�������
	for(int i=0; i<nums.size(); i++)
	{
		if(i>k) num.erase(nums[i-k-1]);
		//��֤���������k��Ԫ��
		auto pos=num.lower_bound(nums[i]-t);
		// ��Ϊ��Ҫ|x-nums[i]|<=t��������-t<=x-nums[i]<=t����������
		//x<=nums[i]-t��ֵ����ȥ�Ƚ�x�Ƿ�����x<=nums[i]+t��
		if(pos!=num.end()&&*pos<=nums[i]+t) return true;
		num.insert(nums[i]);
	}
	return false;
}

int main()
{
	int num[]={1,2,3,4,5};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << containsNearbyAlmostDuplicate(nums, 2, 1) << endl;
	system("pause");
	return 0;
}