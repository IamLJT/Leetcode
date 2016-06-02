/*
��Ŀ��Merge Intervals
Ҫ��Given a collection of intervals, merge all overlapping intervals.

��Ŀ���⣺�ϲ����������������н���ļ��ϡ�

˼·���Ƚ����ϵ�ǰһ��ֵ����С�����ź���Ȼ����б�����������漯�ϵ�
ǰһ��ֵ��ǰһ�����ϵĺ�һ��ֵ����ֱ��ѹ�������У���֮��ǰһ������
�ĺ�һ��ֵ�����������ɡ�
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