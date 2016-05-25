/*
��Ŀ��Permutations II
Ҫ��Given a collection of numbers that might contain duplicates, return all possible 
unique permutations.

��Ŀ���⣺�ҳ��������ּ������в���ͬ������

˼·�����������ٴ�ͷ��ʼ������ֻҪ��ͬλ������������ͬ�򽻻�λ�ã������ݹ�ȥ���㣬��
���Խ�������������������忴���롣
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void uniquenum(vector<vector<int>>& res, vector<int> num, int begin, int end)
{
	if(begin==end-1) 
	{
		res.push_back(num);
		return ;
	}
	for(int i=begin; i<end; i++)
	{
		if(i!=begin&&num[i]==num[begin]) continue;
		swap(num[i], num[begin]);
		uniquenum(res, num, begin+1, end);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	uniquenum(res, nums, 0, nums.size());
	return res;
}

int main()
{
	int num[] = {1,2,3,4};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	vector<vector<int>> res=permuteUnique(nums);
	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j];
		cout << endl;
	}
	system("pause");
	return 0;
}