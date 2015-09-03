//给定一个完全二叉树，统计其节点的个数

//递归遍历
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /*
    //DFS递归，O(n), TLE
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return countNodes(root->left) + countNodes(root->right)+1;
    }
    */
// /*
    //利用满二叉树的特点，如果一个子树是满二叉树，则其节点为2^h-1(h=1,2...).
    //复杂度为O(logn)，递归求解如果某个节点的左孩子等于右孩子那么就可以
    // 算出这个节点的所有子树含有节点数为2^h - 1个，然后如果不是再递归求解
    // 两个子树的节点数目
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l_height = 1, r_height = 1;
        TreeNode *p = root->left;
        while(p != NULL){
            l_height++;
            p = p->left;
        }
        p = root->right;
        while(p != NULL){
            r_height++;
            p = p->right;
        }
        if(l_height == r_height){
            //root为一个高为l_height的满二叉树，节点数为2^h-1
            return (1 << l_height)-1;
        }else{ //递归
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
// */
};
