/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/* 
有两点在写的时候出错了，
1. 一个是hasNext的意思不是指当前结点的下一个结点，而是说当前容器里还有没有值，next()是返回当前该值然后再维护，
2. 另一个是在中序遍历中，stack保存的不是从root到leaf的一条路径，而是一个全左序列，root被访问过之后，当前保存的只是root->right及之后的结点。
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
class BSTIterator {
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *t = s.top();
        int value = t->val;
        s.pop();
        if (t->right) {
            TreeNode *p = t->right;
            while (p) {
                s.push(p);
                p = p->left;
            }
        }
        return value;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */