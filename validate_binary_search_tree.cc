//给定一个二叉树，判断这个二叉树是否是一个合法的二叉搜索树
//BST的定义是，一个节点的左孩子都不大于它的值，右孩子的都不小于它

//递归，DFS
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
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        long long int min = INT_MIN-1;
        long long int max = INT_MAX+1;

        return is_valid(root->left, min, root->val) &&
                is_valid(root->right, root->val, max);
    }
private:
    bool is_valid(TreeNode* root, long long int min, long long int max){
        if(root == NULL) return true;
        //当前节点符合，判断下一个节点
        if(root->val < max && root->val > min)
            return is_valid(root->left, min, root->val) &&
                    is_valid(root->right, root->val, max);
        else
            return false;
    }
};
