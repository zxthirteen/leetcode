/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

// 经典做法，设二维数组存终答案，然后dfs向下传引用
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(root, sum, res, path);
        return res;
    }

    void dfs(TreeNode *node, int target, vector<vector<int> > &res, vector<int> path) {
        if (!node) return;
        target = target - node->val;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (target == 0)
                res.push_back(path);
            return;
        }
        dfs(node->left, target, res, path);
        dfs(node->right, target, res, path);
        return;
    }
};
