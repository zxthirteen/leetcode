/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool nodecomp(ListNode *a, ListNode *b) {
    if (!a || !b) return true;
    return a->val > b->val;
}
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode*> minheap;
        
        for (auto i = lists.begin(); i != lists.end(); i++) {
            if (*i != NULL) {
                minheap.push_back(*i);
            }
        }
        make_heap(minheap.begin(), minheap.end(), nodecomp);
        
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (!minheap.empty()) {
            tail->next = minheap[0];
            pop_heap(minheap.begin(), minheap.end(), nodecomp);
            if (minheap.back()->next == NULL) {
                minheap.pop_back();
            } else {
                minheap.back() = minheap.back()->next;
                push_heap(minheap.begin(), minheap.end(), nodecomp);
            }
            tail = tail->next;
        }
        return head->next;
    }
};
