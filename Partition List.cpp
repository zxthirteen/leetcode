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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *r = newhead;
        
        ListNode *p = r, *n = NULL;
        // consider p->next
        while (p->next) {
            if (p->next->val >= x) p = p->next;
            else {
                // move n after r
                if (p == r) {
                    r = r->next;
                    p = p->next;
                } else {
                
                    n = p->next;
                    p->next = n->next;
                    n->next = r->next;
                    r->next = n;
                    
                    r = r->next;
                }
            }
        }
        
        return newhead->next;
    }
};
