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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) return head;
        
        ListNode **x = &head;
        ListNode *p = head;
        
        while (true) {
            if (!p || !(p->next)) {
                break;
            }
            ListNode *q = p->next;
            ListNode *rest = q->next;
            *x = q;
            q->next = p;
            p->next = rest;
            
            x = &(p->next);
            p = rest;
        }
        
        return head;
    }
};
