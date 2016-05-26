/*
题目：Game of Life
要求：According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the 
British mathematician John Horton Conway in 1970." Given a board with m by n cells, each cell has an initial state live (1) or 
dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken 
from the above Wikipedia article):
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

题目大意：写一个实现生命游戏的函数，求出数组中细胞的下一个状态，要求，每一个活着的细胞周围如果少于2个或者多于3个活着的细胞，那么
它就会死，如果死的细胞周围有确定3个活着的细胞，那么它会复活，其他情况细胞的状态保持不变。

思路：这道题关键难点在于不能用新的数组来存放改变后的数组，而且所有位置必须要同时更新，不能先更新一部分，再用已更新的数组再去更新
余下的数组，可以用二进制高位上的数来存放已更新的状态，用低位数表示原数据，在输出前再将低位清除即可。
*/

#include <iostream>
#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board) 
{
	int m=board.size();
	int n=m ? board[0].size() : 0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			int count=0;
			for(int a=max(i-1,0); a<min(i+2, m); a++)
				for(int b=max(j-1,0); b<min(j+2, n); b++)
					count += board[a][b] & 1;
			if(count==3 || count-board[i][j]==3)
				board[i][j] |= 2;		//	其他情况下，下一个状态都是死
		}
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			board[i][j] >>= 1;
}

void disp(vector<vector<int>> board)
{
	for(int i=0; i<board.size(); i++)
	{
		for(int j=0; j<board[i].size(); j++)
			cout << board[i][j];
		cout << endl;
	}
}

int main()
{
	int board0[][5] = {1,0,1,0,1,
					1,1,0,1,1,
					0,1,0,1,0,
					0,1,1,1,0};
	vector<vector<int>> board;
	for(int i=0; i<sizeof(board0)/sizeof(board0[0]); i++)
		board.push_back(vector<int>(board0[i], board0[i]+sizeof(board0[i])/sizeof(int)));
	disp(board);
	gameOfLife(board);
	disp(board);
	system("pause");
	return 0;
}