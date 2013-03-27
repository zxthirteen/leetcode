/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool comp(ListNode *a, ListNode *b) {
    return a->val > b->val;
}
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<ListNode *> vh;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) vh.push_back(lists[i]);
        }
        
        ListNode *head = NULL;
        ListNode **pre = &head;
        
        make_heap(vh.begin(), vh.end(), comp);
        ListNode *newnode;
        while (!vh.empty()) {
            newnode = vh.front();
            pop_heap(vh.begin(), vh.end(), comp);
            vh.back() = vh.back()->next;
            
            *pre = newnode;
            pre = &((*pre)->next);
            
            if (vh.back() == NULL) {
                vh.pop_back();
            } else {
                push_heap(vh.begin(), vh.end(), comp);
            }
        }
        
        return head;
    }
};
