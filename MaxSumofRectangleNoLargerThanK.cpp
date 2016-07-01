/*
题目：Max Sum of Rectangle No Larger Than K
要求：Given a non-empty 2D matrix matrix and an integer k, find the max sum 
of a rectangle in the matrix such that its sum is no larger than k.

题目大意：找出二维矩阵中任意矩形元素和最大不超过k的值。

思路1：从第一个元素开始遍历，找出从每个元素开始的矩阵的和的最大值，最后再找出
所有最大值中的最大值。(算法复杂度过高，为O((mn)^2)，空间复杂度O(m*n))

思路2：对于求数组中最大范围和的问题，可以类似于求解一维中最大和的问题，可以将
所有的行可取到的范围的和求出组成一个新的数组，对这个数组只需要按照一维的最大和
来求即可，同样，在这个问题中，只需要再增加一个条件为低于K即可，将得到的和每次
插入到数组中，并且每次查找时寻找第一个>=Sum-k的值，如果这个值存在则比较Sum-*it
这个值和已有的最大值谁比较大。具体代码如下：
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
{
	if(matrix.size()==0) return 0;
	int r=matrix.size(), c=matrix[0].size();
	/*
	int max=INT_MIN, temp=0;
	
	vector<vector<int>> matrix_sum(r+1, vector<int>(c+1,0));

	for(int i=1; i<=r; i++)
		for(int j=1; j<=c; j++)
		{
			matrix_sum[i][j]=matrix[i-1][j-1]+matrix_sum[i][j-1]+matrix_sum[i-1][j]-matrix_sum[i-1][j-1];
		}

	for(int i=1; i<=r; i++)
		for(int j=1; j<=c; j++)
		{
			for(int a=i-1; a>=0; a--)
				for(int b=j-1; b>=0; b--)
				{
					if(matrix_sum[i][j]>matrix_sum[a][b])
						temp = matrix_sum[i][j]-matrix_sum[a][j]-matrix_sum[i][b]+matrix_sum[a][b];
					if(temp<=k)
						max = max > temp ? max : temp;
				}
		}
	return max;
	*/
	int res=INT_MIN;
	for(int i=0; i<c; i++)
	{
		vector<int> sums(r, 0);
		for(int j=i; j<c; j++)
		{
			for(int t=0; t<r; ++t)
				sums[t] += matrix[t][j];

			set<int> accuSet;
			accuSet.insert(0);
			int curSum=0, curMax=INT_MIN;
			for(int sum:sums)
			{
				curSum += sum;
				set<int>::iterator it = accuSet.lower_bound(curSum-k);
				if(it!=accuSet.end()) curMax=max(curMax, curSum-*it);
				accuSet.insert(curSum);
			}
			res=max(res, curMax);
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> num;
	int num0[2][3]={{1,2,3},{2,3,5}};
	for(int i=0; i<sizeof(num0)/sizeof(num0[0]); i++)
		num.push_back(vector<int>(num0[i],num0[i]+sizeof(num0[i])/sizeof(int)));
	cout << maxSumSubmatrix(num, 2) << endl;
	system("pause");
	return 0;
}