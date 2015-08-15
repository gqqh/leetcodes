//二叉树的先序遍历
//递归解法，简单高效
//非递归解法：也是要借用一个栈，使用一个cur表示当前遍历的节点，
//如果栈不为空或者cur不为空就继续遍历，访问cur，同时把cur的右孩子压入栈，
//同时cur指向左孩子，继续遍历
//直到栈为空且cur为空。


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
    vector<int> preorderTraversal(struct TreeNode *root){
    	if(root == NULL)
    		return ret;
        pre_order(root);
       	return ret;
    }
private:
    void pre_order(struct TreeNode *root){
        if(root == NULL) return;
        ret.push_back(root->val);
        pre_order(root->left);
        pre_order(root->right);
    }
	/**
	 * 非递归解法
	 */
    vector<int> _preorderTraversal(struct TreeNode *root) {
    	if(root == NULL)
    	    return ret;

    	struct TreeNode *cur;
    	stack<struct TreeNode *> pstk;
        cur = root;
    	while(cur != NULL || !pstk.empty()){
    		if(cur == NULL){
                cur = pstk.top();
                pstk.pop();
                continue;
            }else{
                ret.push_back(cur->val);
                pstk.push(cur->right);
                cur = cur->left;
            }
        }

         return ret;
    }
};
