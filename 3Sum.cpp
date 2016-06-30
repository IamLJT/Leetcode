/*
题目：3Sum
要求：Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

思路：思路比较简单，从第一个数开始遍历，然后从后面的数中找出和为其负数的组合，主要
难度在于不能重复。
*/

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
/*
    vector<vector<int>> res;
    if(nums.size()<3) return res;
    sort(nums.begin(),nums.end());
    vector<int> temp;
    multimap<int, int> num;
    multimap<int, int> res0;
    multimap<int, int>::iterator s;
	set<int> num0;
    typedef multimap<int, int>::iterator int_mul;
	int a, b;
    num.insert(make_pair(nums[0]+nums[1], nums[0]));
        
    for(int i=2; i<nums.size(); i++)
    {
        *//*s=num.find(-nums[i]);
        if(s!=num.end())
        {
            temp.push_back(s->second);
            temp.push_back(s->first-s->second);
            temp.push_back(nums[i]);
            sort(temp.begin(), temp.end());
            res.push_back(temp);
            temp.clear();
            num.erase(s);
        }*//*
        pair<int_mul,int_mul> p = num.equal_range(-nums[i]);
        for(s = p.first; s != p.second; s++)  
        {
            a = s->second>(s->first-s->second)?s->second:(s->first-s->second);
            b = s->first - a;
            if(a*b==0&&res0.find(-s->first)!=res0.end())
				continue;
			if(res0.find(b)!=res0.end()&&num0.find(a+b)!=num0.end())
				continue;
			num0.insert(b+a);
            res0.insert(make_pair(b, a));
        }
		
        for(int j=0; j<i; j++)
            num.insert(make_pair(nums[j]+nums[i], nums[j]));
    }
    for(auto it=res0.begin(); it!=res0.end(); it++)
    {
        temp.push_back(it->first);
        temp.push_back(it->second);
        temp.push_back(-it->first-it->second);
        sort(temp.begin(), temp.end());
        res.push_back(temp);
        temp.clear();
    }
    return res;
*/
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	
	for(int i=0; i<nums.size(); i++)
	{
		int target = -nums[i];
		int front = i+1;
		int rear = nums.size()-1;

		while(front < rear)
		{
			int sum = nums[front] + nums[rear];
			if(sum < target)
				front++;
			else if(sum > target)
				rear--;
			else
			{
				vector<int> triplet(3, 0);
				triplet[0] = nums[i];
				triplet[1] = nums[front];
				triplet[2] = nums[rear];
				res.push_back(triplet);

				// 由于已经排好了序，所以在排重的时候比较简单
				while(front<rear && nums[front]==triplet[1]) front++;
				while(front<rear && nums[rear]==triplet[2]) rear--;
			}
		}

		// 继续排重
		while(i<nums.size()-1 && nums[i+1]==nums[i])
			i++;
	}

	return res;
}

int main()
{
	int num[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));

	vector<vector<int>> res = threeSum(nums);

	for(int i=0; i<res.size(); i++)
	{
		for(int j=0; j<res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}