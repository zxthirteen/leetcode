/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = 0, lenB = 0;
        ListNode* p = headA, *q = headB;
        while (p->next) {
            lenA++;
            p = p->next;
        }
        while (q->next) {
            lenB++;
            q = q->next;
        }
        if (p != q) {
            return NULL;
        }
        
        p = headA;
        q = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                p = p->next;
            }
        }
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; i++) {
                q = q->next;
            }
        }
        
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};