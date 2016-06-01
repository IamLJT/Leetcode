/*
题目：Summary Ranges
要求：Given a sorted integer array without duplicates, return 
the summary of its ranges.
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string temp, ss;
        stringstream stream;
        int begin, end;
        if(nums.size()) begin=end=nums[0];
        else return res;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==end+1)
                end=nums[i];
            else
            {
                if(begin==end)
                {
                    stream.clear();
                    stream << begin;
                    stream >> temp;
                    //temp=""+begin;
                    res.push_back(temp);
                    temp="";
                }
                else
                {
                    stream.clear();
                    stream<<begin;
                    stream>>ss;
                    temp+=ss;
                    //temp+=""+begin;
                    temp+="->";
                    stream.clear();
                    stream<<end;
                    stream>>ss;
                    temp+=ss;
                    res.push_back(temp);
                    temp="";
                }
                begin=end=nums[i];
            }
        }
        if(begin==end)
        {
            stream.clear();
            stream << begin;
            stream >> temp;
            //temp=""+5;
            res.push_back(temp);
            temp="";
        }
        else
        {
            stream.clear();
            stream<<begin;
            stream>>ss;
            temp+=ss;
            //temp+=""+begin;
            temp+="->";
            stream.clear();
            stream<<end;
            stream>>ss;
            temp+=ss;
            res.push_back(temp);
            temp="";
        }
        return res;
    }

int main()
{
	int num[] = {1,2,3,5,7};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	vector<string> res=summaryRanges(nums);
	if(res.size()) cout<<res[0];
	for(int i=1; i<res.size(); i++)
	{
		cout << ", " << res[i];
	}
	cout << endl;
	system("pause");
	return 0;
}