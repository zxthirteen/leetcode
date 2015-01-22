/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
用queue，每行间用null间隔，就可以在pop的时候判断一行是否已经结束
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
    vector<vector<int> > levelOrder(TreeNode *root) {
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
        return res;
    }
};