/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *start = head, *end = NULL;
        ListNode *prev = NULL, *post = NULL, *postpost = NULL;
        for (int i = 1; i < m; i++) {
            prev = start;
            start = start->next;
        }
        
        end = start;
        post = end->next;
        for (int i = 0; i < n - m; i++) {
            postpost = post->next;
            post->next = end;
            end = post;
            post = postpost;
        }
        
        if (prev) 
            prev->next = end;
        else
            head = end;
        start->next = post;
        
        return head;
    }
};
