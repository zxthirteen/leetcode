#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        sort(head, NULL);
        return head;
    }


    // It's easy to use qsort to divide the array to two parts, the <t part and >=t part
    // but time exceed, so try to use three parts, <t, =t, and >t parts. Accepted
    void sort(ListNode *head, ListNode* end) {
        if (head == NULL || head -> next == end || head == end) return;
        int t = head->val;
        ListNode *m = head;
        ListNode *n = head;
        ListNode *i = head->next;
        while (i != end) {
            if (i->val < t) {
                m = m->next;
                n = n->next;
                int tmp = i->val;
                i->val = n->val;
                n->val = m->val;
                m->val = tmp;
            } else if (i->val == t) {
                n = n->next;
                swap(n->val, i->val);
            }
            i = i->next;
        }
        swap(head->val, m->val);
        sort(head, m);
        sort(n->next, end);
        return;
    }   
};


int main() {
    Solution s;
    ListNode *head = new ListNode(2);
    ListNode *second = new ListNode(1);
    head->next = second;
    s.sortList(head);
}
