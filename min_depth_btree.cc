//求一个二叉树的最低高度
//递归求解，注意是到叶子的节点，所以递归必须要判断是不是叶子
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0; //空树的处理
        return m_depth(root);
    }
private:
    int m_depth(TreeNode *root){
        //判断是不是叶子节点，叶子节点单独处理
        if(root->left == NULL && root->right == NULL) //叶子节点的高度为1
            return 1;
        else if(root->left == NULL) //左孩子为空，则右孩子不空，为右孩子高度+1
            return m_depth(root->right) + 1;
        else if(root->right == NULL) //右孩子为空，则左孩子不空，为左孩子高度+1
            return m_depth(root->left) + 1;
        else    //左右孩子都不为空，则树高度为两个子树的高度较小者+1.
            return min(m_depth(root->left), m_depth(root->right)) + 1;
    }
};
