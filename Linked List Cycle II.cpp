/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/*
s1 = s + n1 * r - k
s2 = s + n2 * r - k

s1 = 2 * s2

(n1-n2) * r = s2 = s + n2 * r - k

(n1 - 2 * n2) * r = s - k
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
    ListNode *detectCycle(ListNode *head) {
        bool loop = false;
        ListNode *p = head, *q = head;
        while (p && q && p->next) {
            p = p->next->next;
            q = q->next;
            if (p == q) {
                loop = true;
                break;
            }
        }
        if (!loop) {
            return NULL;
        }
        
        ListNode *meet = p;
        p = head;
        q = meet;
        
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        
        return p;
    }
};