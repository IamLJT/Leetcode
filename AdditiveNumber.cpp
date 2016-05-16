/*
��Ŀ��Additive Number 
Ҫ��Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for 
the first two numbers, each subsequent number in the sequence must be the 
sum of the preceding two.

��Ŀ���⣺��һ���ַ����ж����е������Ƿ�����ɼ������У��ɼ��������ǵ�����
������ǰ��������֮�ͣ��ַ����е����ֿ��Բ�ֻ1λ��

˼·����Ϊһ��ʼ�������ַ������Ȳ����ܳ���������ʼ���ַ������ȵ�1/2��Ȼ���ж�
ÿ�εĿ�ʼ�����ַ�������ʣ����ַ����Ƿ�����ɼ������е��������������򷵻�
true����������㣬��Ƚ�ʣ����ַ������Ƿ����ǰ�����ַ����ĺͣ����������ȥ��
��һ���ַ������ټ����Ƚϣ���Ļ��򷵻�false��
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool check(long num1, long num2, string num)
{
	if(num.size()>1 && num[0]=='0')
		return false;
	long sum = num1+num2, nums = stol(num);
	int len = log10(sum)+1;
	if(sum==nums) return true;
	if(sum>nums || sum!=stol(num.substr(0, len)))
		return false;
	else
		return check(num2, sum, num.substr(len));
}

bool isAdditiveNumber(string num)
{
	for(int i=1; i<=num.size()/2; i++)
	{
		for(int j=1; j<=(num.size()-i)/2; j++)
		{
			if(i>=2 && num[0]=='0' || j>=2 && num[i]=='0')
				continue;
			if(check(stol(num.substr(0, i)), stol(num.substr(i, j)), num.substr(i+j)))
				return true;
		}
	}
	return false;
}

int main()
{
	string num = "121125";
	if(isAdditiveNumber(num))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}