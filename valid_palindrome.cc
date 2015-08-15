/**
 *Palindrome
 * Given a singly linked list, determine if it is a palindrome.
 * Could you do it in O(n) time and O(1) space?
 *比较简单的方法是,把链表逆转一下,然后比较两个链表.(T=O(n), S=O(n))
 *改进点的方法,先统计链表的长度,然后把前面一半(向上取整)原地逆转,如果长度为奇数,
 *    则从第二个元素和中间往后一起同时比较,直到结尾或者出现不匹配的.如果长度为
 *    偶数,则从第一个元素和中间一个元素向后比较.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <iostream>
 using namespace std;
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){}
};
class Solution {
public:
    //首逆转一半,然后挨个向后比较
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
