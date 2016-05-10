/*
��Ŀ��Longest Increasing Path in a Matrix
��ĿҪ��Given an integer matrix, find the length of 
the longest increasing path. From each cell, you can 
either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the 
boundary (i.e. wrap-around is not allowed).

��Ŀ���⣺��һ���������ҳ�һ����ĵ�����·����ֻ��
�������ҵ��ߣ�����б���ߡ�

˼·1���ӵ�һ��λ�ÿ�ʼ�������ж�����Χ��û�б������
����������ȥ�ߣ�����count+1��ֱ���Ҳ����ˣ���count��
max�Ƚϣ�max�������нϴ��ֵ��
*/
#include <iostream>
#include <vector>
using namespace std;

int max0=1;
int count0=1;

#define left 1
#define right 2
#define up 3
#define down 4

bool isOK(vector<vector<int>>& matrix, int line, int row, int der)
{
	switch(der)
	{
	case left:
		if(row-1>=0 && matrix[line][row]<matrix[line][row-1])
			return true;
		break;
	case right:
		if(row+1<=matrix[0].size-1 && matrix[line][row]<matrix[line][row+1])
			return true;
		break;
	case up:
		if(line-1>=0 && matrix[line][row]<matrix[line-1][row])
			return true;
		break;
	case down:
		if(line+1<=matrix.size()-1 && matrix[line][row]<matrix[line][row+1])
			return true;
		break;
	default:
		break;
	}
	return false;
}

int longestPath(vector<vector<int>>& matrix, int line, int row)
{
	int count;
	for(int i=1;i<=4;i++)
	{
		count=1;
		if(isOK(matrix, line, row, i))
		{
			switch(i)
			{
			case 1:
				count += longestPath(matrix, line, row-1);
				break;
			case 2:
				count += longestPath(matrix, line, row+1);
				break;
			case 3:
				count += longestPath(matrix, line-1, row);
				break;
			case 4:
				count += longestPath(matrix, line+1, row);
				break;
			}
		}
		else
			return count;
		if(max0<count) max0=count; 
	}
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[0].size(); j++)
		{
			longestPath(matrix, i, j);
		}
	}
	return max0;
}

