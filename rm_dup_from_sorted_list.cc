//给定一个有序的单链表，删除所有冗余的节点，保证每个值在节点中只有一个
//从前往后依次遍历，如果下一个指针的值跟当前节点值一样就删除，知道最后

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)
			return head;
		ListNode *cur, *post, *del;
		cur = head;
		post = cur->next;
		while(post != NULL){
			if(cur->val == post->val){
				// delete(post);
                del = post;
				post = post->next;
				cur->next = post;
                free(del);
			}else{
				cur = post;
				post = post ->next;
			}
		}

		return head;
    }
};
