/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//判断一个二叉树是否是关于中心对称，从根往两边遍历，
//左边的左孩子和右边的右孩子比较
 #include <iostream>
 struct TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return comp_b(root->left, root->right);
    }
private:
    bool comp_b(TreeNode *l, TreeNode *r){
        if(l == NULL && r == NULL) return true;
        if(l != NULL && r != NULL && l->val == r->val &&
                comp_b(l->left, r->right) &&
                comp_b(l->right, r->left))
            return true;
        return false;
    }
};
