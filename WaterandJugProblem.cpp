/*
题目：Water and Jug Problem
要求：You are given two jugs with capacities x and y litres. There is an infinite 
amount of water supply available. You need to determine whether it is possible to 
measure exactly z litres using these two jugs.If z liters of water is measurable, 
you must have z liters of water contained within one or both buckets by the end.
Operations allowed:
Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the 
first jug itself is empty.

题目大意：用x、y体积的两个水壶来测量出z体积。

思路：本题的解法在于求出x、y的最大公约数，如果z能整除此最大公约数，则是能测量出的，
反之则无法测出，最大公约数使用的是欧几里得算法求解。（至于为什么就不知道了，没想通）
*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

bool canMeasureWater(int x, int y, int z)
{
	if(z > x + y) return false;
	if(gcd(x, y))
	    return z % gcd(x, y) == 0;
	else
	    return z==0 ? true : false;
}

int main()
{
	cout << canMeasureWater(2, 6, 5) << endl;
	system("pause");
	return 0;
}
