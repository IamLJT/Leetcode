/*
��Ŀ��Pow(double x, int n)

1)��ֱ�������뵽�ķ��������õݹ鷽����n��x�ĳ˻���ע�⿼��n�������ţ�ʱ�临�Ӷ�ΪO(n)

[cpp] view plain copy
double pow(double x, int n)  
{  
    if(n==0)  
        return 1.0;  
    if(n<0)  
        return 1.0/pow(x,-n);  
    return x*pow(x,n-1);  
}  

2)���ǵ�n��x���ʽ�ӵĶԳƹ�ϵ�����Զ������������иĽ����Ӷ��õ�һ��ʱ�临�Ӷ�ΪO(logn)�ķ������ݹ��ϵ���Ա�ʾΪpow(x,n) = pow(x,n/2)*pow(x,n-n/2)
[cpp] view plain copy
double pow(double x, int n)  
{  
    if(n==0)  
        return 1.0;  
    if(n<0)  
        return 1.0/pow(x,-n);  
    double half = pow(x,n>>1);  
    if(n%2==0)  
        return half*half;  
    else  
        return half*half*x;  
}  
3)�����������������ﻹ�ᵽ��һ��ʮ������ҿ��ٵķ�����ԭ���������£�

Consider the binary representation of n. For example, if it is "10001011", then x^n = x^(1+2+8+128) = x^1 * x^2 * x^8 * x^128. Thus, we don't want to loop n times to calculate x^n. To speed up, we loop through each bit, if the i-th bit is 1, then we add x^(1 << i) to the result. Since (1 << i) is a power of 2, x^(1<<(i+1)) = square(x^(1<<i)). The loop executes for a maximum of log(n) times.
�÷���ͨ��ɨ��n�Ķ����Ʊ�ʾ��ʽ�ﲻͬλ���ϵ�1��������x���ݴ�

[cpp] view plain copy
double my_pow(double x, int n)  
{  
    if(n==0)  
            return 1.0;  
    if(n<0)  
        return 1.0 / pow(x,-n);  
    double ans = 1.0 ;  
    for(; n>0; x *= x, n>>=1)  
    {  
        if(n&1>0)  
            ans *= x;  
    }  
    return ans;  
}  

Ϊ����ȷ����x��n���ݣ�����Ҫ���ǵ�����һЩ�����
1) xȡֵΪ0ʱ��0������������1��������������û������ģ��ж�x�Ƿ����0����ֱ���á�==����
2) ����nȡֵINT_MINʱ��-n������INT_MAX����ʱ��Ҫ����С�ġ�
3) ����ʹ����λ����������������㣬�ӿ��㷨ִ�е��ٶȡ�

*/

#include <iostream>
using namespace std;

double myPow(double x, int n)
{
	if(n < 0)
	{
		if(n == INT_MIN)
			return 1.0/(myPow(x, INT_MAX) * x);
		else
			return 1.0/myPow(x, -n);
	}
	if(n == 0) return 1.0;
	double res = 1.0;
	for(; n>0; x*=x, n>>=1)
	{
		if(n&1>0) res *= x;
	}
	return res;
}

int main()
{
	cout << myPow(3214.5, 32) << endl;
	system("pause");
	return 0;
}