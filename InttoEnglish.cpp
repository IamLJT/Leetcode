#include <iostream>
#include <string>

using namespace std;
string numberToWords(int num) 
{
	char *numwords[] = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
					"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
					"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string result = "", result0 = "";
	int flag = 0, n0 = 0;
	if(num==0) return "Zero";
	while(num)
	{
	    if(num%1000 && num/1000) result0 += " ";
		int n = num%1000;
		n0 = n;
		if(n0/100)
		{
			result0 += numwords[n/100];
			result0 += " Hundred";
			n0 %= 100;
			if(n0)
			    result0 += " ";
		}
		if(n0/10>1)
		{
			result0 += numwords[n0/10+18];
			n0 %= 10;
			if(n0)
			{
				result0 += " ";
				result0 += numwords[n0];
			}
		}
		else if(n0/10 <= 1 && n0 != 0)
		{
			result0 += numwords[n0];
		}
		if(result0 != "")
		{
			if(flag==1) result0 += " Thousand";
			if(flag==2) result0 += " Million";
			if(flag==3) result0 += " Billion";
		}
		flag++;
		num /= 1000;
		result = result0 + result;
		result0 = "";
	}
	return result;
}

int main()
{
	int num = 3450;
	cout << "Output: " << numberToWords(num) << endl;
	system("pause");
	return 0;
}