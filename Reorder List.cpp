/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // Yeah !!! One shot pass!
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        int n = 0;
        ListNode *p = head;
        while (p != NULL) {
            n++;
            p = p->next;
        }
        p = head;
        for (int i = 0; i < n/2; i++) p = p->next;

        ListNode *q = p->next;
        if (q == NULL) return head;
        p->next = NULL;
        ListNode *r = q->next;
        while (true) {
            q->next = p;
            p = q;
            q = r;
            if (r == NULL) break;
            r = r->next;
        }
        
        ListNode *a = head, *b = p;
        ListNode *tail = new ListNode(0);
        tail->next = head;
        int count = n/2;
        while (count--) {
           ListNode *aa = a->next;
           ListNode *bb = b->next;
           tail->next = a;
           a->next = b;
           tail = b;
           a = aa;
           b = bb;
        }
        
        if (b != NULL) {
            tail->next = b;
            tail = b;
        }
        tail->next = NULL;
        return;
    }
};


int main() {
    Solution s;
    ListNode *head = new ListNode(2);
    ListNode *second = new ListNode(1);
    head->next = second;
    s.reorderList(head);
}
