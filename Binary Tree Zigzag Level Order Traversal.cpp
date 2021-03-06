/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        
        bool reverseline = false;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> line;
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p == NULL) {
                if (reverseline) {
                    line.reverse(line.begin(), line.end());
                    reverseline = false;
                } else {
                    reverseline = true;
                }
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
        return res;
    }
};