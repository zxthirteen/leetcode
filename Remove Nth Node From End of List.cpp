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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode *pre = newhead, *end;
        
        end = pre;
        for (int i = 0; i < n; i++) {
            end = end->next;
        }
        
        while (end->next) {
            pre = pre->next;
            end = end->next;
        }
        
        pre->next = pre->next->next;
        return newhead->next;
    }
};
