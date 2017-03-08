/*************************************************************/
/* 题目: Minimun Absolute Difference in BST				     */
/* 要求: Given a binary search tree with non-negative values,*/
/*       find the minimum absolute difference between values */
/*       of any two nodes.                                   */
/*************************************************************/
/*************************************************************/
/* Data: 2017/03/07                                          */
/*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Inorder(TreeNode *root, vector<int>& nodeVal);
int getMinimumDifference(TreeNode *root);
void insert(TreeNode*& root, int val);

int main()
{
	// 以前序遍历插入值
	TreeNode* root = NULL;
	int val;
	
	while (cin >> val) {
		insert(root, val);
	}
	cout << getMinimumDifference(root) << endl;

	system("pause");
	return 0;
}

void insert(TreeNode*& root, int val)
{
	TreeNode *node = new TreeNode(val);
	if (root == NULL) {
		root = node;
		return;
	}
	//TreeNode *tmp = root;
	if (root != NULL) {
		if (root->val > val)
			insert(root->left, val);
		else if (root->val < val)
			insert(root->right, val);
		else
			return;
	}	
}

// 直接中序遍历一遍即可
void Inorder(TreeNode *root, vector<int>& nodeVal)
{
	if (root == NULL)
		return;
	Inorder(root->left, nodeVal);
	nodeVal.push_back(root->val);
	Inorder(root->right, nodeVal);
}

int getMinimumDifference(TreeNode *root)
{
	vector<int> nodeVal;
	Inorder(root, nodeVal);
	int min = INT_MAX;
	for (int i = 1; i < nodeVal.size(); ++i) {
		if (min > nodeVal[i] - nodeVal[i - 1])
			min = nodeVal[i] - nodeVal[i - 1];
	}
	return min;
}