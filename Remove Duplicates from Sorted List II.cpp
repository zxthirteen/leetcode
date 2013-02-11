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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
