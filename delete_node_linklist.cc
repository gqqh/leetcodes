/*
 *Delete Node in a Linked List
 *Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third
 * node with value 3, the linked list should become 1 -> 2 -> 4 after calling
 * your function.
 */
/**
 *只给一个指针进行删除单链表元素,只能进行后一个元素进行拷贝删除,即把后面一个
 *元素的只拷贝覆盖当前元素,然后删除后面一个元素.内存泄露了一个NODE。
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
struct ListNode{
  int val;
  ListNode *next;
};
class Solution {
public:
    void deleteNode(ListNode* node) {
      if(node == NULL)
        return;
      ListNode *next = node->next; //找到被删节点的后一个节点
      if(next == NULL){
        next = node;
        node = NULL; //如果被删节点是最后一个，则delete该节点
        delete(next);
        return;
      }
      //把被删节点的下一个节点拷贝覆盖将被删节点
      node->val = next->val;
      node->next = next->next;
      delete(next);
    }
};
