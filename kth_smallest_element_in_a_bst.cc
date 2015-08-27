//给一个bst，求其中第k小的元素，假设k总是有效 1<= k <=BST's total elements

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//在BST中，一个节点的左子树所有值都小于等于该节点值，右子树所有值都大于等于
// 该节点值，所以可以进行中序遍历，从最小值开始遍历
// 在递归版本中的传参数要注意，不能通过返回值，因为递归中的返回值会不断地被覆盖

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    //递归版本
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k < 1) return -1;
        int ret = 0;
        inorder(root, k, ret);

        return ret;
    }
private:
    //递归返回值可以通过参数，也可以通过类的成员变量传
    void inorder(TreeNode *node, int &k, int &ret){
        if(node == NULL || k < 1)
            return;
        inorder(node->left, k, ret);
        k--;
        if(k == 0){
            ret = node->val;
            return;
        }
        inorder(node->right, k, ret);
    }
    /*
    //迭代版本，先序遍历，居然MLE内存超限。。。。压栈时还考虑了没压空节点呢
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k < 1) return -1;
        stack<TreeNode *> my_stack;
        TreeNode *cur = root;
        while(cur != NULL || !my_stack.empty()){
            if(cur != NULL){
                if(cur->left != NULL)
                    my_stack.push(cur->left);
                else{
                    k--;
                    if(k == 0) break;
                    cur = cur->right;
                }
            }else{
                cur = my_stack.top();
                my_stack.pop();
            }
        }
        if(cur != NULL)
            return cur->val;
        return -1;
    }*/
};
