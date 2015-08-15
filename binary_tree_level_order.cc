//层序遍历二叉树，借助队列，每次访问一个节点就把其两个孩子放到队列的末尾

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
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        queue<pair<TreeNode *, int> > t_q; //队列多一个元素为节点的层数
        pair<TreeNode *, int> tp(root, 0);
        t_q.push(tp);
        vector<int> line;
        int level = 0;

        while(!t_q.empty()){
            tp = t_q.front();
            TreeNode *tmp = tp.first;
            int l = tp.second;
            t_q.pop();
            //访问节点之前要先判断是否需要换行
            if(level + 1 == l){
                level ++;
                ret.push_back(line);
                line.resize(0);
            }
            if(tmp != NULL){
                line.push_back(tmp->val);
                tp.first = tmp->left;
                tp.second = l+1;
                t_q.push(tp);
                tp.first = tmp->right;
                t_q.push(tp);
            }
        }
        if(!line.empty())
            ret.push_back(line);

        return ret;
    }
};
