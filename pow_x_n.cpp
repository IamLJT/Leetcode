/*
题目：Pow(double x, int n)

1)最直观容易想到的方法就是用递归方法求n个x的乘积，注意考虑n的正负号，时间复杂度为O(n)

[cpp] view plain copy
double pow(double x, int n)  
{  
    if(n==0)  
        return 1.0;  
    if(n<0)  
        return 1.0/pow(x,-n);  
    return x*pow(x,n-1);  
}  

2)考虑到n个x相乘式子的对称关系，可以对上述方法进行改进，从而得到一种时间复杂度为O(logn)的方法，递归关系可以表示为pow(x,n) = pow(x,n/2)*pow(x,n-n/2)
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
3)除了上述方法，这里还提到了一种十分巧妙并且快速的方法，原文描述如下：

Consider the binary representation of n. For example, if it is "10001011", then x^n = x^(1+2+8+128) = x^1 * x^2 * x^8 * x^128. Thus, we don't want to loop n times to calculate x^n. To speed up, we loop through each bit, if the i-th bit is 1, then we add x^(1 << i) to the result. Since (1 << i) is a power of 2, x^(1<<(i+1)) = square(x^(1<<i)). The loop executes for a maximum of log(n) times.
该方法通过扫描n的二进制表示形式里不同位置上的1，来计算x的幂次

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

为了正确计算x的n次幂，还需要考虑到以下一些情况：
1) x取值为0时，0的正数次幂是1，而负数次幂是没有意义的；判断x是否等于0不能直接用“==”。
2) 对于n取值INT_MIN时，-n并不是INT_MAX，这时需要格外小心。
3) 尽量使用移位运算来代替除法运算，加快算法执行的速度。

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