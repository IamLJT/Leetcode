#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

vector<string> findItinerary(vector<pair<string, string>> tickets)
{
	vector<string> Result;
	int n = tickets.size();
	if(n < 1) return Result;
	map<string, multiset<string>> buf;	
	for(int i=0; i<n; i++)
		buf[tickets[i].first].insert(tickets[i].second);
	//	插入时就是按照字母表排的，所以不需要比较
	stack<string> dfs;
	dfs.push("JFK");
	while(!dfs.empty())
	{
		string top = dfs.top();
		if(buf[top].empty())
		{
			Result.push_back(top);
			dfs.pop();
		}
		else
		{
			dfs.push(*buf[top].begin());
			buf[top].erase(buf[top].begin());
		}
	}
	reverse(Result.begin(), Result.end());
	return Result;
}
int main()
{
	vector<pair<string, string>> tickets;

}