/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convert(num, 0, num.size()-1);
    }
    
    TreeNode *convert(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int m = (start + end) /2;
        TreeNode *r = new TreeNode(num[m]);
        r->left = convert(num, start, m-1);
        r->right = convert(num, m+1, end);
        return r;
    }
};