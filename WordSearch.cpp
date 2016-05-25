/*
题目：Word Search
要求：Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

题目大意：给一个二维单词板和一个单词，在单词板上寻找此单词是否存在，单词
中的字母在单词板上只能往相邻的位置查找，并且已经出现过的字母不能再次使用。

思路：还是用深度遍历查找，每找到一个字母，则在它的相邻位置继续查找，并要
把已找过的位置进行标记。
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