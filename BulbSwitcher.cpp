/*
题目：Bulb Switcher 
要求：There are n bulbs that are initially off. You first turn 
on all the bulbs. Then, you turn off every second bulb. On the 
third round, you toggle every third bulb (turning on if it's off 
or turning off if it's on). For the ith round, you toggle every 
i bulb. For the nth round, you only toggle the last bulb. Find 
how many bulbs are on after n rounds.

题目大意：有n个灯泡一开始时关的，第一次，每个灯泡反转一次，第二
次，每隔一个反转1次，第三次，每隔两个反转1次，直到第n次，找出在
第n次操作过后还剩多少个是亮的。

思路：对于每一个数来说，如果它不是一个平方数，那么它的因子一定是
成对出现的，比如6的因子是1和6、2和3，那么在这个数上的灯泡一定是
关着的，因为它在重复开和关的过程，结局一定是关，而对于平方数而言，
除了它的开方数之外，它其他的因子也是成对出现的，所以它的因子数为
奇数，那么它最后一定是开的，因此，现在的问题就可以简化为在n个数
以内，有几个是平方数，即(int)sqrt(n)。
*/

#include <iostream>
using namespace std;

int bulbSwitch(int n)
{
	return (int)sqrt(n);
}

int main()
{
	cout << bulbSwitch(10) << endl;
	system("pause");
	return 0;
}