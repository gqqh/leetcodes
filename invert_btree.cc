#include <iostream>

using namespace std;
/*
 * Invert a binary tree.
 *
 *       4
 *     /   \
 *    2     7
 *   / \   / \
 *  1   3 6   9
 *
 * to
 *       4
 *     /   \
 *    7     2
 *   / \   / \
 *  9   6 3   1
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(root == NULL)
			return root;
		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

int main()
{
	Solution test;
	
	return 0;
}
