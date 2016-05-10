#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) 
{
    if(0 == strs.size())
		return "";
	string prefix = strs[0];
	int len = prefix.size(), j = 0;
    for(int i=1; i<strs.size(); i++)
	{
		if(0 == prefix.length() || 0 == strs[i].size())
			return "";
		if(strs[i].size() < len)
			len = strs[i].size();
		for(j=0; j<len; j++)
		{
			if(strs[i][j] != prefix[j])
				break;
		}
		prefix = prefix.substr(0, j);
	}
	return prefix;
}
int main()
{
	string str[] = {"Arraystack", "Arrays", "Array"};
	vector<string> strs(str, str+sizeof(str)/sizeof(str[0]));
	cout << "Common Prefix is: " << longestCommonPrefix(strs) << endl;
	system("pause");
	return 0;
}