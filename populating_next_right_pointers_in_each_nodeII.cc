/**
 * Populating Next Right Pointers in Each Node II
 * Given a binary tree
 *     struct TreeLinkNode {
 *     TreeLinkNode *left;
 *     TreeLinkNode *right;
 *     TreeLinkNode *next;
 *     }
 * 	For example, Given the following binary tree,
 *        1
 *      /  \
 *     2    3
 *    /      \
 *   4     	 7
 * After calling your function, the tree should look like:
 *        1 -> NULL
 *      /  \
 *     2 -> 3 -> NULL
 *    /      \
 *   4------->7 -> NULL
 */

#include <iostream>
#include <queue>

using namespace std;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
/*    //使用递归DFS
    void connect(struct TreeLinkNode *root){
        if(root == NULL)
            return;
        struct TreeLinkNode *cur = root;
        connect_helper(cur);
    }
private:
    void connect_helper(struct TreeLinkNode *node){
        if(node == NULL) return;
        //该节点的next的继承节点，利用next横着找到该层的next
        TreeLinkNode *node_next = node->next;
        TreeLinkNode *next = NULL;
        while(node_next != NULL && next == NULL){
            if(node_next->left != NULL)
                next = node_next->left;
            else
                next = node_next->right;
            node_next = node_next->next; //横向遍历
        }

        if(node->left != NULL){
            if(node->right != NULL){
                node->left->next = node->right; //树内
            }else{
                node->left->next = next;    //树间
            }
        }
        if(node->right != NULL){
            node->right->next = next; //树间
        }
        // 因为找next时，要横着找，所有要先搞定右子树，再搞定左子树
        connect_helper(node->right);
        connect_helper(node->left);
    }
*/
    //使用层序遍历，每次入队列时记录一个数的层数，从0开始
    //这个方法居然比上面的还慢。。。
    void connect(struct TreeLinkNode *root){
        if(root == NULL)
            return;
        queue<pair<TreeLinkNode *, int> > my_queue;
        my_queue.push(make_pair(root, 0));
        int last_level = -1;
        TreeLinkNode *last = root;
        while(!my_queue.empty()){
            TreeLinkNode *cur = my_queue.front().first;
            int level = my_queue.front().second;
            my_queue.pop();

            if(cur != NULL){
                // cout << cur->val<<"|"<<level<<"|"<<last_level<<endl;
                if(level == last_level + 1){ //上一层的最后一个
                    last->next = NULL;
                    last_level += 1;
                }else{
                    last->next = cur;
                }
                my_queue.push(make_pair(cur->left, level+1));
                my_queue.push(make_pair(cur->right, level+1));
                last = cur;
            }
        }
        last->next = NULL;
    }
};
void printer(struct TreeLinkNode *node){
    if(node == NULL)
        return;
    cout<<"node:"<<node->val;
    if(node->left != NULL){
        cout<<"\tleft:"<<node->left->val;
    }else{
        cout<<"\tleft: NULL";
    }
    if(node->right != NULL){
        cout<<"\tright:"<<node->right->val;
    }else{
        cout<<"\tright: NULL";
    }
    if(node->next != NULL){
        cout<<"\tnext:"<<node->next->val<<endl;
    }else{
        cout<<"\tnext: NULL" <<endl;
    }
}
//test
int main(int argc, char const *argv[])
{
	Solution test;
	struct TreeLinkNode n0(0);
	struct TreeLinkNode n1(1);
	struct TreeLinkNode n2(2);
	struct TreeLinkNode n3(3);
	struct TreeLinkNode n4(4);
	struct TreeLinkNode n5(5);
	struct TreeLinkNode n6(6);
	struct TreeLinkNode n7(7);
	n0.left = &n1;
	n0.right = &n2;

	n1.left = &n3;
    n2.left = &n4;
	n2.right = &n5;
    n3.left = &n6;
    n5.right = &n7;
	test.connect(&n0);

    printer(&n0);
    printer(&n1);
    printer(&n2);
    printer(&n3);
    printer(&n4);
    printer(&n5);
    printer(&n6);
    printer(&n7);

	return 0;
}
