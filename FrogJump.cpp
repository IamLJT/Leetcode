/*
题目：Frog Jump
要求：A frog is crossing a river. The river is divided into x units and at 
each unit there may or may not exist a stone. The frog can jump on a stone, 
but it must not jump into the water.
Given a list of stones' positions (in units) in sorted ascending order, 
determine if the frog is able to cross the river by landing on the last 
stone. Initially, the frog is on the first stone and assume the first 
jump must be 1 unit.
If the frog's last jump was k units, then its next jump must be either k - 1, 
k, or k + 1 units. Note that the frog can only jump in the forward direction.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> dp;

//	没看懂···
bool canCross(vector<int>& stones, int pos = 0, int k = 0) 
{
    int key = pos | k << 11;

    if (dp.count(key) > 0)
        return dp[key];

    for (int i = pos + 1; i < stones.size(); i++) {
        int gap = stones[i] - stones[pos];
        if (gap < k - 1)
            continue;
        if (gap > k + 1)
            return dp[key] = false;
        if (canCross(stones, i, gap))
            return dp[key] = true;
    }

    return dp[key] = (pos == stones.size() - 1);
}

int main()
{
	int N;
	scanf("%d",&N);
	vector<int> stones(N,0);
	for(int i=0; i<stones.size(); i++)
		scanf("%d",&stones[i]);
	if(canCross(stones))
		printf("true\n");
	else
		printf("false\n");
	system("pause");
	return 0;
}