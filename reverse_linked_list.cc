//原地逆转单链表
// 头插入法遍历列表，每个节点都进行头插入

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur = head, *p;
    head = NULL;
    while(cur != NULL){
        p = cur;
        cur = cur->next;
        p->next = head;
        head = p;
    }
    return head;
}*/
//C++
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *p;
        head = NULL;

        while(cur != NULL){
            p = cur;
            cur = cur->next;
            p->next = head;
            head = p;
        }
        return head;
    }
};
