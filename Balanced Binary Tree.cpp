/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
        int totaldepth;
        return getdepth(root, &totaldepth);
    }
};
