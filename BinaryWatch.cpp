/*
题目：Binary Watch
要求：A binary watch has 4 LEDs on the top which represent the hours (0-11), 
and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int OneNum(int n)
{
	int res=0;
	while(n)
	{
		if(n%2) res++;
		n>>=1;
	}
	return res;
}

void hourString(vector<vector<string>>& hourstring)
{
	stringstream ss;
	for(int i=0; i<12; i++)
	{
		ss << i;
		string str=ss.str();
		ss.str("");
		hourstring[OneNum(i)].push_back(str);
	}
}

void minuteString(vector<vector<string>>& minutestring)
{
	stringstream ss;
	for(int i=0; i<60; i++)
	{
		ss<<i;
		string str=ss.str();
		if(str.size()==1) str="0"+str;
		ss.str("");
		minutestring[OneNum(i)].push_back(str);
	}
}

vector<string> readBinaryWatch(int num)
{
	vector<vector<string>> hourstring(12), minutestring(60);
	hourString(hourstring);
	minuteString(minutestring);
	vector<string> res;
	string temp="";
	for(int i=0; i<=num&&i<4; i++)
	{
	    if(num-i>=6)
	        continue;
		for(int a=0; a<hourstring[i].size(); a++)
			for(int b=0; b<minutestring[num-i].size(); b++)
			{
				temp=hourstring[i][a]+":"+minutestring[num-i][b];
				res.push_back(temp);
			}
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<string> str=readBinaryWatch(n);
	for(int i=0; i<str.size(); i++)
		cout << str[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}