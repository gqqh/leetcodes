//判断一个二叉树是否是高度平衡的，也就是任意一个节点的左右孩子高度差不超过1
//使用递归求解，如果根为空则返回ture，否则，如果左孩子和右孩子的高度差大于1，
//则返回false，否则，分别判断两个孩子是否平衡，如果都平衡，则该节点也平衡。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(get_path(root->left) - get_path(root->right)) > 1)
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
private:
    int get_path(TreeNode *root){
        if(root == NULL)
            return 0;
        else
            return (max(get_path(root->left), get_path(root->right)) + 1);
    }
};
