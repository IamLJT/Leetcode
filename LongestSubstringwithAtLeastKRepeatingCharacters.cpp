/*
题目：Longest Substring with At Least K Repeating Characters
要求：Find the length of the longest substring T of a given string (consists of 
lowercase letters only) such that every character in T appears no less than k times.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestSubstring(string s, int k)
{
	if(k<=1)
		return s.size();
	string temp="";
	vector<int> letter(26,0);
	vector<int> templetternum(26,0);
	vector<int> dp(s.size(),0);
	int max=0;
	for(int i=0; i<(int)s.size(); i++)
	{
		letter[s[i]-'a']++;
	}
	for(int i=0; i<(int)s.size(); i++)
	{
		if(letter[s[i]-'a']<k&&letter[s[i]-'a']>0)
		{
			dp[i]=0;
			for(int j=0; j<26; j++)
				letter[j]-=templetternum[j];
			templetternum.assign(26,0);
		}
		else
		{
			templetternum[s[i]-'a']++;
			int flag=0,SUM=0;
			for(int j=0;j<26;j++)
			{
				if(templetternum[j]<k&&templetternum[j]>0)
				{
					flag=1;
					break;
				}
				SUM+=templetternum[j];
			}
			int sum=1;
			if(flag==0)
				dp[i]=SUM;
			for(int j=i;j>=1&&flag==1;j--)
			{
				if(s[j]==s[j-1])
					sum++;
				else
				{
					if(sum>=k)
						dp[i]=dp[j-1]+sum;
					else
						dp[i]=0;
					
					break;
				}
			}
			if(dp[i]>max)
				max=dp[i];
		}
	}
	return max;
}

int main()
{
	string str;
	int k;
	cin >> str >> k;
	
	cout << longestSubstring(str, k) << endl;
	system("pause");
	return 0;
}