#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> lengthpalindrome(string s, int mid)
{
    vector<int> Result;
	int low=mid-1, high=mid+1;
    while(high<s.size() && s[high]==s[mid])
        high++;
    while(low>=0 && high<s.size() && s[high]==s[low])
    {
        high++;
        low--;
    }
	Result.push_back(low+1);
	Result.push_back(high-1);
    return Result;
}
string longestPalindrome(string s) 
{
    vector<int> res;
    string Result="";
    int longest=0;
	if(s.size() == 1)
	{
		return s;
	}
    for(int i=0; i<s.size();i++)
    {
        res = lengthpalindrome(s, i);
        if(res[1]-res[0]+1 > longest)
        {
            longest = res[1]-res[0]+1;
            Result = s.substr(res[0],longest);
        }
        res.clear();
    }
    return Result;
}
int main()
{
	string s = "abbacd";
	cout << "Output: " << longestPalindrome(s) << endl;
	system("pause");
	return 0;
}