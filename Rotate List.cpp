/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0) return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode *tail = newhead, *pre = newhead, *p = head;
        
        int len = 0;
        while (tail->next) {
            len++;
            tail = tail->next;
        }
        
        k = k % len;
        int move = (len - k) % len;
        if (move == 0) return head;
        for (int i = 0; i < move; i++) {
            pre = pre->next;
            p = p->next;
        }
        
        pre->next = NULL;
        tail->next = head;
        
        return p;
    }
};
