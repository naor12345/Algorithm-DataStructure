// Given a binary tree, return the postorder traversal of its nodes' values.

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;
        
        node *r = NULL;
        stack<node*> s;
        node *p = root;
        
        while(p != NULL || !s.empty())
        {
            if(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                if(p->right && p->right != r)
                {
                    p = p->right;
                }
                else
                {
                    res.push_back(p->val);
                    r = p;
                    p = NULL;
                    s.pop();
                }
            }
        }
        return res;
    }
};