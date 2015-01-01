/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return getTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode *getTree(vector<int> &in, vector<int> &post, 
                      int instart, int inend, int poststart, int postend) {
        if (instart > inend) {
            return NULL;
        }
        
        int midval = post[postend];
        int mid;
        for (int i = instart; i <= inend; i++) {
            if (in[i] == midval) {
                mid = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(midval);
        int leftn = mid - instart;
        root->left = getTree(in, post, instart, mid-1, poststart, poststart + leftn -1);
        root->right = getTree(in, post, mid+1, inend, poststart + leftn, postend-1);
        return root;
    }
};