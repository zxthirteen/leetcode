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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k <= 1) return head;
        ListNode *start = head, *prestart = NULL;
        
        ListNode *p, *post, *pre, *end;
        while (true) {
            int i = 0;
            end = start;
            while (end && i++ < k-1) {
                end = end->next;
            }
            if (!end) break;
            
            // reverse sub list from [start to end]
            
            pre = end->next;
            p = start;
            i = k;
            // My significate error happen here:
            // while (p != end->next)
            // Reason: end->next is changing!
            while (i--) {
                post = p->next;
                p->next = pre;
                pre = p;
                p = post;
            }
            if (prestart) {
                prestart->next = pre;
            } else {
                head = end;
            }
            prestart = start;
            start = start->next;
        }
        return head;
    }
};