// Source : https://leetcode.com/problems/rotate-list/
// Author : Peiyang Hong
// Date   : 2015-09-10

/********************************************************************************** 


Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


思路：
1. 遍历链表计算长度
2. 对k取余
2. 找到新的尾节点，然后进行指针变换
**********************************************************************************/


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
        	return NULL;
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        	n ++;
        }
        k = k % n;
        //go to the node n-k
        if (k) {
        	ListNode* newTail = head;
        	for (int i = 1; i < n - k; i ++)
        		newTail = newTail->next;
        	//rotate
        	tail->next = head;
        	head = newTail->next;
        	newTail->next = NULL;
        	return head;
        }
        return head;
    }
};