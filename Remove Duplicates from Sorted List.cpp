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
        if (!head) return head;
        
        ListNode *pre = head, *p = pre->next;
        
        while (p) {
            if (p->val == pre->val) {
                pre->next = p->next;
                delete(p);
                p = pre->next;
            } else {
                p = p->next;
                pre = pre->next;
            }
        }
        
        return head;
    }
};
