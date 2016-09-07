/*
��Ŀ��Lexicographical Numbers
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> lexicalOrder(int n)
{
	int num=0;			//	����n��λ��
	int n0=n;
	vector<int> n_num;	//	����ÿһλ�ϵ�����
	vector<int> res;	//	��¼�ź��������
	while(n0)
	{
		num++;
		n_num.push_back(n0%10);
		n0/=10;
	}
//	reverse(n_num.begin(), n_num.end());
	if(num<=1)
	{
		int i=1;
		while(i<=n)
			res.push_back(i++);
		return res;
	}
	for(int i=1; i<=9; i++)
	{
		if(i==(n/((int)pow(10, num-1))))
		{
			res.push_back(i);
			for(int j=1; j<num-1; j++)
			{
				for(int k=0; k<(int)pow(10, j); k++)
					res.push_back(i*(int)pow(10,j)+k);
			}
			for(int k=0; k<=(n%((int)(pow(10, num-1)))); k++)
				res.push_back(i*(int)pow(10, num-1)+k);
		}
		else if(i<(n/((int)pow(10, num-1))))
		{
			res.push_back(i);
			for(int j=1; j<num; j++)
			{
				for(int k=0; k<(int)pow(10, j); k++)
					res.push_back(i*(int)pow(10,j)+k);
			}
		}
		else
		{
			res.push_back(i);
			for(int j=1; j<num-1; j++)
			{
				for(int k=0; k<(int)pow(10, j); k++)
					res.push_back(i*(int)pow(10,j)+k);
			}
		}
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> res=lexicalOrder(n);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}