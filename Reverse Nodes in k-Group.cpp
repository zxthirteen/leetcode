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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k == 1) return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        
        ListNode *start = newhead, *end = NULL;
        ListNode *newstart, *pre, *p, *post;
        
        
        while (1) {
            end = start;
            for (int i = 0; i < k && end; i++) {
                end = end->next;
            }
            if (!end) break;
            newstart = end->next;
            
            pre = start->next;
            p = pre->next;
            post = p->next;
            
            start->next = end;
            pre->next = newstart;
            start = pre;
            while (pre != end) {
                p->next = pre;
                pre = p;
                p = post;
                if (post) post = post->next;
            }
        }
        
        return newhead->next;
    }
};
