/*
题目：Search a 2D Matrix II
要求：Write an efficient algorithm that searches for a value in 
an m * n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

题目大意：从一个行与列都有序的二维数组中搜索某个数。

思路1：从对角线开始搜索，因为有可能m不等n，则当搜索到边上时继续沿
着边继续比较，知道找到第一个大于这个数的位置，再分别二分搜索两边
的数即可。

思路2：从最后一列第一行开始比较，若比它大则行+1，比它小则列-1。
*/

#include <iostream>
#include <vector>
using namespace std;
/*
bool findrow(vector<int> list, int target, int low, int high)
{
	if(low>high) return false;
	int mid=(low+high)/2;
	if(target==list[mid])
		return true;
	if(target>list[mid])
		return findrow(list, target, mid+1, high);
	if(target<list[mid])
		return findrow(list, target, low, mid-1);
	return false;
}

bool findline(vector<vector<int>> matrix, int line, int target, int low, int high)
{
	if(low>high) return false;
	int mid=(low+high)/2;
	if(target==matrix[mid][line])
		return true;
	if(target>matrix[mid][line])
		return findline(matrix, line, target, mid+1, high);
	if(target<matrix[mid][line])
		return findline(matrix, line, target, low, mid-1);
	return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	int row=0, line=0;
	if(matrix.size()==0) return false;
	while(row<matrix.size()-1 && line<matrix[0].size()-1)
	{
		if(matrix[row][line]>=target)
			break;
		else
		{
			if(row<matrix.size()-1) row++;
			if(line<matrix[0].size()-1) line++;
		}
	}
	if(row==matrix.size()-1 && line==matrix[0].size()-1 && matrix[row][line]<target)
		return false;
	if(matrix[row][line]==target) return true;
	if(findrow(matrix[row], target, 0, line)||findline(matrix, line, target, 0, row))
		return true;
	return false;
}
*/
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.size()==0) return false;
    int row=0, line=matrix[0].size()-1;
    while(row<matrix.size()&&line>=0)
    {
        if(target==matrix[row][line])
            return true;
        else if(target<matrix[row][line])
            line--;
        else
            row++;
    }
    return false;
}