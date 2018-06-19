// Given a binary tree, return the preorder traversal of its nodes' values.

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
    using node = TreeNode;
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;
        
        stack<node*> q;
        q.push(root);
        node *p;
        
        while(!q.empty())
        {
            p = q.top();
            res.push_back(p->val);
            q.pop();
            if(p->right) q.push(p->right);
            if(p->left) q.push(p->left);
 
        }
        return res;
    }
};