/**
 * Linked List Cycle:
 * Given a linked list, determine if it has a cycle in it.
 * Follow up:
 * 		Can you solve it without using extra space?
 */
/**
 * 用两个指针，快指针每次走两步，慢指针每次走一步；在快指针为NULL之前，如果慢指针能追上快指针，则说明有环；否则无环。
 */
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};
class Solution {
public:
    bool hasCycle(struct ListNode *head) {
		if(head == NULL) return false;
		struct ListNode *one = head;
		struct ListNode *two = head;
		bool flag = false;

		while(two != NULL){
			one = one->next;
			if(two->next == NULL){
				break;
			}else{
				two = two->next->next;
			}
			if(one == two){
				flag = true;
				break;
			}
		}

		return flag;
    }
};


int main(int argc, char const *argv[])
{
	Solution test;
	struct ListNode n6(6);
	struct ListNode n5(5);
	n5.next = &n6;
	struct ListNode n4(4);
	n4.next = &n5;
	struct ListNode n3(3);
	n3.next = &n4;
	struct ListNode n2(2);
	n2.next = &n3;
	struct ListNode n1(1);
	n1.next = &n2;
	struct ListNode n0(0);
	n0.next = &n1;
	struct ListNode n(0);
	n.next = &n6;

	if(test.hasCycle(&n)){
		cout << "has cycle" << endl;
	}else{
		cout << "has no cycle" << endl;
	}

	return 0;
}
