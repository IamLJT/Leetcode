/*
��Ŀ��Word Search
Ҫ��Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

��Ŀ���⣺��һ����ά���ʰ��һ�����ʣ��ڵ��ʰ���Ѱ�Ҵ˵����Ƿ���ڣ�����
�е���ĸ�ڵ��ʰ���ֻ�������ڵ�λ�ò��ң������Ѿ����ֹ�����ĸ�����ٴ�ʹ�á�

˼·����������ȱ������ң�ÿ�ҵ�һ����ĸ��������������λ�ü������ң���Ҫ
�����ҹ���λ�ý��б�ǡ�
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool DFS(vector<vector<char>>& board, const char *pos, int x, int y)
{
	if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]=='\0'||*pos!=board[x][y])
		return false;
	if(*(pos+1)=='\0') return true;
	char temp=board[x][y];
	board[x][y]='\0';
	if(DFS(board, pos+1, x-1, y)||
		DFS(board, pos+1, x+1, y)||
		DFS(board, pos+1, x, y-1)||
		DFS(board, pos+1, x, y+1))
	return true;
	board[x][y]=temp;
	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	for(int i=0; i<board.size(); i++)
		for(int j=0; j<board[0].size(); j++)
			if(DFS(board, word.c_str(), i, j))
				return true;
	return false;
}

int main()
{
	char *board0[] = {"ABCS", "SDRF", "DSRE"};
	vector<vector<char>> board;
	for(int i=0; i<sizeof(board0)/sizeof(board0[0]);i++)
		board.push_back(vector<char>(board0[i], board0[i]+sizeof(board0[i])/sizeof(char)));
	cout << exist(board, "ABCRDS") << endl;
	system("pause");
	return 0;
}