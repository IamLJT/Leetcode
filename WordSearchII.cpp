/*
题目：Word Search II
要求：Given a 2D board and a list of words from the dictionary, find all 
words in the board. Each word must be constructed from letters of 
sequentially adjacent cell, where "adjacent" cells are those horizontally 
or vertically neighboring. The same letter cell may not be used more than 
once in a word.

题目大意：从一个二维单词板上找出所有的字典中有的单词，要求每个单词是由板
上相邻字母组成的，同一个字母单元不能在同一个单词中重复使用。

思路：建立一个树形数组结构，存放字典里的单词，然后从单词表中一个一个的去找，
找到匹配的单词后，将此位置上的字母保存起来，并赋空格代替，再从每个字母的相
邻位置继续寻找，直到找到最后一个字母。
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class TrieNode
{
public:
	bool is_end;
	vector<TrieNode*> children;
	TrieNode()
	{
		is_end = false;
		children = vector<TrieNode*>(26, NULL);
	}
};

class Trie
{
private:
	TrieNode* root;
public:
	TrieNode* getRoot() {return root;}
	Trie(vector<string>& words)
	{
		root = new TrieNode();
		for(int i=0; i<words.size(); i++)
			addWord(words[i]);
	}
	void addWord(const string& word)
	{
		TrieNode* cur = root;
		for(int i=0; i<word.size(); i++)
		{
			int index = word[i] - 'a';
			if(cur->children[index]==NULL)
				cur->children[index]=(TrieNode*)new TrieNode();
			cur=cur->children[index];
		}
		cur->is_end = true;
	}
};

void findWord(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result)
{
	if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]==' ')
		return;
	if(root->children[board[x][y]-'a']!=NULL)
	{
		word=word+board[x][y];
		root=root->children[board[x][y]-'a'];
		if(root->is_end) result.insert(word);
		char c=board[x][y];
		board[x][y]=' ';
		findWord(board, x+1, y, root, word, result);
		findWord(board, x-1, y, root, word, result);
		findWord(board, x, y+1, root, word, result);
		findWord(board, x, y-1, root, word, result);
		board[x][y]=c;
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
	Trie* trie = new Trie(words);
	TrieNode* root = trie->getRoot();
	set<string> result_set;		//	保证相同单词只出现一次
	for(int x=0; x<board.size(); x++)
		for(int y=0; y<board[0].size(); y++)
			findWord(board, x, y, root, "", result_set);

	vector<string> result;
	for(auto it:result_set) result.push_back(it);
	return result;
}

int main()
{
	char* board0[] = {"oaan","etae","ihkr","iflv"};
	string word0[] = {"oath","pea","eat","rain"};
	vector<vector<char>> board;
	int len = sizeof(board0)/sizeof(board0[0]);
	for(int i=0; i<len; i++)
		board.push_back(vector<char>(board0[i], board0[i]+sizeof(board0[i])/sizeof(char)));
	vector<string> word(word0, word0+sizeof(word0)/sizeof(string));
	vector<string> res;
	res = findWords(board, word);
	if(res.size())
		cout << res[0];
	for(int i=1; i<res.size(); i++)
		cout << " " << res[i];
	cout << endl;
	system("pause");
	return 0;
}