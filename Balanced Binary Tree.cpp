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
    bool getdepth(TreeNode *root, int *d) {
        if (!root) {
            *d = 0;
            return 1;
        }
        int left;
        int right;
        
        bool res = getdepth(root->left, &left) && getdepth(root->right, &right);
        res = res && (abs(left - right)) <= 1;
        *d = max(left, right) +1;
        return res;
        
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int totaldepth;
        return getdepth(root, &totaldepth);
    }
};
