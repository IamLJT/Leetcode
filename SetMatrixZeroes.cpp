/*
��Ŀ��Set Matrix Zeroes
Ҫ��Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

��Ŀ���⣺�ҳ�ԭ������Ԫ��Ϊ0��λ�ã���������������Ԫ����Ϊ0��

˼·��m*n�Ŀռ�ʹ�������½�һ������ȥ��ţ�m+n���������������¼��0�������У���¼��
�ٽ������б�ǵ����и�0���ɡ����ǳ����Ļ�����ֻ��Ҫ��ԭ�����ĳһ�С�ĳһ�м�¼ס0
��λ�ã�Ȼ����1��������¼��һ�����Ƿ���0���ɡ�
*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
	int m=matrix.size();
	int n=m ? matrix[0].size() : 0;
	int col0=1;
	for(int i=0; i<m; i++)
	{
		if(matrix[i][0]==0) col0=0;
		for(int j=1; j<n; j++)
		{
			if(matrix[i][j]==0)
				matrix[i][0]=matrix[0][j]=0;
		}
	}
	for(int i=m-1; i>=0; i--)
	{
		for(int j=n-1; j>=1; j--)
		{
			if(matrix[i][0]==0||matrix[0][j]==0)
				matrix[i][j]=0;
		}
		if(col0==0) matrix[i][0]=0;
	}
}

void disp(vector<vector<int>> matrix)
{
	int m=matrix.size();
	int n=m ? matrix[0].size() : 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int nums[][3] = {1,1,1,
					0,1,1};
	vector<vector<int>> matrix;
	for(int i=0; i<sizeof(nums)/sizeof(nums[0]); i++)
		matrix.push_back(vector<int>(nums[i], nums[i]+sizeof(nums[i])/sizeof(int)));
	disp(matrix);
	setZeroes(matrix);
	cout << endl;
	disp(matrix);
	cout << endl;
	system("pause");
	return 0;
}