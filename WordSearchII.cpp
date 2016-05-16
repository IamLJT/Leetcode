/*
��Ŀ��Word Search II
Ҫ��Given a 2D board and a list of words from the dictionary, find all 
words in the board. Each word must be constructed from letters of 
sequentially adjacent cell, where "adjacent" cells are those horizontally 
or vertically neighboring. The same letter cell may not be used more than 
once in a word.

��Ŀ���⣺��һ����ά���ʰ����ҳ����е��ֵ����еĵ��ʣ�Ҫ��ÿ���������ɰ�
��������ĸ��ɵģ�ͬһ����ĸ��Ԫ������ͬһ���������ظ�ʹ�á�

˼·������һ����������ṹ������ֵ���ĵ��ʣ�Ȼ��ӵ��ʱ���һ��һ����ȥ�ң�
�ҵ�ƥ��ĵ��ʺ󣬽���λ���ϵ���ĸ���������������ո���棬�ٴ�ÿ����ĸ����
��λ�ü���Ѱ�ң�ֱ���ҵ����һ����ĸ��
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
	set<string> result_set;		//	��֤��ͬ����ֻ����һ��
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