//找树中两个节点的最近共同祖先
//         3
//       /   \
//      5     1
//     / \   / \
//    6   2  0  8
//       / \
//      7   4
//5和1的祖先是3,5和4的祖先是5

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
#include <string>

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
    string path_p, path_q;
    //采用类似编码的方式，记录从根到目标节点的路径，左为0右为1，然后比较两个路径
    //TLE！！
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(p == NULL) return q;
        if(q == NULL) return p;
        // if(p == q) return p;

        string path;
        traver(root, p, q, path);
        int len_p = path_p.size();
        int len_q = path_q.size();
        TreeNode * anc = root;
        for(int i = 0; i < len_q && i < len_p; i++){
            if(path_p[i] != path_q[i]) break;
            if(path_p[i] == '0')
                anc = anc->left;
            else
                anc = anc->right;
        }
        return anc;
    }
private:
    //计算从根到p和q节点的路径，向左走为0，向右走为1
    void traver(TreeNode *root, TreeNode *p, TreeNode *q, string path){
        if(root == NULL) return;
        if(root == p){
            if(root == q){
                path_q = path;
            }
            path_p = path;
            return;
        }
        if(root == q){
            path_q = path;
            return;
        }
        traver(root->left, p, q, path.append("0"));
        traver(root->left, p, q, path.append("1"));
    }
    */
    //递归解决这个问题，两个节点属于一定分别属于某个节点的左右孩子，
    // 或者某一个属于root，递归检查左右孩子即可。
    // 如果分别在某个节点的左右子树，则返回该节点；
    // 否则，返回含有某个节点的子树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode *L = lowestCommonAncestor(root->left, p, q);
        TreeNode *R = lowestCommonAncestor(root->right, p, q);

        if(L != NULL && R != NULL) return root;
        return L == NULL ? R : L;
    }
};
