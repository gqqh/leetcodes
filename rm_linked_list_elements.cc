//删除链表中值为val的所有节点

//从前往后遍历链表，先找一个值不为val的节点，然后依次判断下一个节点，
// 如果为val则删除，直到最后
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head!=NULL && head->val == val){
            head = head->next;
    }
    struct ListNode* cur = head, *p; //head == NULL || head.val != val
    while(cur != NULL){
        p = cur->next;
        while(p != NULL && p->val == val){
            p = p->next;
        }
        cur->next = p;
        cur = cur->next;
    }

    return head;
}
