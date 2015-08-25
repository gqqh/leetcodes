//给定一个二叉树，找到最大的路径和，路径可以从任意点开始和结束
//    1
//   / \
//  2   3
// Return 6.

//思想，递归求解，使用一个全局变量作为最大值g_max，然后对于每个节点，
// 返回max{node->val+max(max(lmax,rmax),0)}
//同时更新g_max = max{g_max, node->val, lmax, rmax, node->val + lmax,
// node->val + rmax, node->val + rmax + lmax, }

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
#include <vector>
#include <algorithm>
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
    int g_max;
    int maxPathSum(TreeNode* root) {
        g_max = INT_MIN;
        if(root == NULL) return g_max;

        int lmax = get_max(root->left);
        int rmax = get_max(root->right);
        //max{g_max, root->val, lmax, rmax, root->val+lmax,
        // root->val+rmax, root->val+rmax+lmax}
        return max(g_max, max(lmax, 0)+max(rmax, 0)+root->val);
    }
private:
    //返回该子树从根往左和从根往右的和的最大值，同时使用左加右加自己与最大值比较
    int get_max(TreeNode *node){
        if(node == NULL) return INT_MIN;
        int lmax = get_max(node->left);
        int rmax = get_max(node->right);
        //g_max = max{g_max, lmax, rmax, root->val, root->val+lmax,
        // root->val+rmax, root->val+rmax+lmax}
        //使用局部路径更新最大路径
        g_max = g_max < lmax ? lmax : g_max;
        g_max = g_max < rmax ? rmax : g_max;
        g_max = max(max(lmax,0)+max(rmax,0)+node->val, g_max); //左中右回路
        //返回
        return (max(max(lmax, rmax), 0) + node->val);
    }
};
int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
