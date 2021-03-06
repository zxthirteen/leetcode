/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

// 关键思路，在广度优先遍历中每一深度的结点之后自动插入一个NULL，方法很通用
/* Same as II */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(1) {
            TreeLinkNode *p = q.front();
            q.pop();
            if (p) {
                p->next = q.front();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            } else {
                if (q.empty()) break;
                else q.push(NULL);
            }
        }
    }
};
