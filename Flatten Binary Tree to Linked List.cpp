// 树的先序遍历生成链表，用栈，简洁方法
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
            
        }
    }
};
