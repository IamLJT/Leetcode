/*
题目：Coin Change
要求：You are given coins of different denominations and
a total amount of money amount. Write a function to compute 
the fewest number of coins that you need to make up that 
amount. If that amount of money cannot be made up by any 
combination of the coins, return -1.

题目大意：给一个数组nums和一个总数amount，数组里面是一堆零
钱，写一个函数用这些零钱组成这个总数，如果有，找出需要的最
少数量，如果没有，则返回-1.

思路：从1计算到amount，计算每次的值与某一枚零钱的差距这一段
需要的数量+1和它自身需要的零钱数的大小，再将其较小值重新赋
给它，最终得到了从1到amount的所有换算所需要的零钱最少数。
*/
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) 
{
	int MAX = amount+1;
	vector<int> dp(amount+1, MAX);
	dp[0] = 0;
	for(int i=0; i<=amount; i++)
		for(int j=0; j<coins.size(); j++)
			if(coins[j] <= i)
				dp[i] = min(dp[i], dp[i-coins[j]]+1);	
	//	找出与比它小的每一块硬币差距之间所需硬币数+1的最小值
	return dp[amount]>amount ? -1 : dp[amount];			
	//	若没有任何一块硬币能组成，则保留其最大值
}

int main()
{
	int coin[] = {2};
	vector<int> coins(coin, coin+sizeof(coin)/sizeof(int));
	cout << coinChange(coins, 10) << endl;
	system("pause");
	return 0;
}