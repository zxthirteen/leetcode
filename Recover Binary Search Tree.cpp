/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
中序遍历 找逆序的情况
*/

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
                    else {
                        second = p;
                    }
                }
                prev = p;
                p = p->right;
            }
        }
        
        swap(first->val, second->val);
    }
};
