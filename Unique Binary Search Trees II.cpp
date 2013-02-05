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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
    }
};
