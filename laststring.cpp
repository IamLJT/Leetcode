#include<iostream>
#include<string>
using namespace std;
int main()
{
    char str[128];
    cout << "ÊäÈë×Ö·û´®:\n";
	cin.getline(str, 128);
	int i=strlen(str)-1, num=0;
	while(i>=0&&str[i]!=' ')
	{
		num++;
		i--;
	}
	cout<< num << endl;
	system("pause");
	return 0;
}