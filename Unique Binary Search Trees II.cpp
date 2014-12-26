/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<TreeNode *> generateTrees(int n) {
        return maketree(1, n);
    }
    
    vector<TreeNode *> maketree(int start, int len) {
        vector<TreeNode *> res;
        if (len == 0) {
            res.push_back(NULL);
            return res;
        }
        if (len == 1) {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        vector<TreeNode *> left, right;
        for (int root = start; root <= start + len -1; root++) {
            left.clear();
            right.clear();
            left = maketree(start, root - start);
            right = maketree(root +1, start + len -1 - root);
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode *node = new TreeNode(root);
                    node->left = left[i];
                    node->right = right[j];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
