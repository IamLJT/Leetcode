/*
*/

#include <iostream>
#include <vector>
using namespace std;

int findtarget(vector<int>& nums, int target, int low, int high)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target)
        return mid;
    if(nums[mid]<target)
        return findtarget(nums, target, mid+1, high);
    if(nums[mid]>target)
        return findtarget(nums, target, low, mid-1);
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) 
{
    int mid=findtarget(nums, target, 0, nums.size()-1);
    int low=mid,high=mid;
    vector<int> res;
    res.push_back(low);
    res.push_back(high);
    if(mid==-1) return res;
    while(--low>=0&&nums[low]==target);
    while(++high<nums.size()&&nums[high]==target);
    res[0]=low+1;
    res[1]=high-1;
    return res;
}

int main()
{
	vector<int> nums(2,2);
	vector<int> res=searchRange(nums, 2);
	cout<< "[" << res[0] << "," << res[1] << "]" << endl;
	system("pause");
	return 0;
}