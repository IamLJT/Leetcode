/*
��Ŀ��Super Ugly Number
Ҫ��Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime 
factors are in the given prime list primes of size k. 
For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] 
is the sequence of the first 12 super ugly numbers given 
primes = [2, 7, 13, 19] of size 4.
Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k �� 100, 0 < n �� 10^6, 0 < primes[i] < 1000.

��Ŀ���⣺�Ӹ��������������У��ҳ����������е�k��ֵ������
����ָ����ֻ�ø������������е�����Ϊ���ӡ�1��Զ�ǳ���������

˼·�������������飬һ��������ų�����������һ������¼����
���ֵĴ�������Ҫ��������µĳ��������������еĳ�����������
�κ�һ�����������������������¼�������������Ϊ�˱����ظ���
���㷨ûŪ���ף�������
*/
#include <iostream>
#include <vector>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) 
{
    vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
    ugly[0]=1;
    for(int i=1; i<n; i++){
        for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
        for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
    }
    return ugly[n-1];
}

int main()
{
	int pri[] = {2, 5, 7, 13};
	vector<int> primes(pri, pri+sizeof(pri)/sizeof(int));
	cout << nthSuperUglyNumber(12, primes) << endl;
	system("pause");
	return 0;
}