/*
��Ŀ��Max Sum of Rectangle No Larger Than K
Ҫ��Given a non-empty 2D matrix matrix and an integer k, find the max sum 
of a rectangle in the matrix such that its sum is no larger than k.

��Ŀ���⣺�ҳ���ά�������������Ԫ�غ���󲻳���k��ֵ��

˼·1���ӵ�һ��Ԫ�ؿ�ʼ�������ҳ���ÿ��Ԫ�ؿ�ʼ�ľ���ĺ͵����ֵ��������ҳ�
�������ֵ�е����ֵ��(�㷨���Ӷȹ��ߣ�ΪO((mn)^2)���ռ临�Ӷ�O(m*n))

˼·2�����������������Χ�͵����⣬�������������һά�����͵����⣬���Խ�
���е��п�ȡ���ķ�Χ�ĺ�������һ���µ����飬���������ֻ��Ҫ����һά������
���󼴿ɣ�ͬ��������������У�ֻ��Ҫ������һ������Ϊ����K���ɣ����õ��ĺ�ÿ��
���뵽�����У�����ÿ�β���ʱѰ�ҵ�һ��>=Sum-k��ֵ��������ֵ������Ƚ�Sum-*it
���ֵ�����е����ֵ˭�Ƚϴ󡣾���������£�
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