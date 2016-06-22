/*
题目：Russian Doll Envelopes
要求：You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is 
greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)

题目大意：类似于找出最多的盒子个数，要求小的盒子能够嵌套到比它大的盒子中，即w(n+1)>w(n),h(n+1)>h(n)。

思路：首先需要对这些盒子进行排序，排序的规则不同于常规排序，可以按w优先排序，然后排序之后就可以
按照常规的回溯法去计算，类似求出最长递增字符串。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(pair<int, int>& p1, pair<int, int>& p2)//定义比较规则
{
	return p1.first < p2.first || p1.first==p2.first && p1.second > p2.second;
			//	保证了同w的不会被比较
}

/*bool cmp0(pair<int, int>& p1, pair<int, int>& p2)
{
	return p1.first < p2.first && p1.second < p2.second;
}

void maxlength(vector<pair<int, int>>& envelopes, int& maxlen, int pos, int st, vector<pair<int, int>> temp)
{
	if(envelopes.size()-st<maxlen || st==envelopes.size() || pos==envelopes.size())
		return;
	if(temp.empty() || cmp0(temp.back(), envelopes[pos]))
	{
		temp.push_back(envelopes[pos]);
		maxlen = maxlen > temp.size() ? maxlen : temp.size();
	}
	if(pos!=envelopes.size())
		maxlength(envelopes, maxlen, pos+1, st, temp);
	else
		maxlength(envelopes, maxlen, st+1, st+1, temp);
}*/

int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
	int maxlen=1;
	vector<pair<int, int>> temp;
	if(envelopes.size() < 2)
		return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), cmp);

	vector<int> dp;
	for(auto e : envelopes)
	{
		auto iter = lower_bound(dp.begin(), dp.end(), e.second);
		if(iter == dp.end())
			dp.push_back(e.second);
		else
			if(e.second < *iter)
				*iter = e.second;
	}
	return dp.size();

	//for(int i=0; i<envelopes.size(); i++)
	//	maxlength(envelopes, maxlen, i, i, temp);
	return maxlen;
}

int main()
{
	vector<pair<int, int>> res;
	res.push_back(make_pair<int, int>(2,3));
	res.push_back(make_pair<int, int>(3,2));
	res.push_back(make_pair<int, int>(4,3));
	res.push_back(make_pair<int, int>(5,7));
	cout << maxEnvelopes(res) << endl;
	system("pause");
	return 0;
}