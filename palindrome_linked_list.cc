//给定一个单链表，判断它是否是回文链表
//把前面一半逆序一下然后依次往后比较，复杂度为1.5N

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
    //首逆转一半,然后同时比较到最后
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
          return true;
        int len = 0;
        ListNode *p = head;
        while(p != NULL){
          len++;
          p = p->next;
        }
        
        int half = (len + 1) / 2;
        ListNode *tail = head, *tmp = head;
        p = head->next;
        while(--half > 0){
          tmp = p;
          p = p->next;
          tmp->next = head;
          head = tmp;
        }
        tail->next = p;
        if(len % 2 == 1)
          tmp = tmp->next;
        while(p != NULL){
          if(p->val != tmp->val)
            return false;
          p = p->next;
          tmp = tmp->next;
        }
        return true;
    }
};
