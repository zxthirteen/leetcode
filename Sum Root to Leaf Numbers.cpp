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
    int res;
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res = 0;
        if (!root) return res;
        getsum(root, 0);
        return res;
    }
    
    void getsum(TreeNode *p, int num) {
        num *= 10;
        num += p->val;
        if (!p->left && !p->right) {
            res += num;
            return;
        } else {
            if (p->left) getsum(p->left, num);
            if (p->right) getsum(p->right, num);
        }
    }
};
