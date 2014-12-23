/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

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
        ListNode *newhead = new ListNode(0);
        ListNode *pre = newhead, *p = head;
        newhead->next = head;
        
        while (p) {
            while (p->next && p->val == p->next->val)
                p = p->next;
            
            if (p == pre->next) {   // no duplicates
                pre = pre->next;
                p = p->next;
            } else {                // duplicates
                pre->next = p->next;
                p = pre->next;
            }
        }
        
        return newhead->next;
    }
};
