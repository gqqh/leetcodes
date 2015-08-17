//给定一个二叉树，返回所有root-to-leaf的路径
//基本上所有的二叉树的问题都可以用递归来解决
//深度优先遍历树即可

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
        vector<string> ret;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return ret;
        string s;
        s += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ret.push_back(s);
        }else{
            helper(root->left, s);
            helper(root->right, s);
        }

        return ret;
    }
private:
    void helper(TreeNode * root, string s){
        if(root == NULL) return;
        s += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ret.push_back(s);
        }else{
            helper(root->left, s);
            helper(root->right, s);
        }
    }
};
