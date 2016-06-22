/*
��Ŀ��Russian Doll Envelopes
Ҫ��You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is 
greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)

��Ŀ���⣺�������ҳ����ĺ��Ӹ�����Ҫ��С�ĺ����ܹ�Ƕ�׵�������ĺ����У���w(n+1)>w(n),h(n+1)>h(n)��

˼·��������Ҫ����Щ���ӽ�����������Ĺ���ͬ�ڳ������򣬿��԰�w��������Ȼ������֮��Ϳ���
���ճ���Ļ��ݷ�ȥ���㣬�������������ַ�����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(pair<int, int>& p1, pair<int, int>& p2)//����ȽϹ���
{
	return p1.first < p2.first || p1.first==p2.first && p1.second > p2.second;
			//	��֤��ͬw�Ĳ��ᱻ�Ƚ�
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