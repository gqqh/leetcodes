#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};
//分别从头开始遍历两个链表，将其中的元素相加，如果大于9，则进位为1，值对10取模。
//如果某个链表到结尾了，则另外一个链表的后面每一位与进位相加。
//如果两个都到达结尾，进位仍然不为0，则添加一个进位位的链表节点。
class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode *ret = (ListNode *)malloc(sizeof(ListNode));
		ListNode *cur = ret;
		int carry = 0;
		while(l1 != NULL && l2 != NULL){
			int val = l1->val + l2->val + carry;
			ListNode *node = (ListNode *)malloc(sizeof(ListNode));
			node->val = val % 10;
			node->next = NULL;
			carry = val / 10;
			cur->next = node;
			cur = node;

			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1 != NULL){
			ListNode *node = (ListNode *)malloc(sizeof(ListNode));
			int val = l1->val + carry;
			node->val = val % 10;
			node->next = NULL;
			carry = val / 10;
			cur->next = node;
			cur = node;

			l1 = l1->next;
		}
		while(l2 != NULL){
			ListNode *node = (ListNode *)malloc(sizeof(ListNode));
			int val = l2->val + carry;
			node->val = val % 10;
			node->next = NULL;
			carry = val / 10;
			cur->next = node;
			cur = node;

			l2 = l2->next;
		}
		if(carry){
			ListNode *node = (ListNode *)malloc(sizeof(ListNode));
			node->val = carry;
			node->next = NULL;
			cur->next = node;
		}

		return ret->next;
	}
};
int main()
{
	Solution test;
	ListNode l1[3];
	ListNode l2[4];
	l1[0].val = 2;
	l1[0].next = &l1[1];
	l1[1].val = 4;
	l1[1].next = &l1[2];
	l1[2].val = 3;
	l1[2].next = NULL;
	l2[0].val = 5;
	l2[0].next = &l2[1];
	l2[1].val = 6;
	l2[1].next = &l2[2];
	l2[2].val = 4;
	l2[2].next = &l2[3];
	l2[3].val = 1;
	l2[3].next = NULL;

	struct ListNode *ret = test.addTwoNumbers(&l1[0], &l2[0]);
	for(ListNode *t = ret; t != NULL; t=t->next)
		cout<<t->val<<endl;
	return 0;
}
