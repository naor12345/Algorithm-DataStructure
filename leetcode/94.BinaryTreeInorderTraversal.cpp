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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        push_left(root, s);
        TreeNode *t;
        while(!s.empty())
        {
            t = s.top();
            s.pop();
            res.push_back(t->val);
            push_left(t->right, s);
        }
        return res;
    }

    void push_left(TreeNode *left, stack<TreeNode*> &s)
    {
        TreeNode *tmp = left;
        while(tmp != NULL)
        {
            s.push(tmp);
            tmp = tmp->left;
        }
    }
};