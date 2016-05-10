/*
��Ŀ��Coin Change
Ҫ��You are given coins of different denominations and
a total amount of money amount. Write a function to compute 
the fewest number of coins that you need to make up that 
amount. If that amount of money cannot be made up by any 
combination of the coins, return -1.

��Ŀ���⣺��һ������nums��һ������amount������������һ����
Ǯ��дһ����������Щ��Ǯ����������������У��ҳ���Ҫ����
�����������û�У��򷵻�-1.

˼·����1���㵽amount������ÿ�ε�ֵ��ĳһö��Ǯ�Ĳ����һ��
��Ҫ������+1����������Ҫ����Ǯ���Ĵ�С���ٽ����Сֵ���¸�
���������յõ��˴�1��amount�����л�������Ҫ����Ǯ��������
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
	//	�ҳ������С��ÿһ��Ӳ�Ҳ��֮������Ӳ����+1����Сֵ
	return dp[amount]>amount ? -1 : dp[amount];			
	//	��û���κ�һ��Ӳ������ɣ����������ֵ
}

int main()
{
	int coin[] = {2};
	vector<int> coins(coin, coin+sizeof(coin)/sizeof(int));
	cout << coinChange(coins, 10) << endl;
	system("pause");
	return 0;
}