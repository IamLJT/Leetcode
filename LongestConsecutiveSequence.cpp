/*
题目：Longest Consecutive Sequence
要求：Given an unsorted array of integers, find the length of the longest 
consecutive elements sequence.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    if(!nums.size()) return 0;
    unordered_set<int> num(nums.begin(), nums.end());
    int maxlen=0;
    for(int i=0; i<nums.size(); i++)
    {
        if(num.find(nums[i])==num.end())
            continue;
        num.erase(nums[i]);
        int count=1;
        int left=nums[i];
        while(num.find(--left)!=num.end())
            num.erase(left);
        int right=nums[i];
        while(num.find(++right)!=num.end())
            num.erase(right);
        maxlen=maxlen>(right-left-1)?maxlen:(right-left-1);
    }
    return maxlen;
}

int main()
{
	int num[] = {100, 4, 200, 1, 3, 2};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	cout << longestConsecutive(nums) << endl;
	system("pause");
	return 0;
}