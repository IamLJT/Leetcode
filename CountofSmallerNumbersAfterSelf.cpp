/*
��Ŀ��Count of Smaller Numbers After Self
Ҫ��You are given an integer array nums and you have to 
return a new counts array. The counts array has the property 
where counts[i] is the number of smaller elements to the 
right of nums[i].

��Ŀ���⣺�ҳ�����ÿ��Ԫ���ұ߱���С�����ĸ�����

˼·��������������Ļ���ÿ�αȽ�ÿ�����������С�����ĸ�����
���Ӷ���O(n^2)���ظ��Ƚ���̫�࣬����ȡ�������Ƚ������ĺ���
�ӵ�һ������ʼ�������ҳ����������е�λ��,Ȼ���������ɾ������
������Һ�����ķ����õĻ������ø��Ӷ���O(nlogn)��
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> countSmaller(vector<int>& nums)
{
	vector<int> num(nums), res;
	int pos=-1;
	sort(num.begin(), num.end());
	while(num.size())
	{
		pos = find(num.begin(), num.end(), nums[0]) - num.begin();
		res.push_back(pos);
		num.erase(pos + num.begin());
		nums.erase(nums.begin());
	}
	return res;
}

int main()
{
	int num[] = {5,2,5,6,1};
	vector<int> res;
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	res = countSmaller(nums);
	if(res.size())
		cout << res[0];
	for(int i=1; i<res.size(); i++)
		cout << "," << res[i];
	cout << endl;
	system("pause");
	return 0;
}