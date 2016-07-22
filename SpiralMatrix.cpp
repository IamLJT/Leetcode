/*
题目：Spiral Matrix
要求：Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.
*/


#include <iostream>
#include <vector>
using namespace std;

bool isnotfound(vector<vector<int>>matrix, int i, int j)
{
    int row=matrix.size(), col;
    if(row) col=matrix[0].size();
    if(matrix[max(0,i-1)][j]==INT_MAX&&matrix[min(row-1,i+1)][j]==INT_MAX
    &&matrix[i][max(0,j-1)]==INT_MAX&&matrix[i][min(col-1,j+1)]==INT_MAX)
        return false;
    return true;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int i=0,j=0,dic=0;
    vector<int> res;
    int row=matrix.size(), col;
    if(row) col=matrix[0].size();
    if(row==0) return res;
	res.push_back(matrix[0][0]);
	matrix[0][0]=INT_MAX;
    while(isnotfound(matrix,i,j))
    {
        dic=dic%4;
        if(dic==0)
        {
			j++;
            while(j<col&&matrix[i][j]!=INT_MAX)
            {
                res.push_back(matrix[i][j]);
                matrix[i][j++]=INT_MAX;
            }
			j--;
            dic++;
        }
        else if(dic==1)
        {
			i++;
            while(i<row&&matrix[i][j]!=INT_MAX)
            {
                res.push_back(matrix[i][j]);
                matrix[i++][j]=INT_MAX;
            }
			i--;
            dic++;
        }
        else if(dic==2)
        {
			j--;
            while(j>=0&&matrix[i][j]!=INT_MAX)
            {
                res.push_back(matrix[i][j]);
                matrix[i][j--]=INT_MAX;
            }
			j++;
            dic++;
        }
        else if(dic==3)
        {
			i--;
            while(i>=0&&matrix[i][j]!=INT_MAX)
            {
                res.push_back(matrix[i][j]);
                matrix[i--][j]=INT_MAX;
            }
			i++;
            dic++;
        }
    }
    return res;
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int>> num(m, vector<int>(n,0));
	vector<int> res;
	for(int i=0;i<m;i++)
		for(int j=0; j<n; j++)
			cin >> num[i][j];
	res=spiralOrder(num);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << " " << endl;
	system("pause");
	return 0;
}