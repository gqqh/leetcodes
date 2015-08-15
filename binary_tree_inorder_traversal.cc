//二叉树的中序遍历
//递归解法很简单，也比较高效
//非递归解法，也就是迭代解法，是借助栈，使用cur表示当前访问的节点，
//如果该节点不为空，就压入栈，cur指向其左孩子；如果栈不为空或者cur不为空，则继续循环，
//如果cur为空，则pop出来一个节点，访问之，同时把cur指向其右孩子。
//知道cur为空并且栈为空，退出。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 递归解法，速度反而比迭代解法速度要快
     */
    vector<int> ret;
    vector<int> inorderTraversal(struct TreeNode *root){
    	if(root == NULL)
    		return ret;
        in_order(root);
       	return ret;
    }
private:
    void in_order(struct TreeNode *root){
        if(root == NULL) return;
        in_order(root->left);
        ret.push_back(root->val);
        in_order(root->right);
    }
    //非递归解法，迭代解法，需要借助栈，只要当前节点有左孩子，就把该节点压入栈
    //遍历完左孩子，如果栈非空，就pop出来访问，同时指定下一个访问的节点为右孩子。
    vector<int> _inorderTraversal(struct TreeNode *root){
    	if(root == NULL)
    		return ret;
    	struct TreeNode *cur = root;
    	stack<struct TreeNode *> pstk;
    	while(cur != NULL || !pstk.empty()){
    		if(cur != NULL){ 		//走到最左边
    			pstk.push(cur);
    			cur = cur->left;
    		}else{					//访问当前节点
    			cur = pstk.top();
    			pstk.pop();
    			ret.push_back(cur->val);
    			cur = cur->right;
    		}
       	}
       	return ret;
    }
};
