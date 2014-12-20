/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode *lastnode = NULL;
        stack<TreeNode *> s;
        
        s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            if (lastnode != NULL) {
                lastnode->left = NULL;
                lastnode->right = p;
            }
            lastnode = p;
            // push right child first
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
    }
};
