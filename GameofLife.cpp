/*
��Ŀ��Game of Life
Ҫ��According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the 
British mathematician John Horton Conway in 1970." Given a board with m by n cells, each cell has an initial state live (1) or 
dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken 
from the above Wikipedia article):
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

��Ŀ���⣺дһ��ʵ��������Ϸ�ĺ��������������ϸ������һ��״̬��Ҫ��ÿһ�����ŵ�ϸ����Χ�������2�����߶���3�����ŵ�ϸ������ô
���ͻ������������ϸ����Χ��ȷ��3�����ŵ�ϸ������ô���Ḵ��������ϸ����״̬���ֲ��䡣

˼·�������ؼ��ѵ����ڲ������µ���������Ÿı������飬��������λ�ñ���Ҫͬʱ���£������ȸ���һ���֣������Ѹ��µ�������ȥ����
���µ����飬�����ö����Ƹ�λ�ϵ���������Ѹ��µ�״̬���õ�λ����ʾԭ���ݣ������ǰ�ٽ���λ������ɡ�
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
				board[i][j] |= 2;		//	��������£���һ��״̬������
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