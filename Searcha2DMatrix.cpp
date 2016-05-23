/*
题目：Search a 2D Matrix
要求：Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

题目大意：从一个二维有序矩阵中搜索某个数。

大意：可以先找行，再找列。
*/

#include <iostream>
#include <vector>
using namespace std;

int rowfind(vector<vector<int>>& matrix, int target/*, int low, int high*/)
{
   /* int mid = (low + high)/2;
	if(low>high) return -1;
	else if(low==high)
	{
		if(matrix[mid][0]<=target)
			return mid;
		else
			return -1;
	}
	else if(matrix[mid][0]>target)
		return rowfind(matrix, target, low, mid);
    else if(matrix[mid][0]<=target)
		return rowfind(matrix, target, mid, high);*/
	int i=0;
	for(i=0; i<matrix.size(); i++)
	{
		if(matrix[i][0]>target)
			return i-1;
	}
	return i-1;
}
int linefind(vector<int> list, int target, int low, int high)
{
	if(low>high) return -1;
	int mid=(low+high)/2;
	if(low==high)
	{
		if(target==list[mid])
			return mid;
		else
			return -1;
	}
	if(target==list[mid])
		return mid;
	else if(target>list[mid])
		return linefind(list, target, mid+1, high);
	else if(target<list[mid])
		return linefind(list, target, low, mid-1);
}
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	int row=rowfind(matrix, target);
	if(row==-1)
		return false;
	else
	{
		if(linefind(matrix[row], target, 0, matrix[row].size()-1)>=0)
			return true;
		else
			return false;
	}
}

int main()
{
	vector<vector<int>> matrix;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	matrix.push_back(temp);
	cout << searchMatrix(matrix, 2) << endl;
	system("pause");
	return 0;
}