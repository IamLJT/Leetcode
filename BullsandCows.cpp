/*
题目：Bulls and Cows
要求：You are playing the following Bulls and Cows 
game with your friend: You write down a number and 
ask your friend to guess what the number is. Each 
time your friend makes a guess, you provide a hint 
that indicates how many digits in said guess match 
your secret number exactly in both digit and position 
(called "bulls") and how many digits match the secret 
number but locate in the wrong position (called "cows").
Your friend will use successive guesses and hints 
to eventually derive the secret number.

题目大意：猜数字游戏，给出一串数字让你的朋友猜，再对
朋友猜的数字给出暗示，暗示为xAxB，A表示有几个数字位
置是对的，B表示有几个数字A中有但是位置错了。

思路：用两个变量存储A和B的个数，再用一个类似哈希表的
结构存储所给字符串中某个数字出现的位置，再将所猜字符
串的数字遍历一遍，若遍历到的数字中的内容不为空，再遍
历其中的位置，若遍历不到，则将B++，若遍历到则将A++。
这个方法在遍历重复数字的时候有点问题。

思路2：用两个数组存放所给字符串和所猜字符串中不对应的
数字的个数，对应的话则将A++，不对应的话则存进数组中，
最后再遍历所猜数组的每个数字，每个数字对应于两个数字
的极小值即是它的B值。
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