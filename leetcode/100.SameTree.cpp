/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return trans(p, q);
    }
    
    bool trans(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL)
        {
            return 1;
        }
        else if(p != NULL && q != NULL && p->val == q->val)
        {
            return 1 && trans(p->left, q->left) && trans(p->right, q->right);
        }
        else
        {
            return 0;
        }
    }
    
};