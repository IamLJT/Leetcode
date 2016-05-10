/*	规则
(1)基本数字 Ⅰ、X 、C 中的任何一个、自身连用构成数目、或者放在大数的右边连用构成数目、都不能超过三个；放在大数的左边只能用一个；
(2)不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目、只能使用一个；
(3)V 和 X 左边的小数字只能用 Ⅰ；
(4)L 和 C 左边的小数字只能用 X；
(5)D 和 M 左边的小数字只能用 C。
*/
#include <iostream>
#include <string>

using namespace std;
string intToRoman(int num) 
{
	char *roman[] = {
		"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",	// 0-9
		"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",	// 10-90
		"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",	// 100-900
		"", "M", "MM", "MMM"	// 1000-3000
	};
	string Result = "";
	int digit = 0;
	while(num != 0)
	{
		int remain = num % 10;
		Result = roman[digit*10+remain] + Result;
		digit++;
		num /= 10;
	}
	return Result;
}

int main()
{
	int n = 621;
	cout << "Output: " << intToRoman(n) << endl;
	system("pause");
	return 0;
}