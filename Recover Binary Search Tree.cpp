/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        
        stack<TreeNode *> s;
        TreeNode *head = new TreeNode(INT_MIN);
        TreeNode *p = root;
        TreeNode *prev = head;
        TreeNode *first = NULL, *second = NULL;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                if (prev->val > p->val) {
                    // tricky part: the code may come to here ONCE or TWICE:
                    // ONCE: 1 2 4 3 5 6; TWICE: 1 5 3 4 2 6
                    if (first == NULL) {
                        first = prev;
                        second = p;
                    }
                    else 
                        second = p;
                }
                prev = p;
                p = p->right;
            }
        }
        
        swap(first->val, second->val);
    }
};
