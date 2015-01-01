/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return getTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode *getTree(vector<int> &pre, vector<int> &in, 
                      int prestart, int preend, int instart, int inend) {
        if (instart > inend) {
            return NULL;
        }
        
        int midval = pre[prestart];
        int mid;
        for (int i = instart; i <= inend; i++) {
            if (in[i] == midval) {
                mid = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(midval);
        int leftn = mid - instart;
        root->left = getTree(pre, in, prestart +1, prestart + leftn, instart, instart + leftn -1);
        root->right = getTree(pre, in, prestart + leftn +1, preend, instart + leftn +1, inend);
        return root;
    }
};