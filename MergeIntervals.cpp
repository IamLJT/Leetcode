/*
题目：Merge Intervals
要求：Given a collection of intervals, merge all overlapping intervals.

题目大意：合并所给集合中所有有交叉的集合。

思路：先将集合的前一个值按从小到大排好序，然后进行遍历，如果后面集合的
前一个值比前一个集合的后一个值大，则直接压入容器中，反之则将前一个集合
的后一个值进行修正即可。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> res;
	if(intervals.empty()) return res;
	sort(intervals.begin(), intervals.end(), 
		[](Interval a, Interval b){return a.start<b.start;});
	res.push_back(intervals[0]);
	for(int i=1; i<intervals.size(); i++)
	{
		if(intervals[i].start>res.back().end)
			res.push_back(intervals[i]);
		else
			res.back().end=res.back().end>intervals[i].end 
						? res.back().end : intervals[i].end;
	}
	return res;
}

int main()
{
	vector<Interval> ins;
	ins.push_back(Interval(1,3));
	ins.push_back(Interval(2,6));
	ins.push_back(Interval(7,8));
	vector<Interval> res=merge(ins);
	for(int i=0; i<res.size(); i++)
	{
		cout << res[i].start << "," << res[i].end << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}