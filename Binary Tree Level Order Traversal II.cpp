/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> line;
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p == NULL) {
                res.push_back(line);
                line.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                line.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};