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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
