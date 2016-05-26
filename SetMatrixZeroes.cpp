/*
题目：Set Matrix Zeroes
要求：Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

题目大意：找出原数组中元素为0的位置，将它的行列所有元素设为0。

思路：m*n的空间使用是再新建一个数组去存放，m+n则是用两个数组记录下0的行与列，记录后
再将数组中标记的行列赋0即可。若是常数的话，则只需要用原数组的某一行、某一列记录住0
的位置，然后用1个变量记录这一列上是否有0即可。
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