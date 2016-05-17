/*
��Ŀ��Range Sum Query 2D
Ҫ��Given a 2D matrix, find the sum of the elements 
inside the rectangle defined by its upper left corner 
(row1, col1) and lower right corner (row2, col2).

��Ŀ���⣺һ����ά���飬������������㣬��������������
Χ�ɵĳ���������������֮�͡�

˼·����Ϊ��ܶ�εĵ��ü��㺯���������ڼ��㺯���в�Ӧ
�����ظ����㣬��ô�Ϳ����뵽��ÿһ�����η�Χ����������
��б���ϵĶ����������Χ�����η�Χ֮�ͼ�ȥ��һб�߶���
�������Χ�����η�Χ�ͣ���ô�Ϳ��Լ��ٺܶ��ظ��ļ��㡣
*/

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
		row = matrix.size();
		col = row>0 ? matrix[0].size() : 0;
		matrix_sum = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<row+1; i++)
			for(int j=1; j<col+1; j++)
				matrix_sum[i][j] = matrix[i-1][j-1] + matrix_sum[i-1][j]
								+ matrix_sum[i][j-1] - matrix_sum[i-1][j-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
		return matrix_sum[row2+1][col2+1] + matrix_sum[row1][col1]
		- matrix_sum[row1][col2+1] - matrix_sum[row2+1][col1];
    }
private:
	int row, col;
	vector<vector<int>> matrix_sum;
};

int main()
{
	int num[][5] = {{3, 0, 1, 4, 2},
					{5, 6, 3, 2, 1},
					{1, 2, 0, 1, 5},
					{4, 1, 0, 1, 7},
					{1, 0, 3, 0, 5}};
					
	vector<vector<int>> matrix;
	for(int i=0; i<sizeof(num)/sizeof(num[0]); i++)
		matrix.push_back(vector<int>(num[i], num[i]+sizeof(num[i])/sizeof(int)));
	NumMatrix nummatrix(matrix);
	cout << nummatrix.sumRegion(2,1,4,3) << endl;
	system("pause");
	return 0;
}