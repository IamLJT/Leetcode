/*
��Ŀ��Bulb Switcher 
Ҫ��There are n bulbs that are initially off. You first turn 
on all the bulbs. Then, you turn off every second bulb. On the 
third round, you toggle every third bulb (turning on if it's off 
or turning off if it's on). For the ith round, you toggle every 
i bulb. For the nth round, you only toggle the last bulb. Find 
how many bulbs are on after n rounds.

��Ŀ���⣺��n������һ��ʼʱ�صģ���һ�Σ�ÿ�����ݷ�תһ�Σ��ڶ�
�Σ�ÿ��һ����ת1�Σ������Σ�ÿ��������ת1�Σ�ֱ����n�Σ��ҳ���
��n�β�������ʣ���ٸ������ġ�

˼·������ÿһ������˵�����������һ��ƽ��������ô��������һ����
�ɶԳ��ֵģ�����6��������1��6��2��3����ô��������ϵĵ���һ����
���ŵģ���Ϊ�����ظ����͹صĹ��̣����һ���ǹأ�������ƽ�������ԣ�
�������Ŀ�����֮�⣬������������Ҳ�ǳɶԳ��ֵģ���������������Ϊ
��������ô�����һ���ǿ��ģ���ˣ����ڵ�����Ϳ��Լ�Ϊ��n����
���ڣ��м�����ƽ��������(int)sqrt(n)��
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