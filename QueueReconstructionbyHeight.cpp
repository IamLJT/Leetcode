/*
题目：Queue Reconstruction by Height
要求：Suppose you have a random list of people standing in a queue. Each 
person is described by a pair of integers (h, k), where h is the height 
of the person and k is the number of people in front of this person who 
have a height greater than or equal to h. Write an algorithm to reconstruct 
the queue.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first==p2.first)
    	return p1.second>p2.second?1:0;
    return p1.first<p2.first?1:0;
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), cmp);
    vector<pair<int,int>> res;
    if(people.size()==0) return res;
    res.push_back(people.back());
    people.pop_back();
    while(people.size())
    {
    	res.insert(res.begin()+people.back().second, people.back());
    	people.pop_back();
    }
    return res;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> people(n);
	for(int i=0; i<n; i++)
		cin >> people[i].first >> people[i].second;
	vector<pair<int,int>> res=reconstructQueue(people);
	system("pause");
	return 0;
}