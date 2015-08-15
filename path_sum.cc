//给定一个数和一个二叉树，求树中是否存在一个从根到叶子的路径，使得路径上的
// 所有节点的和为给定的这个数

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //二叉树的题目基本上都可以用递归来求解
 //递归求解，注意必须是由根到叶子节点的路径，所以一定要判断是否为叶子节点
#include <iostream>
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false; //树为空，单独处理

        return find_path(root, sum);
    }
private:
    bool find_path(TreeNode *root, int sum){
        //为叶子节点，并且值恰好对上，则返回true
        if(root->left ==  NULL && root->right == NULL && root->val == sum)
            return true;
        //如果左孩子不为空，则尝试左孩子
        if(root->left && find_path(root->left, sum - root->val)) return true;
        //如果右孩子不为空，则尝试右孩子
        if(root->right && find_path(root->right, sum - root->val)) return true;
        return false; //此子路断掉
    }
};
