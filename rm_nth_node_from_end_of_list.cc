//删除一个链表的倒数第n个节点，返回头节点。
//使用两个指针

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n < 1) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        //只有一个节点
        if(q == NULL && n == 1){
            head = NULL;
            free(p);
            return head;
        }
        //只有两个节点时，单独讨论
        if(q->next == NULL){
            if(n == 1){
                head->next = NULL;
                free(q);
            }else if(n == 2){
                head = q;
                free(p);
            }
            return head;
        }
        //q指向最后一个节点
        while(--n > 0 && q->next != NULL) q = q->next;
        if(n > 0 && q->next == NULL){
            //找到了最后节点，还没找到要删的点，p->next就是要删的节点
            if(n == 1){ //删除头节点
                head = head->next;
                free(p);
                return head;
            }else{ //n大于长度了
                return head;
            }
        }else if(n == 0){ //n == 0
            while(q->next != NULL){
                q = q->next;
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            free(q);
            return head;
        }

        return head;
    }
};
