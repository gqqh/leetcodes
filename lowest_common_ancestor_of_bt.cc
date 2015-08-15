/*
 *https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
/*
 *找一个bst中两个节点的最近公共祖先,要比一个二叉树找公共祖先容易,因为多了一个bst
 *  条件,节点有序,如果两个值都小于根的值,则处理左子树;如果两个值都大于根,则处理
 *   右子树;如果一个小于根植,一个大于根值,则根为最低公共祖先.
 */

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
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root == NULL || p == NULL || q == NULL)
        return NULL;
      if(p == q)
        return p;
      if(p->val < root->val && q->val < root->val) //找左子树
        return lowestCommonAncestor(root->left, p, q);
      else if(p->val > root->val && q->val > root->val) //找右子树
        return lowestCommonAncestor(root->right, p, q);
      else
        return root;
   }
};
