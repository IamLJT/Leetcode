/*
题目：Count of Smaller Numbers After Self
要求：You are given an integer array nums and you have to 
return a new counts array. The counts array has the property 
where counts[i] is the number of smaller elements to the 
right of nums[i].

题目大意：找出数组每个元素右边比它小的数的个数。

思路：倘若正常计算的话，每次比较每个数后面比它小的数的个数，
则复杂度有O(n^2)，重复比较了太多，不可取。倘若先将数组拍好序，
从第一个数开始遍历，找出它在数组中的位置,然后从数组中删掉他，
如果查找和排序的方法好的话可已让复杂度在O(nlogn)。
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