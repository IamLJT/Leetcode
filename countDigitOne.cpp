#include <iostream>
#include <math.h>
using namespace std;

int countDigitOne(int n)
{
	//	��ÿһλ��1����һλ��ߵ���+1�����ұ�λ�������ֵ��
	//	��Ϊ��11������1���֣����Բ��õ��Ļ��ظ���
	if(n<=0) return 0;
    int left = n;	
    int Right = 0;
	int Result = 0;
	int RightSize = 0;
	long num=n;
	while(left)
	{
		left/=10;
		Right=num%(long)pow(10,RightSize);
		if(n%10 > 1)	//	���λ�ϵ�ֵ����1����1�Ļ�����ֵ������
		    Result+=(left+1)*pow(10,RightSize);
		if(n%10 == 1)	//	���λ�ϵ�ֵ����1�������С��left��ֵ�����㣬����left������ұߵ�ֵ
		    Result+=left*pow(10,RightSize)+Right+1;
		if(n%10 == 0)	//	���Ϊ0�������С��left��ֵ���㣬����������
		    Result+=left*pow(10,RightSize);
		n=left;
		RightSize++;
	}
	return Result;
}

int main()
{

}