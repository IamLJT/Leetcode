/*	����
(1)�������� ��X ��C �е��κ�һ�����������ù�����Ŀ�����߷��ڴ������ұ����ù�����Ŀ�������ܳ������������ڴ��������ֻ����һ����
(2)���ܰѻ������� V ��L ��D �е��κ�һ����ΪС�����ڴ�������߲�������ķ���������Ŀ�����ڴ������ұ߲�����ӵķ�ʽ������Ŀ��ֻ��ʹ��һ����
(3)V �� X ��ߵ�С����ֻ���� ��
(4)L �� C ��ߵ�С����ֻ���� X��
(5)D �� M ��ߵ�С����ֻ���� C��
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