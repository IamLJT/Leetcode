/*
��Ŀ��Bulls and Cows
Ҫ��You are playing the following Bulls and Cows 
game with your friend: You write down a number and 
ask your friend to guess what the number is. Each 
time your friend makes a guess, you provide a hint 
that indicates how many digits in said guess match 
your secret number exactly in both digit and position 
(called "bulls") and how many digits match the secret 
number but locate in the wrong position (called "cows").
Your friend will use successive guesses and hints 
to eventually derive the secret number.

��Ŀ���⣺��������Ϸ������һ��������������Ѳ£��ٶ�
���Ѳµ����ָ�����ʾ����ʾΪxAxB��A��ʾ�м�������λ
���ǶԵģ�B��ʾ�м�������A���е���λ�ô��ˡ�

˼·�������������洢A��B�ĸ���������һ�����ƹ�ϣ���
�ṹ�洢�����ַ�����ĳ�����ֳ��ֵ�λ�ã��ٽ������ַ�
�������ֱ���һ�飬���������������е����ݲ�Ϊ�գ��ٱ�
�����е�λ�ã���������������B++������������A++��
��������ڱ����ظ����ֵ�ʱ���е����⡣

˼·2�������������������ַ����������ַ����в���Ӧ��
���ֵĸ�������Ӧ�Ļ���A++������Ӧ�Ļ����������У�
����ٱ������������ÿ�����֣�ÿ�����ֶ�Ӧ����������
�ļ�Сֵ��������Bֵ��
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
/*
string getHint(string secret, string guess)
{
	int A=0, B=0;
	string res="";
	vector<vector<int>> num(10,vector<int>(1,0));
	for(int i=0; i<secret.size(); i++)
	{
		num[secret[i]-'0'].push_back(i);
		num[secret[i]-'0'][0]++;
	}
	for(int i=0; i<guess.size(); i++)
	{
		if(num[guess[i]-'0'][0])
		{
			B++;
			for(int k=1; k<num[guess[i]-'0'].size(); k++)
			{
				if(i==num[guess[i]-'0'][k])
				{
					A++;
					B--;
					break;
				}
			}
			num[guess[i]-'0'][0]--;
		}
	}
	res = char(A+'0');
	res += "A";
	res +=char(B+'0');
	res += "B";
	return res;
}
*/

string getHint(string secret, string guess)
{
	vector<int> S_num(10,0);
	vector<int> G_num(10,0);
	int A=0, B=0;
	string res="";
	if(secret.size()!=guess.size() || secret.size()==0)
		return res;
	for(int i=0; i<secret.size(); i++)
	{
		if(secret[i]==guess[i])
			A++;
		else
		{
			S_num[secret[i]-'0']++;
			G_num[guess[i]-'0']++;
		}
	}
	for(int i=0; i<S_num.size(); i++)
		B += min(S_num[i], G_num[i]);
	res = to_string(A) + 'A' + to_string(B) + 'B';
	return res;
}

int main()
{
	string res = getHint("1780", "0187");
	cout << res << endl;
	system("pause");
	return 0;
}